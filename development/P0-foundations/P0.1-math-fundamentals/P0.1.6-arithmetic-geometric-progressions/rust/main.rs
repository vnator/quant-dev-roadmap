fn binary_pow(mut base: f64, mut exp: u64) -> f64 {
    let mut result = 1.0;

    while exp > 0 {
        if !exp.is_multiple_of(2) {
            result *= base;
        }

        base *= base;
        exp /= 2;
    }

    result
}

pub fn summ_pa(n: u64, a: f64, d: f64) -> f64 {
    if n == 0 {
        return 0.0;
    }

    let n = n as f64;

    n * (2.0 * a + (n - 1.0) * d) / 2.0
}

pub fn summ_pg(n: u64, a: f64, r: f64) -> f64 {
    if n == 0 {
        return 0.0;
    }

    if r == 1.0 {
        return a * (n as f64);
    }

    (a * (1.0 - binary_pow(r, n))) / (1.0 - r)
}
