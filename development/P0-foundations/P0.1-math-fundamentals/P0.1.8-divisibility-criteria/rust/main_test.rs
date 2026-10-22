use rstest::rstest;

#[rstest]
#[case(4.0, 2.0, true)]
#[case(4.0, 0.0, false)]
#[case(3.0, 5.0, false)]
#[case(0.0, 5.0, true)]
#[case(0.0, 0.0, false)]
#[case(-4.0, 2.0, true)]
#[case(4.0, -2.0, true)]
#[case(-4.0, -2.0, true)]
#[case(4.5, 1.5, true)]
#[case(0.5, 0.25, true)]
#[case(0.75, 0.5, false)]
#[case(2.5, 1.0, false)]
#[case(1.0, 0.5, true)]
#[case(1.0, -0.0, false)]
#[case(f64::NAN, 2.0, false)]
#[case(2.0, f64::NAN, false)]
#[case(f64::INFINITY, 2.0, false)]
#[case(2.0, f64::INFINITY, false)]
#[case(f64::NEG_INFINITY, 2.0, false)]
fn should_validate_if_is_divisible(#[case] n: f64, #[case] d: f64, #[case] expected: bool) {
    assert_eq!(is_divisible(n, d), expected);
}
