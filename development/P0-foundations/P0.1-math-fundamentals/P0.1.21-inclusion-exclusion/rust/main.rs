use std::collections::HashSet;
use std::hash::Hash;

#[derive(Debug, PartialEq, Eq)]
pub enum InclusionExclusionError {
    TooManySets,
    ArithmeticOverflow,
    NegativeResult,
}

pub fn inclusion_exclusion<T>(sets: &[HashSet<T>]) -> Result<usize, InclusionExclusionError>
where
    T: Eq + Hash,
{
    let n = sets.len();

    if n >= usize::BITS as usize {
        return Err(InclusionExclusionError::TooManySets);
    }

    let subset_count = 1usize << n;
    let mut total: i128 = 0;

    // Percorre todas as combinações não vazias.
    for mask in 1..subset_count {
        let mut base_index = None;
        let mut selected_count = 0usize;

        for index in 0..n {
            if mask & (1usize << index) != 0 {
                selected_count += 1;

                match base_index {
                    None => base_index = Some(index),
                    Some(current) if sets[index].len() < sets[current].len() => {
                        base_index = Some(index);
                    }
                    _ => {}
                }
            }
        }

        let base_set = &sets[base_index.expect("Non-empty mask")];

        let intersection = base_set
            .iter()
            .filter(|element| {
                (0..n).all(|index| mask & (1usize << index) == 0 || sets[index].contains(*element))
            })
            .count();

        let term = i128::try_from(intersection)
            .map_err(|_| InclusionExclusionError::ArithmeticOverflow)?;

        total = if selected_count % 2 == 1 {
            total.checked_add(term)
        } else {
            total.checked_sub(term)
        }
        .ok_or(InclusionExclusionError::ArithmeticOverflow)?;
    }

    if total < 0 {
        return Err(InclusionExclusionError::NegativeResult);
    }

    usize::try_from(total).map_err(|_| InclusionExclusionError::ArithmeticOverflow)
}

#[cfg(test)]
mod main_test;
