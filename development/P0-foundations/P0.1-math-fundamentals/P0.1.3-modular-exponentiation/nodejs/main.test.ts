import { describe, expect, it } from "vitest";
import modExp from "./main";

describe("P0.1.3 Modular Exponentiation", () => {
  it.each([
    [2, 3, 5, 3],
    [2, 10, 1000, 24],
    [3, 13, 7, 3],
    [10, 2, 6, 4],
  ])("computes %i^%i mod %i = %i", (base, exp, modulus, expected) => {
    expect(modExp(base, exp, modulus)).toBe(expected);
  });

  it.each([
    [-2, 3, 5, 2],
    [-2, 2, 5, 4],
    [-1, 7, 7, 6],
  ])("handles negative base %i^%i mod %i", (base, exp, modulus, expected) => {
    expect(modExp(base, exp, modulus)).toBe(expected);
  });

  it.each([
    [7, 0, 5, 1],
    [0, 0, 5, 1],
    [0, 5, 7, 0],
    [123, 100, 1, 0],
    [0, 0, 1, 0],
  ])("handles boundary case %i^%i mod %i", (base, exp, modulus, expected) => {
    expect(modExp(base, exp, modulus)).toBe(expected);
  });

  it.each([
    [Number.MAX_SAFE_INTEGER - 2, 2, Number.MAX_SAFE_INTEGER, 4],
    [2, 2 ** 40 + 1, 7, 4],
    [2, Number.MAX_SAFE_INTEGER, 7, 2],
  ])("handles large integers %i^%i mod %i", (base, exp, modulus, expected) => {
    expect(modExp(base, exp, modulus)).toBe(expected);
  });

  it.each([
    [2, -1, 7],
    [2, 3, 0],
    [2, 3, -7],
    [0.5, 2, 7],
    [2, 1.5, 7],
    [2, 2, 1.5],
    [Number.MAX_SAFE_INTEGER + 1, 2, 7],
  ])("rejects invalid input (%i, %i, %i)", (base, exp, modulus) => {
    expect(() => modExp(base, exp, modulus)).toThrow(RangeError);
  });
});
