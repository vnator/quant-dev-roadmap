#[derive(Debug, Copy, Clone)]
pub struct State {
    pub t: f64,
    pub y: f64,
}

pub fn euler_step<F>(f: F, current: State, h: f64) -> State
where
    F: FnOnce(f64, f64) -> f64,
{
    let slope = f(current.t, current.y);

    State {
        t: current.t + h,
        y: current.y + h * slope,
    }
}
