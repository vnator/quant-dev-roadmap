function gcd(a: bigint, b: bigint): bigint {
  while (b !== 0n) {
    const remainder = a % b;
    a = b;
    b = remainder;
  }

  return a;
}

export function factorialBinomialExact(n: bigint, k: bigint): bigint {
  if (n < 0n || k < 0n) {
    throw new RangeError("n and k must be non-negative");
  }

  if (k > n) {
    return 0n;
  }

  if (k > n - k) {
    k = n - k;
  }

  let result = 1n;

  for (let i = 1n; i <= k; i++) {
    let numerator = n - i + 1n;
    let denominator = i;

    const divisor = gcd(numerator, denominator);

    numerator /= divisor;
    denominator /= divisor;

    if (result % denominator !== 0n) {
      throw new Error("Non-exact binomial division");
    }

    result = (result / denominator) * numerator;
  }

  return result;
}

export default function factorialBinomial(n: number, k: number): number {
  if (!Number.isSafeInteger(n) || !Number.isSafeInteger(k) || n < 0 || k < 0) {
    throw new RangeError("n and k must be non-negative safe integers");
  }

  const result = factorialBinomialExact(BigInt(n), BigInt(k));

  if (result > BigInt(Number.MAX_SAFE_INTEGER)) {
    throw new RangeError("Binomial coefficient exceeds safe integer range");
  }

  return Number(result);
}
