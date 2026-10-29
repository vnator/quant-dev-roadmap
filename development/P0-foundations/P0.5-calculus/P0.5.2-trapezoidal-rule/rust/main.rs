fn infinite(n: f64) -> bool {
    !n.is_finite()
}

pub fn trapezoidal_rule<F>(f: F, a: f64, b: f64, n: usize) -> f64
where
    F: Fn(f64) -> f64,
{
    if n == 0 || infinite(a) || infinite(b) {
        return f64::NAN;
    }

    let h = (b - a) / n as f64;

    if infinite(h) {
        return f64::NAN;
    }

    let fa = f(a);
    let fb = f(b);

    if infinite(fa) || infinite(fb) {
        return f64::NAN;
    }

    let mut sum = (fa + fb) / 2.0;

    for i in 1..n {
        let x = a + (i as f64) * h;
        let y = f(x);

        if infinite(x) || infinite(y) {
            return f64::NAN;
        }

        sum += y;
    }

    let result = h * sum;

    if infinite(result) {
        f64::NAN
    } else {
        result
    }
}
