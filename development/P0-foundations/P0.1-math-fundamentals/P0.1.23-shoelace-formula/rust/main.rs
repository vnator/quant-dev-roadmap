// Implement the mathematical algorithm here.

#[derive(Debug, PartialEq, Eq)]
pub enum ShoelaceError {
    TooFewVertices,
    CoordinateLengthMismatch,
}

pub struct Vector {
    pub x: Vec<f64>,
    pub y: Vec<f64>,
}

pub fn shoelace(vector: &Vector) -> Result<f64, ShoelaceError> {
    let n = vector.x.len();

    if n < 3 {
        return Err(ShoelaceError::TooFewVertices);
    }

    if n != vector.y.len() {
        return Err(ShoelaceError::CoordinateLengthMismatch);
    }

    let mut sum: f64 = 0.0;

    for i in 0..n {
        let j = (i + 1) % n;
        sum += (vector.x[i] * vector.y[j]) - (vector.x[j] * vector.y[i]);
    }

    Ok(sum.abs() / 2.0)
}

#[cfg(test)]
mod main_test;
