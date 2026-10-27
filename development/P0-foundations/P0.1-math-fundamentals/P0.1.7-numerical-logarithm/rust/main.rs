#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum LogError {
    InvalidDomain,
    InvalidBase,
    InvalidTolerance,
    DidNotConverge,
}

const MAX_TERMS: usize = 512;

fn ln_series(x: f64, epsilon: f64) -> Result<f64, LogError> {
    let z = (x - 1.0) / (x + 1.0);
    let z_squared = z * z;

    let mut power = z;
    let mut sum = 0.0;

    for k in 0..MAX_TERMS {
        let denominator = (2 * k + 1) as f64;

        let next_sum = sum + 2.0 * power / denominator;

        power *= z_squared;

        let remainder_bound = 2.0 * power.abs() / ((2 * k + 3) as f64 * (1.0 - z_squared));

        if remainder_bound <= epsilon {
            return Ok(next_sum);
        }

        if next_sum == sum {
            return Err(LogError::DidNotConverge);
        }

        sum = next_sum;
    }

    Err(LogError::DidNotConverge)
}

pub fn log_n(x: f64, epsilon: f64) -> Result<f64, LogError> {
    if !epsilon.is_finite() || epsilon <= 0.0 {
        return Err(LogError::InvalidTolerance);
    }

    if !x.is_finite() || x <= 0.0 {
        return Err(LogError::InvalidDomain);
    }

    if x == 1.0 {
        return Ok(0.0);
    }

    let mut mantissa = x;
    let mut exponent: i32 = 0;

    while mantissa > 2.0 {
        mantissa *= 0.5;
        exponent += 1;
    }

    while mantissa < 0.5 {
        mantissa *= 2.0;
        exponent -= 1;
    }

    let component_epsilon = epsilon / (f64::from(exponent.unsigned_abs()) + 1.0);

    if component_epsilon == 0.0 {
        return Err(LogError::DidNotConverge);
    }

    let ln_mantissa = ln_series(mantissa, component_epsilon)?;

    if exponent == 0 {
        return Ok(ln_mantissa);
    }

    let ln_two = ln_series(2.0, component_epsilon)?;

    Ok(f64::from(exponent) * ln_two + ln_mantissa)
}

pub fn log_base(x: f64, base: f64, epsilon: f64) -> Result<f64, LogError> {
    if !epsilon.is_finite() || epsilon <= 0.0 {
        return Err(LogError::InvalidTolerance);
    }

    if !x.is_finite() || x <= 0.0 {
        return Err(LogError::InvalidDomain);
    }

    if !base.is_finite() || base <= 0.0 || base == 1.0 {
        return Err(LogError::InvalidBase);
    }

    if x == 1.0 {
        return Ok(0.0);
    }

    if x == base {
        return Ok(1.0);
    }

    let numerator = log_n(x, epsilon)?;
    let denominator = log_n(base, epsilon)?;

    Ok(numerator / denominator)
}
