use rstest::rstest;

#[rstest]
#[case(0, 0, 1)]
#[case(1, 1, 1)]
#[case(2, 1, 2)]
#[case(3, 2, 3)]
#[case(5, 5, 8)]
#[case(10, 55, 89)]
#[case(20, 6765, 10946)]
#[case(50, 12586269025, 20365011074)]
#[case(92, 7540113804746346429, 12200160415121876738)]
#[case(93, 12200160415121876738, 19740274219868223167)]
#[case(100, 354224848179261915075, 573147844013817084101)]
#[case(
    184,
    127127879743834334146972278486287885163,
    205697230343233228174223751303346572685
)]
#[case(
    185,
    205697230343233228174223751303346572685,
    332825110087067562321196029789634457848
)]
fn should_compute_fibonacci_pair(
    #[case] n: u128,
    #[case] expected_current: u128,
    #[case] expected_next: u128,
) {
    assert_eq!(
        fibonacci_fast_doubling(n),
        (expected_current, expected_next)
    );
}

fn fibonacci_iterative(n: u128) -> (u128, u128) {
    let mut a = 0u128;
    let mut b = 1u128;

    for _ in 0..n {
        let next = a + b;
        a = b;
        b = next;
    }

    (a, b)
}

#[test]
fn should_match_iterative_reference() {
    for n in 0..=185 {
        assert_eq!(
            fibonacci_fast_doubling(n),
            fibonacci_iterative(n),
            "Incorrect Fibonacci pair at n={n}"
        );
    }
}

#[test]
fn should_preserve_fibonacci_recurrence() {
    for n in 0..185 {
        let (fn0, fn1) = fibonacci_fast_doubling(n);
        let (next_fn, fn2) = fibonacci_fast_doubling(n + 1);

        assert_eq!(fn1, next_fn);
        assert_eq!(fn0 + fn1, fn2);
    }
}

#[rstest]
#[case(186)]
#[case(u128::MAX)]
#[should_panic(expected = "F(n + 1) exceeds u128")]
fn should_reject_unrepresentable_results(#[case] n: u128) {
    fibonacci_fast_doubling(n);
}
