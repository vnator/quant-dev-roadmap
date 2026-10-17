export default function factorialBinomial(n: number, k: number): number {
  if (k > n) return 0;

  if (k > n - k) {
    n = n - k;
  }

  let result = 1;

  for (let i = 1; i <= k; i++) {
    result = (result * (n - i + 1)) / i;
  }

  return result;
}
