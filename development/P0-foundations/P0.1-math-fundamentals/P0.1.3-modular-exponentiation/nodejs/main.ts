export default function modExp(
  base: number,
  exp: number,
  modulus: number,
): number {
  if (modulus == 1) return 0;
  let result = 1;

  base %= modulus;

  while (exp > 0) {
    if ((exp & 1) === 1) {
      result = (result * base) % modulus;
    }

    exp >>= 1;
    base = (base * base) % modulus;
  }

  return result;
}
