use rstest::rstest;

#[rstest]
#[case(-10, vec![])]
#[case(-1, vec![])]
#[case(0, vec![])]
#[case(1, vec![])]
#[case(2, vec![2])]
#[case(3, vec![2, 3])]
#[case(4, vec![2, 3])]
#[case(9, vec![2, 3, 5, 7])]
#[case(10, vec![2, 3, 5, 7])]
#[case(25, vec![2, 3, 5, 7, 11, 13, 17, 19, 23])]
#[case(30, vec![2, 3, 5, 7, 11, 13, 17, 19, 23, 29])]
fn should_generate_prime_numbers(#[case] limit: i64, #[case] expected: Vec<i64>) {
    assert_eq!(sieve(limit), expected);
}

#[rstest]
#[case(100, 25, 97)]
#[case(1_000, 168, 997)]
#[case(10_000, 1_229, 9_973)]
#[case(100_000, 9_592, 99_991)]
fn should_compute_prime_counting_function(
    #[case] limit: i64,
    #[case] expected_count: usize,
    #[case] expected_last: i64,
) {
    let primes = sieve(limit);

    assert_eq!(primes.len(), expected_count);
    assert_eq!(primes.last().copied(), Some(expected_last));

    for pair in primes.windows(2) {
        assert!(pair[0] < pair[1]);
    }
}

// Independent reference for checking the sieve.
fn is_prime_by_division(n: i64) -> bool {
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
fn should_match_independent_primality_check() {
    let primes = sieve(1_000);

    for n in 0..=1_000 {
        let found = primes.binary_search(&n).is_ok();

        assert_eq!(
            found,
            is_prime_by_division(n),
            "Incorrect primality for {n}"
        );
    }
}
