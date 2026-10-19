use rstest::rstest;

fn assert_approx(actual: f64, expected: f64) {
    let tolerance = 1e-10 * expected.abs().max(1.0);

    assert!(
        (actual - expected).abs() <= tolerance,
        "expected {expected}, got {actual}"
    );
}

#[rstest]
#[case(2.0, 0, 1.0)]
#[case(2.0, 1, 2.0)]
#[case(2.0, 2, 4.0)]
#[case(2.0, 10, 1024.0)]
#[case(-2.0, 3, -8.0)]
#[case(-2.0, 4, 16.0)]
#[case(0.5, 3, 0.125)]
fn should_compute_binary_power(#[case] base: f64, #[case] exp: u64, #[case] expected: f64) {
    assert_approx(binary_pow(base, exp), expected);
}

#[rstest]
#[case(0, 2.0, 3.0, 0.0)]
#[case(1, 2.0, 3.0, 2.0)]
#[case(5, 2.0, 3.0, 40.0)]
#[case(4, -3.0, 2.0, 0.0)]
#[case(100, 1.0, 1.0, 5050.0)]
fn should_sum_arithmetic_progression(
    #[case] n: u64,
    #[case] a: f64,
    #[case] d: f64,
    #[case] expected: f64,
) {
    assert_approx(summ_pa(n, a, d), expected);
}

#[rstest]
#[case(0, 2.0, 3.0, 0.0)]
#[case(1, 2.0, 3.0, 2.0)]
#[case(3, 2.0, 2.0, 14.0)]
#[case(4, 2.0, 3.0, 80.0)]
#[case(5, 3.0, 1.0, 15.0)]
#[case(4, 2.0, 0.0, 2.0)]
#[case(4, 2.0, -2.0, -10.0)]
#[case(4, 2.0, 0.5, 3.75)]
#[case(4, 2.0, -1.0, 0.0)]
fn should_sum_geometric_progression(
    #[case] n: u64,
    #[case] a: f64,
    #[case] r: f64,
    #[case] expected: f64,
) {
    assert_approx(summ_pg(n, a, r), expected);
}
