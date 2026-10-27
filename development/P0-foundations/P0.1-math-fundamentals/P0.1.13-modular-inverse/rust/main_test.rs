use rstest::rstest;

#[rstest]
#[case(3, 11, 4)]
#[case(10, 17, 12)]
#[case(-3, 11, 7)]
#[case(1, 13, 1)]
#[case(12, 13, 12)]
#[case(7, 26, 15)]
#[case(2, 5, 3)]
#[case(17, 3120, 2753)]
#[case(37, 100, 73)]
#[case(-1, i64::MAX, i64::MAX - 1)]
#[case(i64::MIN, i64::MAX, i64::MAX - 1)]
#[case(i64::MIN, 3, 1)]
fn should_compute_modular_inverse(#[case] a: i64, #[case] m: i64, #[case] expected: i64) {
    assert_eq!(inverse_mod(a, m), expected);
}

#[rstest]
#[case(6, 9)]
#[case(4, 8)]
#[case(0, 13)]
#[case(11, 11)]
#[case(3, 1)]
#[case(3, 0)]
#[case(3, -11)]
#[case(i64::MIN, 2)]
#[case(i64::MAX, i64::MAX)]
fn should_return_zero_when_inverse_does_not_exist(#[case] a: i64, #[case] m: i64) {
    assert_eq!(inverse_mod(a, m), 0);
}

#[rstest]
#[case(3, 11, (1, 4, -1))]
#[case(11, 3, (1, -1, 4))]
#[case(7, 26, (1, -11, 3))]
#[case(18, 30, (6, 2, -1))]
#[case(30, 18, (6, -1, 2))]
fn should_compute_extended_gcd(#[case] a: i64, #[case] b: i64, #[case] expected: (i64, i64, i64)) {
    assert_eq!(extended_gcd(a, b), expected);
}

// Independent Euclidean GCD implementation.
fn gcd_reference(mut a: i64, mut b: i64) -> i64 {
    while b != 0 {
        let remainder = a % b;
        a = b;
        b = remainder;
    }

    a
}

#[test]
fn should_satisfy_modular_inverse_property() {
    for m in 2_i64..=200 {
        for a in -200_i64..=200 {
            let normalized_a = a.rem_euclid(m);
            let gcd = gcd_reference(normalized_a, m);
            let inverse = inverse_mod(a, m);

            if gcd != 1 {
                assert_eq!(inverse, 0);
            } else {
                assert!(inverse > 0 && inverse < m);

                let product = i128::from(a) * i128::from(inverse);

                assert_eq!(
                    product.rem_euclid(i128::from(m)),
                    1,
                    "Failed for a={a}, m={m}"
                );
            }
        }
    }
}

#[test]
fn should_satisfy_property_for_large_integers() {
    let cases = [
        (i64::MIN, i64::MAX),
        (-1, i64::MAX),
        (i64::MAX - 1, i64::MAX),
        (i64::MIN, 3),
    ];

    for (a, m) in cases {
        let inverse = inverse_mod(a, m);

        let product = i128::from(a) * i128::from(inverse);

        assert_eq!(product.rem_euclid(i128::from(m)), 1);
    }
}
