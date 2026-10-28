fn add_mod(a: u128, b: u128, m: u128) -> u128 {
    if a >= m - b {
        a - (m - b)
    } else {
        a + b
    }
}

fn mul_mod(mut a: u128, mut b: u128, m: u128) -> u128 {
    let mut result = 0u128;
    a %= m;

    while b > 0 {
        if !b.is_multiple_of(2) {
            result = add_mod(result, a, m);
        }

        b /= 2;

        if b > 0 {
            a = add_mod(a, a, m);
        }
    }

    result
}

fn mod_exp(base: u128, mut exp: u128, m: u128) -> u128 {
    let mut result = 1u128;
    let mut b = base % m;

    while exp > 0 {
        if !exp.is_multiple_of(2) {
            result = mul_mod(result, b, m);
        }

        exp /= 2;

        if exp > 0 {
            b = mul_mod(b, b, m);
        }
    }

    result
}

pub fn miller_rabin(n: u128, a: u128) -> bool {
    if n == 2 || n == 3 {
        return true;
    }

    if n < 2 || n.is_multiple_of(2) {
        return false;
    }

    assert!(a >= 2 && a <= n - 2, "invalid Miller-Rabin base");

    let mut d = n - 1;
    let mut s = 0u32;

    while d.is_multiple_of(2) {
        d /= 2;
        s += 1;
    }

    let mut x = mod_exp(a, d, n);

    if x == 1 || x == n - 1 {
        return true;
    }

    for _ in 1..s {
        x = mul_mod(x, x, n);

        if x == n - 1 {
            return true;
        }
    }

    false
}
