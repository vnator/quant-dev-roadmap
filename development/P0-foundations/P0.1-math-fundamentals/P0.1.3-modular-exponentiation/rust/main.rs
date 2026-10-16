pub fn mod_exp(mut base: i64, mut exp: i64, modulus: i64) -> i64 {
    let mut result: i64 = 1;
    base %= modulus;

    while exp > 0 {
        if exp % 2 != 0 {
            result = (result * base) % modulus;
        }

        exp /= 2;
        base = (base * base) % modulus;
    }

    result
}
