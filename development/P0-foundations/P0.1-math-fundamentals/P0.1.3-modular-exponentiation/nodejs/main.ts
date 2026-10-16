export default function modExp(
  base: number,
  exp: number,
  modulus: number,
): number {

  if (![base, exp, modulus].every(Number.isSafeInteger)) {
    throw new RangeError("Arguments must be safe integers");
  }

  if (exp < 0) {
    throw new RangeError("Exponent must be non-negative");
  }

  if (modulus <= 0) {
    throw new RangeError("Modulus must be positive");
  }

  const m = BigInt(modulus);

  let factor = ((BigInt(base) % m) + m) % m;
  let exponent = BigInt(exp);
  let result = 1n % m;

  while (exponent > 0n) {
    if ((exponent & 1n) !== 0n) {
      result = (result * factor) % m;
    }

    exponent >>= 1n;

    if (exponent > 0n) {
      factor = (factor * factor) % m;
    }
  }

  return Number(result);
}
