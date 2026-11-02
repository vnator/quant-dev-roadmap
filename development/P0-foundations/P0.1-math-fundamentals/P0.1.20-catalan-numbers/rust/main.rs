fn gcd(mut a: u128, mut b: u128) -> u128 {
    while b != 0 {
        let r = a % b;
        a = b;
        b = r;
    }

    a
}

pub fn catalan_number(n: u64) -> u128 {
    let mut result = 1u128;

    for i in 0..n {
        let i = u128::from(i);

        // C(n+1) = C(n) * 2(2n+1) / n+2
        let mut numerator = 2 * (2 * i + 1);
        let mut denominator = i + 2;

        // Simplify numarator and denominator
        let divisor = gcd(numerator, denominator);

        numerator /= divisor;
        denominator /= divisor;

        assert_eq!(result % denominator, 0, "Invalid Catalan recurrence");

        result /= denominator;

        result = result
            .checked_mul(numerator)
            .expect("Catalan number exceeds u128");
    }

    result
}
