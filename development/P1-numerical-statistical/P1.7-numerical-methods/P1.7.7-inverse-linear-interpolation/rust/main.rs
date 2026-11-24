// Implement the mathematical algorithm here.

#[derive(Debug, Clone, Copy)]
pub struct V {
    x: f64,
    y: f64,
}

impl V {
    pub fn new(x: f64, y: f64) -> Self {
        Self { x, y }
    }
}

#[derive(Debug, PartialEq, Eq)]
pub enum ErrorInterpol {
    NonFinitInput,
    EqualAbiscissa,
    EqualOrdinate,
    TargetOutOfInterval,
}

pub fn Inverse_linear_interpolation(p0: V, p1: V, target: f64) -> Result<f64, ErrorInterpol> {
    if ![p0.x, p0.y, p1.x, p1.y, target]
        .iter()
        .all(|v| v.is_finite())
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

    let dy = p1.y - p0.y;

    let fraction = if dy.is_finite() {
        (target - p0.y) / dy
    } else {
        (target / 2.0 - p0.y / 2.0) / (p1.y / 2.0 - p0.y / 2.0)
    };

    let x = if p0.x.is_sign_negative() != p1.x.is_sign_negative() {
        (1.0 - fraction) * p0.x + fraction * p1.x
    } else {
        fraction.mul_add(p1.x - p0.x, p0.x)
    };

    Ok(x)
}
