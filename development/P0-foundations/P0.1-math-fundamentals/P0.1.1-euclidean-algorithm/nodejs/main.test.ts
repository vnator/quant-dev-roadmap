import { expect, it } from "vitest";
import gcd from "./main";
import { describe } from "node:test";

describe("P0.1.1 Elclidean Algorithm", () => {
  it("Should be return the Greatest Common Divisor", () => {
    let result = gcd(252, 105);

    expect(result).toBe(21);
  });

  it("Should be return Zero", () => {
    let result = gcd(0, 0);

    expect(result).toBe(0);
  });

  it("Should be return the same value that the entries, 20", () => {
    let result = gcd(20, 20);

    expect(result).toBe(20);
  });

  it("Should be return the Greatest Common Divisor as a Positive Number", () => {
    let result_a = gcd(-252, 105);
    let result_b = gcd(252, -105);

    expect(result_a).toBe(21);
    expect(result_b).toBe(21);
  });
});
