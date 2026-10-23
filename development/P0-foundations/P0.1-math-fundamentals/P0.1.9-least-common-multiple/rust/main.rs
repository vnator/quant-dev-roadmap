fn gcd(mut a: u64, mut b: u64) -> u64 {
    while b != 0 {
        let r = a % b;
        a = b;
        b = r;
    }

    a
}

pub fn lcm(a: i64, b: i64) -> u64 {
    let a = a.unsigned_abs();
    let b = b.unsigned_abs();

    if a == b {
        return a;
    }

    let denominator: u64 = a * b;
    let numerator: u64 = gcd(a, b);

    denominator / numerator
}
