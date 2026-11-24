#[test]
fn interpolates_with_both_point_orders() {
    let p0 = V::new(20.0, 1.0);
    let p1 = V::new(30.0, 1.5);

    for (start, end) in [(p0, p1), (p1, p0)] {
        let result = Inverse_linear_interpolation(start, end, 1.2).unwrap();
        assert!((result - 24.0).abs() < 1e-12);
    }
}

#[test]
fn returns_exact_endpoints() {
    let p0 = V::new(20.0, 1.0);
    let p1 = V::new(30.0, 1.5);

    assert_eq!(Inverse_linear_interpolation(p0, p1, 1.0), Ok(20.0));
    assert_eq!(Inverse_linear_interpolation(p0, p1, 1.5), Ok(30.0));
}

#[test]
fn rejects_targets_outside_the_interval() {
    let p0 = V::new(20.0, 1.0);
    let p1 = V::new(30.0, 1.5);

    for target in [0.5, 2.0] {
        assert_eq!(
            Inverse_linear_interpolation(p0, p1, target),
            Err(ErrorInterpol::TargetOutOfInterval)
        );
    }
}

#[test]
fn rejects_degenerate_points() {
    let p0 = V::new(20.0, 1.0);

    assert_eq!(
        Inverse_linear_interpolation(p0, V::new(20.0, 1.5), 1.2),
        Err(ErrorInterpol::EqualAbiscissa)
    );
    assert_eq!(
        Inverse_linear_interpolation(p0, V::new(30.0, 1.0), 1.0),
        Err(ErrorInterpol::EqualOrdinate)
    );
}

#[test]
fn rejects_non_finite_inputs() {
    let p0 = V::new(20.0, 1.0);
    let p1 = V::new(30.0, 1.5);

    assert_eq!(
        Inverse_linear_interpolation(p0, p1, f64::NAN),
        Err(ErrorInterpol::NonFinitInput)
    );
    assert_eq!(
        Inverse_linear_interpolation(V::new(f64::INFINITY, 1.0), p1, 1.2),
        Err(ErrorInterpol::NonFinitInput)
    );
}

#[test]
fn handles_extreme_finite_coordinates() {
    let p0 = V::new(-f64::MAX, -f64::MAX);
    let p1 = V::new(f64::MAX, f64::MAX);

    assert_eq!(Inverse_linear_interpolation(p0, p1, 0.0), Ok(0.0));
}
