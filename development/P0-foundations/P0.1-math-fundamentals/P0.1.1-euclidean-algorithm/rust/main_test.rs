#[test]
fn should_return_greatest_common_divisor() {
    let result = gcd(252, 105);

    assert_eq!(result, 21);
}

#[test]
fn should_return_zero() {
    let result = gcd(0, 0);

    assert_eq!(result, 0);
}

#[test]
fn should_return_same_value_that_the_entries() {
    let result = gcd(2, 2);

    assert_eq!(result, 2);
}

#[test]
fn should_return_the_greatest_common_divisor_positive_number() {
    let result_a = gcd(-252, 105);
    let result_b = gcd(252, -105);

    assert_eq!(result_a, 21);
    assert_eq!(result_b, 21);
}
