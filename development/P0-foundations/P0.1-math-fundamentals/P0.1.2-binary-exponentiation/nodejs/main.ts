export default function binaryExp(base: number, exp: number): number {
  let result = 1;

  while (exp > 0) {
    if (exp % 1 === 1) {
      result *= base;
    }

    base *= base;
    exp /= 2;
  }

  return exp > 0 ? result : 1 / result;
}
