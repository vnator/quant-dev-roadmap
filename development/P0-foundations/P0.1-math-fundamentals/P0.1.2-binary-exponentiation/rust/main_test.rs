use rstest::rstest;

#[rstest]
#[case(2, 1, 2)]
#[case(2, 2, 4)]
#[case(2, 3, 8)]
#[case(2, 10, 1024)]
#[case(3, 5, 243)]
fn should_compute_positive_powers(#[case] base: i64, #[case] exp: i64, #[case] expected: i64) {
    assert_eq!(binary_exp(base, exp), expected);
}

#[rstest]
#[case(-2, 3, -8)]
#[case(-2, 4, 16)]
#[case(-1, 7, -1)]
fn should_handle_negative_powers(#[case] base: i64, #[case] exp: i64, #[case] expected: i64) {
    assert_eq!(binary_exp(base, exp), expected);
}

#[rstest]
#[case(7, 0, 1)]
#[case(0, 0, 1)]
#[case(0, 5, 0)]
#[case(1, 12, 1)]
fn should_return_a_negative_number(#[case] base: i64, #[case] exp: i64, #[case] expected: i64) {
    assert_eq!(binary_exp(base, exp), expected);
}
