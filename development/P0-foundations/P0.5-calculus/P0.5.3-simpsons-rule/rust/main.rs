fn non_finite(n: f64) -> bool {
    !n.is_finite()
}

pub fn simpsons_rule<F>(f: F, a: f64, b: f64, n: usize) -> f64
where
    F: Fn(f64) -> f64,
{
    if n < 2 || !n.is_multiple_of(2) || non_finite(a) || non_finite(b) {
        return f64::NAN;
    }

    let h = (b - a) / n as f64;

    if non_finite(h) {
        return f64::NAN;
    }

    let fa = f(a);
    let fb = f(b);

    if non_finite(fa) || non_finite(fb) {
        return f64::NAN;
    }

    if a == b {
        return 0.0;
    }

    let mut sum = fa + fb;

    for i in 1..n {
        let x = a + (i as f64) * h;

        if non_finite(x) {
            return f64::NAN;
        }

        let y = f(x);

        if non_finite(y) {
            return f64::NAN;
        }

        let weight = if i.is_multiple_of(2) { 2.0 } else { 4.0 };

        sum += weight * y;
    }

    let result = (h / 3.0) * sum;

    if non_finite(result) {
        f64::NAN
    } else {
        result
    }
}
