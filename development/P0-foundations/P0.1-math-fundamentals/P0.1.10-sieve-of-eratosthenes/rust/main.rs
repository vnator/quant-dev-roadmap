pub fn sieve(limit: i64) -> Vec<i64> {
    if limit < 2 {
        return Vec::new();
    }

    let n = usize::try_from(limit).expect("Limit exceed usize");

    let length = n.checked_add(1).expect("limit is too large");

    let mut is_prime = vec![true; length];

    is_prime[0] = false;
    is_prime[1] = false;

    let mut p = 2usize;

    while p <= n / p {
        if is_prime[p] {
            for i in (p * p..=n).step_by(p) {
                is_prime[i] = false;
            }
        }

        p += 1;
    }

    let mut primes = Vec::new();

    for i in 2..=n {
        if is_prime[i] {
            primes.push(i as i64);
        }
    }

    primes
}
