#[test]
fn evaluates_slope_at_start() {
    let mut calls = 0;
    let next = euler_step(
        |t, y| {
            calls += 1;
            t + 2.0 * y
        },
        State { t: 2.0, y: 3.0 },
        0.25,
    );

    assert_eq!(calls, 1);
    assert_eq!(next.t, 2.25);
    assert_eq!(next.y, 5.0);
}

#[test]
fn chains_three_cooling_steps() {
    let cooling = |_: f64, y: f64| -0.1 * (y - 20.0);
    let mut state = State { t: 0.0, y: 80.0 };

    for expected in [74.0, 68.6, 63.74] {
        state = euler_step(cooling, state, 1.0);
        assert!((state.y - expected).abs() < 1e-12);
    }

    assert_eq!(state.t, 3.0);
}
