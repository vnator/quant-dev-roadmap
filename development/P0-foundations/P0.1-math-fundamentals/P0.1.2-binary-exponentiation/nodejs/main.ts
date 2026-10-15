export default function binaryExp(base: number, exp: number): number {
  let result = 1;
  let isPositive = exp > 0;

  while (exp > 0) {
    if (exp % 2 === 1) {
      result *= base;
    }

    base *= base;
    exp = Math.floor(exp / 2);
  }

  return isPositive ? result : 1 / result;
}
