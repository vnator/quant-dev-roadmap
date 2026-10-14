pub fn gcd(mut a: i32, mut b: i32) -> u32 {
    let mut a = a.unsigned_abs();
    let mut b = b.unsigned_abs();

    if a == b {
        return a;
    }

    while b != 0 {
        let r = a % b;
        a = b;
        b = r;
    }

    a
}
