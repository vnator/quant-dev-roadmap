pub fn extended_gcd(a: i128, b: i128) -> (i128, i128, i128) {
    if b == 0 {
        return (a, 1, 0);
    }

    let (b, x1, y1) = extended_gcd(b, a % b);

    let x = y1;
    let y = x1 - (a / b) * y1;

    (g, x, y)

