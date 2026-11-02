use super::*;
use rstest::rstest;

#[rstest]
#[case(0, 1)]
#[case(1, 1)]
#[case(2, 2)]
#[case(3, 5)]
#[case(4, 14)]
#[case(5, 42)]
#[case(6, 132)]
#[case(7, 429)]
#[case(8, 1430)]
#[case(9, 4862)]
#[case(10, 16796)]
#[case(15, 9694845)]
#[case(20, 6564120420)]
fn should_compute_catalan_numbers(#[case] n: u64, #[case] expected: u128) {
    assert_eq!(catalan_number(n), expected);
}

#[test]
fn should_compute_largest_catalan_number_in_u128() {
    assert_eq!(
        catalan_number(69),
        337485502510215975556783793455058624700u128
    );
}

#[test]
#[should_panic(expected = "Catalan number exceeds u128")]
fn should_detect_catalan_overflow() {
    catalan_number(70);
}
