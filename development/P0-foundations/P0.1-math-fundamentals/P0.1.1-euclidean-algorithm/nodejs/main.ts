// a = q(b) + r;
export default function gcd(a: number, b: number) {
  a = Math.abs(a);
  b = Math.abs(b);

  if (a === b) {
    return b;
  }

  while (b !== 0) {
    const r = a % b;

    a = b;
    b = r;
  }

  return a;
}
