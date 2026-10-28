use rstest::rstest;

#[rstest]
#[case(0, 2, false)]
#[case(1, 2, false)]
#[case(2, 2, true)]
#[case(3, 2, true)]
#[case(4, 2, false)]
#[case(5, 2, true)]
#[case(9, 2, false)]
#[case(13, 2, true)]
#[case(21, 2, false)]
#[case(97, 2, true)]
#[case(97, 3, true)]
#[case(341, 2, false)]
#[case(561, 2, false)]
#[case(2047, 2, true)]
#[case(2047, 3, false)]
fn should_evaluate_known_values(#[case] n: u128, #[case] a: u128, #[case] expected: bool) {
    assert_eq!(miller_rabin(n, a), expected);
}

#[rstest]
#[case((1u128 << 127) - 1, 2, true)]
#[case(u128::MAX, 2, false)]
fn should_handle_large_numbers(#[case] n: u128, #[case] a: u128, #[case] expected: bool) {
    assert_eq!(miller_rabin(n, a), expected);
}

#[test]
fn should_avoid_intermediate_overflow() {
    let modulus = u128::MAX;

    assert_eq!(mul_mod(modulus - 1, modulus - 1, modulus), 1);

    assert_eq!(mod_exp(modulus - 1, 2, modulus), 1);
}

#[test]
#[should_panic(expected = "invalid Miller-Rabin base")]
fn should_reject_base_below_range() {
    miller_rabin(13, 1);
}

#[test]
#[should_panic(expected = "invalid Miller-Rabin base")]
fn should_reject_base_above_range() {
    miller_rabin(13, 12);
}

// Independent primality reference for small integers.
fn is_prime_reference(n: u128) -> bool {
    if n < 2 {
        return false;
    }

    let mut divisor = 2;

    while divisor <= n / divisor {
        if n % divisor == 0 {
            return false;
        }

        divisor += 1;
    }

    true
}

#[test]
fn should_accept_every_base_for_small_primes() {
    for n in 5u128..=200 {
        if !is_prime_reference(n) {
            continue;
        }

        for a in 2..=n - 2 {
            assert!(miller_rabin(n, a), "Prime {n} rejected with base {a}");
        }
    }
}

#[test]
fn should_find_witness_for_small_odd_composites() {
    for n in (5u128..=200).step_by(2) {
        if is_prime_reference(n) {
            continue;
        }

        let found_witness = (2..=n - 2).any(|a| !miller_rabin(n, a));

        assert!(found_witness, "No composite witness found for n={n}");
    }
}
