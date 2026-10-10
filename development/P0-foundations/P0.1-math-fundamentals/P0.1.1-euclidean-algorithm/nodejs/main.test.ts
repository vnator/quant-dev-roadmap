import { expect, it } from "vitest";
import gcd from "./main";

it("Euclidean Algorith: Find Greatest Common Divisor with", () => {
  let result = gcd(252, 105);

  expect(result).toBe(21);
});
