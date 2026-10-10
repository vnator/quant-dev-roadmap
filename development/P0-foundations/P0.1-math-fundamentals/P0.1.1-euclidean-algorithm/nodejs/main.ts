// a = q(b) + r;
export default function gcd(a: number, b: number) {
  let q = Math.floor(a / b);
  let r = a - q * b;

  while (r > 0) {
    a = b;
    b = r;

    q = Math.floor(a / b);
    r = a - q * b;
  }

  return b;
}
