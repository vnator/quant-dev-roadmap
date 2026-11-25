// Implement the mathematical algorithm here.
#[derive(Debug, Copy, Clone)]
struct State {
    t: f64,
    y: f64,
}

pub fn euler_step<F>(f: F, current: State, h: f64) -> State
where
    F: Derivative(f64, f64) -> f64,
{
    let slope = f(current.t, current.y);

    State {
        t: current.t + h,
        y: current.y + h * slope,
    }
}
