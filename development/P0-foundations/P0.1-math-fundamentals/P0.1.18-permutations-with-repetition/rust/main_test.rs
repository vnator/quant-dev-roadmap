use super::*;
use rstest::rstest;

#[rstest]
#[case(5, 2, 10)]
#[case(5, 0, 1)]
#[case(5, 5, 1)]
#[case(0, 0, 1)]
#[case(5, 6, 0)]
#[case(10, 3, 120)]
fn should_compute_binomial_coefficients(#[case] n: u64, #[case] k: u64, #[case] expected: u128) {
    assert_eq!(factorial_binomial(n, k), expected);
}

#[rstest]
#[case(6, vec![3, 2, 1], 60)]
#[case(3, vec![1, 1, 1], 6)]
#[case(4, vec![2, 2], 6)]
#[case(3, vec![0, 2, 0, 1], 3)]
#[case(3, vec![3], 1)]
#[case(0, vec![], 1)]
fn should_compute_permutations_with_repetition(
    #[case] n: u64,
    #[case] mults: Vec<u64>,
    #[case] expected: u128,
) {
    assert_eq!(permutations_with_repetition(n, &mults), expected);
}

#[test]
#[should_panic(expected = "Invalid multiplicities")]
fn should_reject_multiplicities_exceeding_n() {
    permutations_with_repetition(5, &[3, 3]);
}

#[test]
#[should_panic(expected = "Multiplicities must sum to n")]
fn should_reject_incomplete_multiplicities() {
    permutations_with_repetition(5, &[2, 2]);
}

#[test]
#[should_panic(expected = "Binomial coefficient exceeds u128")]
fn should_detect_binomial_overflow() {
    factorial_binomial(135, 67);
}

#[test]
#[should_panic(expected = "Permutation count exceeds u128")]
fn should_detect_permutation_overflow() {
    let mults = [1u64; 35];

    permutations_with_repetition(35, &mults);
}
