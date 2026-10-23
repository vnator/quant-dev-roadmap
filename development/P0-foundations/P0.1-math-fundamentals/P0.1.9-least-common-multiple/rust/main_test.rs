use rstest::rstest;

#[rstest]
#[case(0, 0, 0)]
#[case(0, 5, 0)]
#[case(5, 0, 0)]
#[case(1, 1, 1)]
#[case(1, 99, 99)]
#[case(99, 1, 99)]
#[case(4, 6, 12)]
#[case(6, 4, 12)]
#[case(12, 18, 36)]
#[case(18, 12, 36)]
#[case(21, 6, 42)]
#[case(7, 13, 91)]
#[case(-4, 6, 12)]
#[case(4, -6, 12)]
#[case(-4, -6, 12)]
#[case(-7, 3, 21)]
#[case(42, 56, 168)]
#[case(i64::MAX, 1, i64::MAX as u64)]
#[case(i64::MAX, 2, 18_446_744_073_709_551_614)]
#[case(i64::MIN, 1, 9_223_372_036_854_775_808)]
#[case(i64::MIN, -1, 9_223_372_036_854_775_808)]
#[case(i64::MIN, 2, 9_223_372_036_854_775_808)]
#[case(i64::MIN, -2, 9_223_372_036_854_775_808)]
#[case(i64::MIN, i64::MIN / 2, 9_223_372_036_854_775_808)]
#[case(i64::MIN, i64::MIN, 9_223_372_036_854_775_808)]
#[case(3_000_000_000, 6_000_000_000, 6_000_000_000)]
fn should_compute_lcm(#[case] a: i64, #[case] b: i64, #[case] expected: u64) {
    assert_eq!(lcm(a, b), expected);
}

#[rstest]
#[case(0, 0, 0)]
#[case(5, 0, 5)]
#[case(0, 5, 5)]
#[case(24, 18, 6)]
#[case(u64::MAX, 1, 1)]
fn should_compute_gcd(#[case] a: u64, #[case] b: u64, #[case] expected: u64) {
    assert_eq!(gcd(a, b), expected);
}

#[rstest]
#[case(i64::MIN, 3)]
#[case(i64::MAX, 3)]
#[case(i64::MIN, i64::MAX)]
#[should_panic(expected = "LCM exceeds u64")]
fn should_detect_lcm_overflow(#[case] a: i64, #[case] b: i64) {
    lcm(a, b);
}
