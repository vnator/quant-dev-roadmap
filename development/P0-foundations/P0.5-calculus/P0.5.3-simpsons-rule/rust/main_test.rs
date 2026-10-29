use rstest::rstest;

const EPSILON: f64 = 1e-12;

fn assert_close(actual: f64, expected: f64, tolerance: f64) {
    assert!(actual.is_finite(), "Non-finite result: {actual}");

    assert!(
        (actual - expected).abs() <= tolerance,
        "Expected {expected}, got {actual}"
    );
}

#[rstest]
#[case(0.0, 1.0, 2, 5.0)]
#[case(-2.0, 3.0, 10, 25.0)]
fn should_integrate_constant(
    #[case] a: f64,
    #[case] b: f64,
    #[case] n: usize,
    #[case] expected: f64,
) {
    assert_close(simpsons_rule(|_| 5.0, a, b, n), expected, EPSILON);
}

#[rstest]
#[case(0.0, 2.0, 2, 10.0)]
#[case(0.0, 2.0, 4, 10.0)]
#[case(-1.0, 1.0, 2, 6.0)]
fn should_integrate_linear(
    #[case] a: f64,
    #[case] b: f64,
    #[case] n: usize,
    #[case] expected: f64,
) {
    assert_close(simpsons_rule(|x| 2.0 * x + 3.0, a, b, n), expected, EPSILON);
}

#[rstest]
#[case(0.0, 2.0, 2, 8.0 / 3.0)]
#[case(0.0, 2.0, 4, 8.0 / 3.0)]
fn should_integrate_quadratic(
    #[case] a: f64,
    #[case] b: f64,
    #[case] n: usize,
    #[case] expected: f64,
) {
    assert_close(simpsons_rule(|x| x * x, a, b, n), expected, EPSILON);
}

#[rstest]
#[case(0.0, 2.0, 2, 4.0)]
#[case(-1.0, 2.0, 6, 3.75)]
fn should_integrate_cubic(#[case] a: f64, #[case] b: f64, #[case] n: usize, #[case] expected: f64) {
    assert_close(simpsons_rule(|x| x * x * x, a, b, n), expected, EPSILON);
}

#[test]
fn should_approximate_sine() {
    let actual = simpsons_rule(|x| x.sin(), 0.0, std::f64::consts::PI, 100);
    assert_close(actual, 2.0, 1e-7);
}

#[test]
fn should_handle_reversed_interval() {
    let actual = simpsons_rule(|x| x * x, 2.0, 0.0, 4);
    assert_close(actual, -8.0 / 3.0, EPSILON);
}

#[test]
fn should_handle_zero_width_interval() {
    let actual = simpsons_rule(|x| x * x, 1.5, 1.5, 4);
    assert_close(actual, 0.0, 0.0);
}

#[rstest]
#[case(0)]
#[case(1)]
#[case(3)]
fn should_reject_invalid_subinterval_counts(#[case] n: usize) {
    assert!(simpsons_rule(|x| x * x, 0.0, 1.0, n).is_nan());
}

#[test]
fn should_reject_nonfinite_bounds() {
    assert!(simpsons_rule(|x| x, f64::NAN, 1.0, 4).is_nan());
    assert!(simpsons_rule(|x| x, 0.0, f64::INFINITY, 4).is_nan());
    assert!(simpsons_rule(|x| x, -f64::MAX, f64::MAX, 4).is_nan());
}

#[test]
fn should_reject_nonfinite_function_values() {
    let endpoint = simpsons_rule(|x| if x == 0.0 { f64::INFINITY } else { x }, 0.0, 1.0, 4);

    let interior = simpsons_rule(|x| if x == 0.5 { f64::NAN } else { x }, 0.0, 1.0, 2);

    assert!(endpoint.is_nan());
    assert!(interior.is_nan());
}

#[test]
fn should_converge_for_quartic() {
    let exact = 0.2;
    let coarse = simpsons_rule(|x| x * x * x * x, 0.0, 1.0, 2);
    let fine = simpsons_rule(|x| x * x * x * x, 0.0, 1.0, 4);

    assert!((fine - exact).abs() < (coarse - exact).abs());
    assert_close(coarse, 0.20833333333333334, EPSILON);
    assert_close(fine, 0.20052083333333334, EPSILON);
}

#[test]
fn should_accumulate_all_simpson_weights() {
    let result = simpsons_rule(|x| x * x, 0.0, 2.0, 4);

    assert!((result - 8.0 / 3.0).abs() < 1e-12);
}

#[test]
fn should_work_with_minimum_subintervals() {
    let result = simpsons_rule(|x| x * x, 0.0, 2.0, 2);

    assert!((result - 8.0 / 3.0).abs() < 1e-12);
}

#[test]
fn should_reject_non_finite_endpoint_evaluation() {
    let result = simpsons_rule(|x| if x == 0.0 { f64::NAN } else { x }, 0.0, 1.0, 4);

    assert!(result.is_nan());
}

#[test]
fn should_reject_non_finite_interior_evaluation() {
    let result = simpsons_rule(|x| if x == 0.5 { f64::INFINITY } else { x }, 0.0, 1.0, 2);

    assert!(result.is_nan());
}

#[test]
fn should_handle_zero_width_with_large_values() {
    let result = simpsons_rule(|_| f64::MAX, 1.0, 1.0, 4);

    assert_eq!(result, 0.0);
}

#[test]
fn should_reject_odd_number_of_subintervals() {
    let result = simpsons_rule(|x| x * x, 0.0, 2.0, 3);

    assert!(result.is_nan());
}
