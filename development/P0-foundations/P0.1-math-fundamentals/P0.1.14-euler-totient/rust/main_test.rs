use rstest::rstest;

#[rstest]
#[case(2, 1)]
#[case(7, 6)]
#[case(9, 6)]
#[case(12, 4)]
#[case(30, 8)]
#[case(36, 12)]
#[case(49, 42)]
#[case(60, 16)]
#[case(97, 96)]
#[case(360, 96)]
#[case(999_983, 999_982)]
#[case(600_851_475_143, 591_194_251_200)]
fn should_compute_known_values(#[case] n: u128, #[case] expected: u128) {
    assert_eq!(euler_phi(n), expected);
}

#[rstest]
#[case(0, 0)]
#[case(1, 1)]
#[case(1u128 << 127, 1u128 << 126)]
#[case(3u128 << 100, 1u128 << 100)]
fn should_handle_boundary_cases(#[case] n: u128, #[case] expected: u128) {
    assert_eq!(euler_phi(n), expected);
}

// Independent implementation used as a test oracle.
fn gcd_reference(mut a: u128, mut b: u128) -> u128 {
    while b != 0 {
        let remainder = a % b;
        a = b;
        b = remainder;
    }

    a
}

#[test]
fn should_match_defining_relation() {
    for n in 1u128..=300 {
        let mut expected = 0;

        for k in 1..=n {
            if gcd_reference(k, n) == 1 {
                expected += 1;
            }
        }

        assert_eq!(
            euler_phi(n),
            expected,
            "Euler totient definition failed for n={n}"
        );
    }
}

#[test]
fn should_preserve_multiplicativity() {
    assert_eq!(euler_phi(5 * 8), euler_phi(5) * euler_phi(8));

    assert_eq!(euler_phi(9 * 10), euler_phi(9) * euler_phi(10));

    assert_eq!(euler_phi(16 * 15), euler_phi(16) * euler_phi(15));
}
