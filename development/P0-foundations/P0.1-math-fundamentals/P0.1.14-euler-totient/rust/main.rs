pub fn euler_phi(n: u128) -> u128 {
    if n == 0 {
        return 0;
    }

    let mut result = n;
    let mut rest = n;
    let mut divisor = 2u128;

    while divisor <= rest / divisor {
        if rest.is_multiple_of(divisor) {
            result -= result / divisor;

            while rest.is_multiple_of(divisor) {
                rest /= divisor;
            }
        }

        divisor += 1;
    }

    if rest > 1 {
        result -= (result / rest);
    }

    result
}
