pub fn derangement(n: u128) -> u128 {
    if n == 0 {
        return 1;
    }

    if n == 1 {
        return 0;
    }

    let mut d_prev2 = 1u128;

    let mut d_prev1 = 0u128;

    for i in 2..=n {
        let sum = d_prev1
            .checked_add(d_prev2)
            .expect("Derangement exceeds u128");

        let current = (i - 1).checked_mul(sum).expect("Derangement exceeds u128");

        d_prev2 = d_prev1;
        d_prev1 = current;
    }

    d_prev1
}
