use super::*;
use rstest::rstest;
use std::collections::HashSet;

#[rstest]
#[case(vec![], 0)]
#[case(vec![vec![1, 2, 3]], 3)]
#[case(vec![vec![1, 2], vec![3, 4], vec![5]], 5)]
#[case(vec![vec![1, 2, 3], vec![3, 4]], 4)]
#[case(vec![vec![1, 2, 3], vec![2, 3, 4], vec![3, 4, 5]], 5)]
#[case(vec![vec![1, 2], vec![1, 2]], 2)]
#[case(vec![vec![1, 2, 3], vec![2, 3]], 3)]
#[case(vec![vec![], vec![1, 2]], 2)]
fn test_inclusion_exclusion(#[case] values: Vec<Vec<i32>>, #[case] expected: usize) {
    let sets: Vec<HashSet<i32>> = values
        .into_iter()
        .map(|items| items.into_iter().collect())
        .collect();

    assert_eq!(inclusion_exclusion(&sets), Ok(expected));
}

#[test]
fn test_too_many_sets() {
    let sets = vec![HashSet::<i32>::new(); usize::BITS as usize];

    assert_eq!(
        inclusion_exclusion(&sets),
        Err(InclusionExclusionError::TooManySets)
    );
}
