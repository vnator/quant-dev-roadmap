use super::*;
use rstest::rstest;

#[rstest]
#[case(0, 3, 0.5)] // Triângulo retângulo unitário
#[case(0, 4, 1.0)] // Quadrado de lado 1
#[case(1, 8, 4.0)] // Quadrado de lado 2
#[case(2, 10, 6.0)] // Retângulo 3 x 2
#[case(9, 16, 16.0)] // Quadrado de lado 4
#[case(3, 12, 8.0)] // Triângulo retângulo com catetos 4
fn test_picks_area(#[case] int_points: u64, #[case] border_points: u64, #[case] expected: f64) {
    assert_eq!(picks_area(int_points, border_points), expected);
}
