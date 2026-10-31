fn gcd(mut a: u64, mut b: u64) -> u64 {
    while b != 0 {
        let remainder = a % b;
        a = b;
        b = remainder;
    }

    a
}

pub fn factorial_binomial(n: u64, mut k: u64) -> u128 {
    if k > n {
        return 0;
    }

    // C(n, k) = C(n, n-k).
    k = k.min(n - k);

    let mut result = 1u128;

    for i in 1..=k {
        let mut numerator = n - i + 1;
        let mut denominator = i;

        // Simplify the fraction before multiplying.
        let divisor = gcd(numerator, denominator);

        numerator /= divisor;
        denominator /= divisor;

        let denominator = u128::from(denominator);

        assert_eq!(
            result % denominator,
            0,
            "Binomial recurrence division must be exact"
        );

        result /= denominator;

        result = result
            .checked_mul(u128::from(numerator))
            .expect("Binomial coefficient exceeds u128");
    }

    result
}

pub fn permutations_with_repetition(n: u64, mults: &[u64]) -> u128 {
    let mut result = 1u128;
    let mut remaining = n;

    for &quantity in mults {
        assert!(quantity <= remaining, "Invalid multiplicities");

        let combinations = factorial_binomial(remaining, quantity);

        result = result
            .checked_mul(combinations)
            .expect("Permutation count exceeds u128");

        remaining -= quantity;
    }

    assert_eq!(remaining, 0, "Multiplicities must sum to n");

    result
}
