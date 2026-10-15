#[test]
fn should_return_1_with_0_pow() {
    assert_eq!(binary_exp(2, 0), 1);

    assert_eq!(binary_exp(0, 0), 1);
}

#[test]
fn should_be_default_behavior() {
    assert_eq!(binary_exp(2, 2), 4);
}

#[test]
fn should_return_a_negative_number() {
    assert_eq!(binary_exp(-2, 3), -8);
}

#[test]
fn should_return_a_positive_number_with_negative_base() {
    assert_eq!(binary_exp(-2, 4), 16);
}

#[test]
fn should_return_something_great() {
    assert_eq!(binary_exp(400000000, 1), 400000000);
}
