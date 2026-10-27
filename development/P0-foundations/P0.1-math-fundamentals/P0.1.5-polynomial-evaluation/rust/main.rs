pub fn eval_polynomial(coeficients: &[i64], x: i64) -> i64 {
    let mut result: i64 = 0i64;

    for &c in coeficients.iter().rev() {
        result = result
            .checked_mul(x)
            .and_then(|v| v.checked_add(c))
            .expect("overflow");
    }

    result
}
