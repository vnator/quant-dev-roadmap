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

    if k > n - k {
        k = n - k;
    }

    let mut result = 1u128;

    for i in 1..=k {
        let mut numerator = n - i + 1;
        let mut denominator = i;

        let divisor = gcd(numerator, denominator);

        numerator /= divisor;
        denominator /= divisor;

        let denominator = u128::from(denominator);

        assert_eq!(result % denominator, 0);

        result /= denominator;

        result = result
            .checked_mul(u128::from(numerator))
            .expect("Binomial coefficient exceeds u128");
    }

    result
}
