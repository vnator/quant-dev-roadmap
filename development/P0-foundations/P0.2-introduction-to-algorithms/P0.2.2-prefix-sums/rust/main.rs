// Implement the mathematical algorithm here.
#[derive(Debug, PartialEq, Eq)]

pub enum PrefixSumError {
    InvalidRange,
    ArithmeticOverflow,
}

pub struct PrefixSums {
    prefix: Vec<i128>,
}

impl PrefixSums {
    pub fn new(values: &[i64]) -> Result<Self, PrefixSumError> {
        let mut prefix = Vec::with_capacity(values.len().saturating_add(1));

        let mut running_total = 0i128;

        prefix.push(running_total);

        for &value in values {
            running_total = running_total
                .checked_add(i128::from(value))
                .ok_or(PrefixSumError::ArithmeticOverflow)?;

            prefix.push(running_total);
        }

        Ok(Self { prefix })
    }

    pub fn sum(&self, start: usize, end: usize) -> Result<i128, PrefixSumError> {
        if start > end || end >= self.prefix.len() {
            return Err(PrefixSumError::InvalidRange);
        }

        self.prefix[end]
            .checked_sub(self.prefix[start])
            .ok_or(PrefixSumError::ArithmeticOverflow)
    }
}
