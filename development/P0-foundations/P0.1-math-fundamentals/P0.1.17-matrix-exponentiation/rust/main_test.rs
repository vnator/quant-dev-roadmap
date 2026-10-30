use rstest::rstest;

#[test]
fn should_multiply_matrices() {
    let a = Matrix::new([[1, 2], [3, 4]]);

    let b = Matrix::new([[5, 6], [7, 8]]);

    let result = &a * &b;

    assert_eq!(result.data(), &[[19, 22], [43, 50],]);
}

#[rstest]
#[case(0, [[1, 0], [0, 1]])]
#[case(1, [[1, 1], [1, 0]])]
#[case(2, [[2, 1], [1, 1]])]
#[case(5, [[8, 5], [5, 3]])]
#[case(10, [[89, 55], [55, 34]])]
#[case(
    45,
    [
        [1836311903, 1134903170],
        [1134903170, 701408733],
    ]
)]
fn should_compute_fibonacci_matrix_powers(#[case] exponent: u64, #[case] expected: [[i32; 2]; 2]) {
    let a = Matrix::new([[1, 1], [1, 0]]);

    assert_eq!(a.pow(exponent).data(), &expected);
}

#[test]
fn should_generate_identity_matrix() {
    let identity = Matrix::<3>::identity();

    assert_eq!(identity.data(), &[[1, 0, 0], [0, 1, 0], [0, 0, 1],]);
}

#[test]
fn should_preserve_identity_property() {
    let a = Matrix::new([[2, 3], [4, 5]]);

    let identity = Matrix::<2>::identity();

    assert_eq!(&a * &identity, a);
    assert_eq!(&identity * &a, a);
}

#[test]
fn should_support_negative_elements() {
    let a = Matrix::new([[1, -1], [1, 0]]);

    let result = a.pow(3);

    assert_eq!(result.data(), &[[-1, 0], [0, -1],]);
}

#[test]
fn should_support_one_by_one_matrices() {
    let a = Matrix::new([[-2]]);

    assert_eq!(a.pow(3).data(), &[[-8]]);
    assert_eq!(a.pow(0).data(), &[[1]]);
}

#[test]
fn should_support_three_by_three_matrices() {
    let a = Matrix::new([[1, 1, 0], [0, 1, 1], [0, 0, 1]]);

    assert_eq!(a.pow(3).data(), &[[1, 3, 3], [0, 1, 3], [0, 0, 1],]);
}

#[test]
fn should_preserve_exponent_addition_property() {
    let a = Matrix::new([[1, 1], [1, 0]]);

    let a3 = a.pow(3);
    let a4 = a.pow(4);
    let a7 = a.pow(7);

    // A^(p+q) = A^p * A^q
    assert_eq!(&a3 * &a4, a7);
}

#[test]
fn should_preserve_original_matrix() {
    let a = Matrix::new([[1, 1], [1, 0]]);

    let original = a.clone();

    let _ = a.pow(5);

    assert_eq!(a, original);
}

#[test]
fn should_support_large_exponent_for_zero_matrix() {
    let a = Matrix::new([[0, 0], [0, 0]]);

    assert_eq!(a.pow(u64::MAX).data(), &[[0, 0], [0, 0],]);
}

#[test]
#[should_panic]
fn should_reject_zero_dimension() {
    let _ = Matrix::<0>::new([]);
}

#[test]
#[should_panic(expected = "Matrix overflow multy")]
fn should_detect_multiplication_overflow() {
    let a = Matrix::new([[50_000]]);

    let _ = a.pow(2);
}

#[test]
#[should_panic(expected = "Matrix overflow add")]
fn should_detect_addition_overflow() {
    let a = Matrix::new([[i32::MAX, i32::MAX], [1, 1]]);

    let b = Matrix::new([[1, 0], [1, 0]]);

    let _ = &a * &b;
}

#[rstest]
#[case(46)]
#[case(u64::MAX)]
#[should_panic(expected = "Matrix overflow")]
fn should_reject_unrepresentable_powers(#[case] exponent: u64) {
    let a = Matrix::new([[1, 1], [1, 0]]);

    let _ = a.pow(exponent);
}
