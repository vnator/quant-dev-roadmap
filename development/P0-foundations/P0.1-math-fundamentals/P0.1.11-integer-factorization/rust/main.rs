pub fn prime_factors(mut n: i64) -> Vec<i64> {
    let mut factors = Vec::new();

    if n < 2 {
        return factors;
    }

    let mut d: i64 = 2;

    while d <= n / d {
        while n % d == 0 {
            factors.push(d);
            n /= d;
        }

        if d == 2 {
            d = 3;
        } else {
            d += 2;
        }
    }

    if n > 1 {
        factors.push(n);
    }

    factors
}
