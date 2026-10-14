unsigned int gcd(int a, int b) {
  unsigned int x = (unsigned int)a;
  unsigned int y = (unsigned int)b;

  if (a < 0)
    x = -x;

  if (b < 0)
    y = -y;

  if (x == y)
    return x;

  while (y != 0) {
    unsigned int r = x % y;
    x = y;
    y = r;
  }

  return x;
}
