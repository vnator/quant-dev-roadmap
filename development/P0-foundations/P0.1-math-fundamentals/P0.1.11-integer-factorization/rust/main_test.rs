use rstest::rstest;

#[rstest]
#[case(i64::MIN, vec![])]
#[case(-12, vec![])]
#[case(-1, vec![])]
#[case(0, vec![])]
#[case(1, vec![])]
#[case(2, vec![2])]
#[case(3, vec![3])]
#[case(4, vec![2, 2])]
#[case(6, vec![2, 3])]
#[case(8, vec![2, 2, 2])]
#[case(9, vec![3, 3])]
#[case(12, vec![2, 2, 3])]
#[case(27, vec![3, 3, 3])]
#[case(49, vec![7, 7])]
#[case(72, vec![2, 2, 2, 3, 3])]
#[case(97, vec![97])]
#[case(121, vec![11, 11])]
#[case(360, vec![2, 2, 2, 3, 3, 5])]
#[case(999_983, vec![999_983])]
#[case(999_966_000_289, vec![999_983, 999_983])]
#[case(600_851_475_143, vec![71, 839, 1471, 6857])]
#[case(i64::MAX, vec![7, 7, 73, 127, 337, 92737, 649657])]
fn should_factorize_known_values(#[case] n: i64, #[case] expected: Vec<i64>) {
    assert_eq!(prime_factors(n), expected);
}

#[test]
fn should_handle_maximum_factor_count() {
    let n: i64 = 1_i64 << 62;

    let factors = prime_factors(n);

    assert_eq!(factors, vec![2; 62]);
}

// Independent reference for checking primality.
fn is_prime_by_division(n: i64) -> bool {
    if n < 2 {
        return false;
    }

    let mut d = 2;

    while d <= n / d {
        if n % d == 0 {
            return false;
        }

        d += 1;
    }

    true
}

#[test]
fn should_preserve_prime_factor_properties() {
    for n in 2..=10_000 {
        let factors = prime_factors(n);

        assert!(!factors.is_empty());

        // Every returned factor must be prime.
        for &factor in &factors {
            assert!(is_prime_by_division(factor), "{factor} is not prime");
        }

        // Factors must be in ascending order.
        for pair in factors.windows(2) {
            assert!(pair[0] <= pair[1]);
        }

        // Multiplying the factors must recover n.
        let product: i64 = factors.iter().product();

        assert_eq!(product, n);
    }
}
