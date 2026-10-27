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

    if a == 0 || b == 0 {
        return 0;
    }

    if a == b {
        return a;
    }

    let divisor = gcd(a, b);
    let reduced_a = a / divisor;

    reduced_a.checked_mul(b).expect("LCM exceeds u64")
}
