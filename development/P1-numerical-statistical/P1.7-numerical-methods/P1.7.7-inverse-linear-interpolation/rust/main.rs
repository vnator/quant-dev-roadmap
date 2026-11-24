// Implement the mathematical algorithm here.

pub struct V {
    x: f64,
    y: f64,
}

#[derive(Debug, PartialEq, Eq)]
pub enum ErrorInterpol {
    NonFinitInput,
    EqualAbiscissa,
    EqualOrdinate,
    TargetOutOfInterval,
}

pub fn Inverse_linear_interpolation(p0: V, p1: V, target: f64) -> Result<f64, ErrorInterpol> {
    if !p0.x.is_finite()
        || !p0.y.is_finite()
        || !p1.x.is_finite()
        || !p1.y.is_finite()
        || !target.is_finite()
    {
        return Err(ErrorInterpol::NonFinitInput);
    }

    if p0.x == p1.x {
        return Err(ErrorInterpol::EqualAbiscissa);
    }

    if p0.y == p1.y {
        return Err(ErrorInterpol::EqualOrdinate);
    }

    if p0.y.min(p1.y) > target || p0.y.max(p1.y) < target {
        return Err(ErrorInterpol::TargetOutOfInterval);
    }

    if target == p0.y {
        return Ok(p0.x);
    }

    if target == p1.y {
        return Ok(p1.x);
    }

    Ok(p0.x + ((target - p0.y) / (p1.y - p0.y)) * (p1.x - p0.x))
}
