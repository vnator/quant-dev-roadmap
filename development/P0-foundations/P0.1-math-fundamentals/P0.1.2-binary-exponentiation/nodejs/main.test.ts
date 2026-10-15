import { describe, it, expect } from "vitest";
import binaryExp from "./main.ts";

describe("P0.1.2 Binary Exponentiation", () => {
  it.each([
    [2, 1, 2],
    [2, 2, 4],
    [2, 3, 8],
    [2, 10, 1024],
    [3, 5, 243],
  ])("Computes %i raised to %i as %i", (base, exp, expected) => {
    expect(binaryExp(base, exp)).toBe(expected);
  });

  it.each([
    [-2, 3, -8],
    [-2, 4, 16],
    [-1, 7, -1],
  ])("Handle negative base %i and exponent %i", (base, exp, expected) => {
    expect(binaryExp(base, exp)).toBe(expected);
  });

  it.each([
    [7, 0, 1],
    [0, 0, 1],
    [0, 5, 0],
    [1, 12, 1],
  ])("handles boundary case %i raised to %i", (base, exp, expected) => {
    expect(binaryExp(base, exp)).toBe(expected);
  });
});
