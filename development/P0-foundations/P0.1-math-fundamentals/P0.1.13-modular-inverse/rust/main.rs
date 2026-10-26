fn extended_gcd(a: i64, b: i64) -> (i64, i64, i64) {
    if b == 0 {
        return (a, 1, 0);
    }

    let (g, x1, y1) = extended_gcd(b, a % b);

    let x = y1;
    let y = x1 - (a / b) * y1;

    (g, x, y)
}

pub fn inverse_mod(a: i64, m: i64) -> i64 {
    if m <= 1 {
        return 0;
    }

    let mut normalized_a = a % m;

    if normalized_a < 0 {
        normalized_a += m;
    }

    let (g, x, _) = extended_gcd(normalized_a, m);

    if g != 1 {
        return 0;
    }

    let mut inverse = x % m;

    if inverse < 0 {
        inverse += m;
    }

    inverse
}
