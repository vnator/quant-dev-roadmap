pub fn binary_exp(mut base: i64, mut exp: i64) -> i64 {
    let mut result: i64 = 1;
    let is_positive = exp > 0;

    while exp > 0 {
        if exp % 2 != 0 {
            result *= base;
        }

        base *= base;
        exp /= 2;
    }

    if isPositive {
        result
    } else {
        1 / result
    }
}
