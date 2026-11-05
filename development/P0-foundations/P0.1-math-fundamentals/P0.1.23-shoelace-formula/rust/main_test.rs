use super::*;
use rstest::rstest;

#[rstest]
#[case(
    vec![0.0, 4.0, 0.0],
    vec![0.0, 0.0, 3.0],
    6.0
)]
#[case(
    vec![0.0, 1.0, 1.0, 0.0],
    vec![0.0, 0.0, 1.0, 1.0],
    1.0
)]
#[case(
    vec![0.0, 3.0, 3.0, 0.0],
    vec![0.0, 0.0, 2.0, 2.0],
    6.0
)]
#[case(
    vec![0.0, 0.0, 1.0],
    vec![0.0, 1.0, 1.0],
    0.5
)]
// Clockwise ordering must produce the same positive area.
#[case(
    vec![0.0, 0.0, 1.0, 1.0],
    vec![0.0, 1.0, 1.0, 0.0],
    1.0
)]
fn test_shoelace(#[case] x: Vec<f64>, #[case] y: Vec<f64>, #[case] expected: f64) {
    let vector = Vector { x, y };

    let result = shoelace(&vector).unwrap();

    assert!((result - expected).abs() < 1e-10);
}

#[test]
fn test_too_few_vertices() {
    let vector = Vector {
        x: vec![0.0, 1.0],
        y: vec![0.0, 1.0],
    };

    assert_eq!(shoelace(&vector), Err(ShoelaceError::TooFewVertices));
}

#[test]
fn test_coordinate_length_mismatch() {
    let vector = Vector {
        x: vec![0.0, 1.0, 2.0],
        y: vec![0.0, 1.0],
    };

    assert_eq!(
        shoelace(&vector),
        Err(ShoelaceError::CoordinateLengthMismatch)
    );
}
