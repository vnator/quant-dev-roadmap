// Implement the mathematical algorithm here.
pub fn max_subarray_sum(list: &[i64]) -> Option<i128> {
    let (&head, tail) = list.split_first()?;

    let mut best_ending = i128::from(head);
    let mut best_overall = best_ending;

    for &item in tail {
        let value = i128::from(item);

        best_ending = value.max(best_ending + value);
        best_overall = best_overall.max(best_ending);
    }

    Some(best_overall)
}
