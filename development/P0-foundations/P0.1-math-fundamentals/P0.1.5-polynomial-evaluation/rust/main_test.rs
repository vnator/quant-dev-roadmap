use rstest::rstest;

#[rstest]
#[case(&[2, 3, 4], 2, 24)]
#[case(&[-5, 2, 1], 3, 10)]
#[case(&[1, 2, 3], 10, 321)]
#[case(&[3, -2, 5], -2, 27)]
#[case(&[-1, 0, 1], 3, 8)]
#[case(&[1, -2, 1], 2, 1)]
fn should_evaluate_polynomials(
    #[case] coefficients: &[i64],
    #[case] x: i64,
    #[case] expected: i64,
) {
    assert_eq!(eval_polynomial(coefficients, x), expected);
}

#[rstest]
#[case(&[], 2, 0)]
#[case(&[0], 2, 0)]
#[case(&[7], 42, 7)]
#[case(&[2, 3, 4], 0, 2)]
#[case(&[0, 0, 0], -3, 0)]
#[case(&[1, -2, 1], 1, 0)]
#[case(&[0, 0, 1], -3, 9)]
fn should_handle_boundary_cases(
    #[case] coefficients: &[i64],
    #[case] x: i64,
    #[case] expected: i64,
) {
    assert_eq!(eval_polynomial(coefficients, x), expected);
}

#[rstest]
#[case(&[i64::MAX], 2, i64::MAX)]
#[case(&[i64::MIN], 2, i64::MIN)]
#[case(&[i64::MAX, 0], 1, i64::MAX)]
#[case(&[0, i64::MIN], 1, i64::MIN)]
fn should_handle_integer_limits(
    #[case] coefficients: &[i64],
    #[case] x: i64,
    #[case] expected: i64,
) {
    assert_eq!(eval_polynomial(coefficients, x), expected);
}

#[rstest]
#[case(&[0, i64::MAX], 2)]
#[case(&[1, i64::MAX], 1)]
#[case(&[0, i64::MIN], -1)]
#[case(&[-1, i64::MIN], 1)]
fn should_detect_arithmetic_overflow(#[case] coefficients: &[i64], #[case] x: i64) {
    assert!(std::panic::catch_unwind(|| { eval_polynomial(coefficients, x) }).is_err());
}
