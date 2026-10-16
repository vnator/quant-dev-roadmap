use std::num::NonZeroU64;

pub fn mod_exp(base: i64, exp: u64, modulus: NonZeroU64) -> u64 {
    let m = u128::from(modulus.get());
    let m_i = i128::from(modulus.get());

    let mut factor = ((i128::from(base) % m_i + m_i) % m_i) as u128;

    let mut pow = exp;

    let mut result = 1u128 % m;

    while pow > 0 {
        if !pow.is_multiple_of(2) {
            result = (result * factor) % m;
        }

        pow /= 2;

        if pow > 0 {
            factor = (factor * factor) % m;
        }
    }

    result as u64
}
