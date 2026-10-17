use rstest::rstest;

#[rstest]
#[case(5, 2, 10)]
#[case(6, 3, 20)]
#[case(8, 4, 70)]
#[case(10, 3, 120)]
#[case(20, 10, 184756)]
#[case(30, 15, 155117520)]
fn should_compute_binomial_coefficient(#[case] n: u64, #[case] k: u64, #[case] expected: u128) {
    assert_eq!(factorial_binomial(n, k), expected);
}

#[rstest]
#[case(0, 0, 1)]
#[case(1, 0, 1)]
#[case(1, 1, 1)]
#[case(5, 0, 1)]
#[case(5, 5, 1)]
#[case(10, 1, 10)]
#[case(10, 10, 1)]
fn should_handle_boundary_cases(#[case] n: u64, #[case] k: u64, #[case] expected: u128) {
    assert_eq!(factorial_binomial(n, k), expected);
}

#[rstest]
#[case(0, 1)]
#[case(2, 3)]
#[case(3, 5)]
#[case(10, 11)]
fn should_return_zero_when_k_exceeds_n(#[case] n: u64, #[case] k: u64) {
    assert_eq!(factorial_binomial(n, k), 0);
}

#[rstest]
#[case(5, 2)]
#[case(10, 3)]
#[case(20, 5)]
#[case(30, 12)]
fn should_preserve_binomial_symmetry(#[case] n: u64, #[case] k: u64) {
    assert_eq!(factorial_binomial(n, k), factorial_binomial(n, n - k));
}

#[rstest]
#[case(5, 2)]
#[case(10, 4)]
#[case(20, 8)]
#[case(30, 12)]
fn should_satisfy_pascals_identity(#[case] n: u64, #[case] k: u64) {
    let expected = factorial_binomial(n - 1, k - 1) + factorial_binomial(n - 1, k);

    assert_eq!(factorial_binomial(n, k), expected);
}

#[rstest]
#[case(50, 25, 126410606437752)]
#[case(67, 33, 14226520737620288370)]
#[case(100, 50, 100891344545564193334812497256)]
fn should_handle_large_binomial_coefficients(
    #[case] n: u64,
    #[case] k: u64,
    #[case] expected: u128,
) {
    assert_eq!(factorial_binomial(n, k), expected);
}
