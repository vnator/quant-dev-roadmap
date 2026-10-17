pub fn factorial_binomial(n: u64, mut k: u64) -> u128 {
    if k > n {
        return 0;
    }

    if k > (n - k) {
        k = n - k;
    }

    let mut result: u128 = 1u128;

    for i in 1..=k {
        result = (result * u128::from(n - i + 1)) / u128::from(i);
    }
    result
}
