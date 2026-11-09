use rstest::rstest;

use super::{PrefixSumError, PrefixSums};

#[rstest]
#[case(vec![3, -2, 5, 1, -6], 1, 4, 4)]
#[case(vec![1, 2, 3, 4, 5], 0, 5, 15)]
#[case(vec![1, 2, 3, 4, 5], 2, 4, 7)]
#[case(vec![-5, -2, -8], 0, 3, -15)]
#[case(vec![10], 0, 1, 10)]
#[case(vec![10, -10, 5], 0, 3, 5)]
fn should_calculate_range_sum(
    #[case] values: Vec<i64>,
    #[case] start: usize,
    #[case] end: usize,
    #[case] expected: i128,
) {
    let prefix = PrefixSums::new(&values).unwrap();

    assert_eq!(prefix.sum(start, end), Ok(expected));
}

#[rstest]
#[case(vec![], 0, 0)]
#[case(vec![1, 2, 3], 1, 1)]
#[case(vec![1, 2, 3], 0, 0)]
#[case(vec![1, 2, 3], 3, 3)]
fn should_return_zero_for_empty_ranges(
    #[case] values: Vec<i64>,
    #[case] start: usize,
    #[case] end: usize,
) {
    let prefix = PrefixSums::new(&values).unwrap();

    assert_eq!(prefix.sum(start, end), Ok(0));
}

#[rstest]
#[case(vec![1, 2, 3], 2, 1)]
#[case(vec![1, 2, 3], 0, 4)]
#[case(vec![1, 2, 3], 4, 4)]
#[case(vec![], 0, 1)]
fn should_reject_invalid_ranges(
    #[case] values: Vec<i64>,
    #[case] start: usize,
    #[case] end: usize,
) {
    let prefix = PrefixSums::new(&values).unwrap();

    assert_eq!(prefix.sum(start, end), Err(PrefixSumError::InvalidRange));
}

#[rstest]
#[case(vec![])]
#[case(vec![0])]
#[case(vec![1, -1, 2, -2])]
#[case(vec![i64::MAX, i64::MIN, i64::MAX])]
#[case(vec![-10, -20, -30, -40])]
fn should_build_prefix_sums_for_valid_inputs(#[case] values: Vec<i64>) {
    let prefix = PrefixSums::new(&values).unwrap();

    assert_eq!(
        prefix.sum(0, values.len()),
        Ok(values.iter().map(|&value| i128::from(value)).sum())
    );
}

#[rstest]
#[case(vec![3, -2, 5, 1, -6])]
#[case(vec![i64::MAX, i64::MIN, 10, -20])]
#[case(vec![-10, -20, 30, 40, -50])]
fn should_match_direct_sum_for_every_valid_range(#[case] values: Vec<i64>) {
    let prefix = PrefixSums::new(&values).unwrap();

    for start in 0..=values.len() {
        for end in start..=values.len() {
            let expected: i128 = values[start..end]
                .iter()
                .map(|&value| i128::from(value))
                .sum();

            assert_eq!(prefix.sum(start, end), Ok(expected));
        }
    }
}
