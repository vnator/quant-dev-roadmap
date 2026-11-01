use super::*;
use rstest::rstest;

#[rstest]
#[case(0, 1)]
#[case(1, 0)]
#[case(2, 1)]
#[case(3, 2)]
#[case(4, 9)]
#[case(5, 44)]
#[case(6, 265)]
#[case(7, 1854)]
#[case(8, 14833)]
#[case(9, 133496)]
#[case(10, 1334961)]
#[case(15, 481066515734)]
#[case(20, 895014631192902121)]
#[case(34, 108610077126170304674801654684367969729)]
fn should_compute_derangements(#[case] n: u128, #[case] expected: u128) {
    assert_eq!(derangement(n), expected);
}

#[test]
#[should_panic(expected = "Derangement exceeds u128")]
fn should_detect_derangement_overflow() {
    derangement(35);
}
