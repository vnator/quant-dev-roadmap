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
#[case(0.0, 1.0, 1, 5.0)]
#[case(-2.0, 3.0, 10, 25.0)]
fn should_integrate_constant(
    #[case] a: f64,
    #[case] b: f64,
    #[case] n: usize,
    #[case] expected: f64,
) {
    let result = trapezoidal_rule(|_| 5.0, a, b, n);

    assert_close(result, expected, EPSILON);
}

#[rstest]
#[case(0.0, 2.0, 1, 10.0)]
#[case(0.0, 2.0, 4, 10.0)]
#[case(-1.0, 1.0, 2, 6.0)]
fn should_integrate_linear(
    #[case] a: f64,
    #[case] b: f64,
    #[case] n: usize,
    #[case] expected: f64,
) {
    let result = trapezoidal_rule(|x| 2.0 * x + 3.0, a, b, n);

    assert_close(result, expected, EPSILON);
}

#[rstest]
#[case(1, 4.0)]
#[case(2, 3.0)]
#[case(4, 2.75)]
#[case(8, 2.6875)]
fn should_approximate_quadratic(#[case] n: usize, #[case] expected: f64) {
    let result = trapezoidal_rule(|x| x * x, 0.0, 2.0, n);

    assert_close(result, expected, EPSILON);
}

#[test]
fn should_approximate_cubic() {
    let result = trapezoidal_rule(|x| x * x * x, 0.0, 2.0, 4);

    assert_close(result, 4.25, EPSILON);
}

#[test]
fn should_approximate_sine() {
    let result = trapezoidal_rule(|x| x.sin(), 0.0, std::f64::consts::PI, 100);

    assert_close(result, 2.0, 2e-4);
}

#[test]
fn should_handle_reversed_intervals() {
    let result = trapezoidal_rule(|x| x * x, 2.0, 0.0, 4);

    assert_close(result, -2.75, EPSILON);
}

#[test]
fn should_return_zero_for_zero_width_interval() {
    let result = trapezoidal_rule(|x| x * x, 1.5, 1.5, 4);

    assert_close(result, 0.0, 0.0);
}

#[test]
fn should_reject_zero_subintervals() {
    let result = trapezoidal_rule(|x| x * x, 0.0, 1.0, 0);

    assert!(result.is_nan());
}

#[test]
fn should_reject_nonfinite_bounds() {
    assert!(trapezoidal_rule(|x| x, f64::NAN, 1.0, 4,).is_nan());

    assert!(trapezoidal_rule(|x| x, 0.0, f64::INFINITY, 4,).is_nan());

    assert!(trapezoidal_rule(|x| x, -f64::MAX, f64::MAX, 4,).is_nan());
}

#[test]
fn should_reject_nonfinite_function_values() {
    let endpoint = trapezoidal_rule(|x| if x == 0.0 { f64::INFINITY } else { x }, 0.0, 1.0, 4);

    let interior = trapezoidal_rule(|x| if x == 0.5 { f64::NAN } else { x }, 0.0, 1.0, 2);

    assert!(endpoint.is_nan());
    assert!(interior.is_nan());
}

#[test]
fn should_converge_quadratically() {
    let f = |x: f64| x * x;
    let exact = 8.0 / 3.0;

    let e1 = (trapezoidal_rule(f, 0.0, 2.0, 1) - exact).abs();
    let e2 = (trapezoidal_rule(f, 0.0, 2.0, 2) - exact).abs();
    let e4 = (trapezoidal_rule(f, 0.0, 2.0, 4) - exact).abs();

    assert!(e4 < e2 && e2 < e1);

    assert_close(e2, e1 / 4.0, EPSILON);
    assert_close(e4, e2 / 4.0, EPSILON);
}
