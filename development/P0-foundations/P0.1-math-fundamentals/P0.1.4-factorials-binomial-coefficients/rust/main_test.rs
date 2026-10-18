use rstest::rstest;

#[rstest]
#[case(10, 3, 1)]
#[case(252, 105, 21)]
#[case(48, 18, 6)]
#[case(5, 0, 5)]
#[case(0, 5, 5)]
#[case(0, 0, 0)]
fn should_compute_gcd(#[case] a: u64, #[case] b: u64, #[case] expected: u64) {
    assert_eq!(gcd(a, b), expected);
}

#[test]
fn should_avoid_intermediate_overflow() {
    assert_eq!(
        factorial_binomial(128, 64),
        23951146041928082866135587776380551750u128
    );
}

#[test]
#[should_panic(expected = "Binomial coefficient exceeds u128")]
fn should_detect_result_overflow() {
    factorial_binomial(200, 100);
}

#[rstest]
#[case(u64::MAX, 0, 1)]
#[case(u64::MAX, 1, u64::MAX as u128)]
#[case(u64::MAX, u64::MAX, 1)]
#[case(u64::MAX, u64::MAX - 1, u64::MAX as u128)]
fn should_handle_extreme_inputs(#[case] n: u64, #[case] k: u64, #[case] expected: u128) {
    assert_eq!(factorial_binomial(n, k), expected);
}
