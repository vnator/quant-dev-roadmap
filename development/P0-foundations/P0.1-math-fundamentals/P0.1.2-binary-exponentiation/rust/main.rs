pub fn binary_exp(mut base: i64, mut exp: i64) -> i64 {
    let mut result: i64 = 1;

    while exp > 0 {
        if exp % 2 != 0 {
            result *= base;
        }

        base *= base;
        exp /= 2;
    }

    if exp > 0 {
        result
    } else {
        1 / result
    }
}
