import { defineConfig } from "vitest/config";
import { fileURLToPath } from "node:url";

const development = fileURLToPath(new URL("../../", import.meta.url));

export default defineConfig({
  root: development,
  test: {
    environment: "node",
    include: ["P*/*/*/nodejs/*.test.ts", "config/nodejs/tests/*.test.ts"],
    coverage: {
      provider: "v8",
      reporter: ["text", "html", "lcov"],
      reportsDirectory: "./config/nodejs/coverage",
      include: ["P*/*/*/nodejs/main.ts"],
      exclude: ["**/*.test.ts"],
    },
  },
});
