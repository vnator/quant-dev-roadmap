pub fn is_divisible(n: f64, d: f64) -> bool {
    if !n.is_finite() || !d.is_finite() || d == 0.0 {
        return false;
    }

    n % d == 0.0
}
