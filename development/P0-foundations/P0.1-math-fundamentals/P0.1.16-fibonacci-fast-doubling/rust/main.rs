pub fn fibonacci_fast_doubling(n: u128) -> (u128, u128) {
    assert!(n <= 185, "F(n+1) exceeds u128");

    if n == 0 {
        return (0, 1);
    }

    let (a, b) = fibonacci_fast_doubling(n / 2);

    let c = a * (2 * b - a);
    let d = a * a + b * b;

    if n.is_multiple_of(2) {
        (c, d)
    } else {
        (d, c + d)
    }
}
