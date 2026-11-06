#[derive(Debug, PartialEq, Eq)]
pub enum BurnsideError {
    EmptyGroup,
    InconsistentPermutationSize,
    InvalidPermutation,
    ArithmeticOverflow,
    NonIntegralAverage,
}

pub fn burnside_orbits(group_actions: &[Vec<usize>]) -> Result<usize, BurnsideError> {
    if group_actions.is_empty() {
        return Err(BurnsideError::EmptyGroup);
    }

    let set_size = group_actions[0].len();

    let mut total_fixed: u128 = 0;

    for permutation in group_actions {
        if permutation.len() != set_size {
            return Err(BurnsideError::InconsistentPermutationSize);
        }

        let mut seen = vec![false; set_size];

        for &image in permutation {
            if image >= set_size || seen[image] {
                return Err(BurnsideError::InvalidPermutation);
            }

            seen[image] = true;
        }

        let fixed_count = permutation
            .iter()
            .enumerate()
            .filter(|(index, image)| *index == **image)
            .count();

        total_fixed = total_fixed
            .checked_add(fixed_count as u128)
            .ok_or(BurnsideError::ArithmeticOverflow)?;
    }

    let group_size = group_actions.len() as u128;

    if total_fixed % group_size != 0 {
        return Err(BurnsideError::NonIntegralAverage);
    }

    let orbits = total_fixed / group_size;

    usize::try_from(orbits).map_err(|_| BurnsideError::ArithmeticOverflow)
}

#[cfg(test)]
mod main_test;
