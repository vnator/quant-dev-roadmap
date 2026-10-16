use rstest::rstest;
use std::num::NonZeroU64;

#[rstest]
#[case(2, 3, 5, 3)]
#[case(2, 10, 1000, 24)]
#[case(3, 13, 7, 3)]
#[case(10, 2, 6, 4)]
fn should_compute_modular_powers(
    #[case] base: i64,
    #[case] exp: u64,
    #[case] modulus: u64,
    #[case] expected: u64,
) {
    let modulus = NonZeroU64::new(modulus).unwrap();

    assert_eq!(mod_exp(base, exp, modulus), expected);
}

#[rstest]
#[case(-2, 3, 5, 2)]
#[case(-2, 2, 5, 4)]
#[case(-1, 7, 7, 6)]
fn should_handle_negative_bases(
    #[case] base: i64,
    #[case] exp: u64,
    #[case] modulus: u64,
    #[case] expected: u64,
) {
    let modulus = NonZeroU64::new(modulus).unwrap();

    assert_eq!(mod_exp(base, exp, modulus), expected);
}

#[rstest]
#[case(7, 0, 5, 1)]
#[case(0, 0, 5, 1)]
#[case(0, 5, 7, 0)]
#[case(123, 100, 1, 0)]
#[case(0, 0, 1, 0)]
fn should_handle_boundary_cases(
    #[case] base: i64,
    #[case] exp: u64,
    #[case] modulus: u64,
    #[case] expected: u64,
) {
    let modulus = NonZeroU64::new(modulus).unwrap();

    assert_eq!(mod_exp(base, exp, modulus), expected);
}

#[rstest]
#[case(i64::MAX - 2, 2, i64::MAX as u64, 4)]
#[case(i64::MIN, 1, i64::MAX as u64, (i64::MAX - 1) as u64)]
#[case(i64::MIN, 1, u64::MAX, i64::MAX as u64)]
#[case(2, i64::MAX as u64, 7, 2)]
#[case(2, u64::MAX, 7, 1)]
fn should_handle_large_integers_without_overflow(
    #[case] base: i64,
    #[case] exp: u64,
    #[case] modulus: u64,
    #[case] expected: u64,
) {
    let modulus = NonZeroU64::new(modulus).unwrap();

    assert_eq!(mod_exp(base, exp, modulus), expected);
}

#[test]
fn should_reject_zero_modulus_at_construction() {
    assert!(NonZeroU64::new(0).is_none());
}
