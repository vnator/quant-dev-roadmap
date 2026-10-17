import { describe, expect, it } from "vitest";
import factorialBinomial from "./main";

describe("P0.1.4 Factorials & Binomial Coefficients", () => {
  it.each([
    [5, 2, 10],
    [6, 3, 20],
    [8, 4, 70],
    [10, 3, 120],
    [20, 10, 184756],
    [30, 15, 155117520],
  ])("computes C(%i, %i) = %i", (n, k, expected) => {
    expect(factorialBinomial(n, k)).toBe(expected);
  });

  it.each([
    [0, 0, 1],
    [1, 0, 1],
    [1, 1, 1],
    [5, 0, 1],
    [5, 5, 1],
    [10, 1, 10],
    [10, 10, 1],
  ])("handles boundary case C(%i, %i) = %i", (n, k, expected) => {
    expect(factorialBinomial(n, k)).toBe(expected);
  });

  it.each([
    [0, 1],
    [2, 3],
    [3, 5],
    [10, 11],
  ])("returns zero when k > n: C(%i, %i)", (n, k) => {
    expect(factorialBinomial(n, k)).toBe(0);
  });

  it.each([
    [5, 2],
    [10, 3],
    [20, 5],
    [30, 12],
  ])("preserves binomial symmetry for C(%i, %i)", (n, k) => {
    expect(factorialBinomial(n, k)).toBe(factorialBinomial(n, n - k));
  });

  it.each([
    [5, 2],
    [10, 4],
    [20, 8],
    [30, 12],
  ])("satisfies Pascal's identity for C(%i, %i)", (n, k) => {
    const expected =
      factorialBinomial(n - 1, k - 1) + factorialBinomial(n - 1, k);

    expect(factorialBinomial(n, k)).toBe(expected);
  });

  it.each([
    [40, 20, 137846528820],
    [50, 25, 126410606437752],
    [52, 26, 495918532948104],
  ])("computes large coefficient C(%i, %i)", (n, k, expected) => {
    expect(factorialBinomial(n, k)).toBe(expected);
  });
});
