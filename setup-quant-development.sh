#!/usr/bin/env bash
set -euo pipefail

# Quant Development: centralized config, exactly two code/test files per language.
# Run from the repository root. No dependency installs, commits, or deletions.
ROOT=development
[[ -f README.md ]] || { echo 'Run from the repository root (README.md missing).' >&2; exit 1; }
mkdir -p "$ROOT" "$ROOT/docs" "$ROOT/template" "$ROOT/config" 

# Canonical scope paths (the numeric IDs are stable).
cat > /tmp/quant-scopes-$$ <<'SCOPES'
P0|1|math-fundamentals
P0|2|introduction-to-algorithms
P0|3|dynamic-programming
P0|4|linear-algebra
P0|5|calculus
P0|6|probability-statistics
P1|7|numerical-methods
P1|8|numerical-linear-algebra
P1|9|numerical-optimization
P1|10|monte-carlo
P1|11|stochastic-processes
P1|12|time-series
P1|13|econometrics
P1|14|stochastic-calculus
P1|15|differential-equations
P2|16|quantitative-algorithms
P2|17|derivatives-pricing
P2|18|portfolio-optimization
P2|19|financial-risk
P2|20|market-microstructure
P2|21|algorithmic-execution
P2|22|backtesting
P2|23|fixed-income
P2|24|credit-risk
P2|25|volatility-modeling
P2|26|statistical-arbitrage
P3|27|parallel-programming
P3|28|concurrent-distributed
P3|29|low-latency
P3|30|gpu-computing
P3|31|signal-processing
P3|32|information-theory
P3|33|bayesian-inference
P3|34|graph-algorithms
P3|35|optimal-control
P3|36|machine-learning
P3|37|reinforcement-learning
SCOPES
SCOPES_FILE=/tmp/quant-scopes-$$
trap 'rm -f "$SCOPES_FILE" "$CATALOG_FILE"' EXIT

priority_dir() {
  case "$1" in
    P0) echo P0-foundations;; P1) echo P1-numerical-statistical;;
    P2) echo P2-quantitative-finance;; P3) echo P3-advanced-computing;;
    *) return 1;;
  esac
}

# Algorithm names, one per line: scope number | canonical slug.
# This is the complete condensed roadmap PLUS the article's nonduplicate exercises.
CATALOG_FILE=/tmp/quant-catalog-$$
cat > "$CATALOG_FILE" <<'CATALOG'
1|euclidean-algorithm
1|binary-exponentiation
1|modular-exponentiation
1|factorials-binomial-coefficients
1|polynomial-evaluation
1|arithmetic-geometric-progressions
1|numerical-logarithm
1|divisibility-criteria
1|least-common-multiple
1|sieve-of-eratosthenes
1|integer-factorization
1|extended-euclidean-algorithm
1|modular-inverse
1|euler-totient
1|miller-rabin
1|fibonacci-fast-doubling
1|matrix-exponentiation
1|permutations-with-repetition
1|derangements
1|catalan-numbers
1|inclusion-exclusion
1|picks-theorem
1|shoelace-formula
1|burnsides-lemma
1|polya-enumeration
2|kadanes-algorithm
2|prefix-sums
2|bitset-operations
2|binary-search
2|merge-sort
2|quick-sort
2|heap-sort
2|quickselect
2|binary-heap
2|hash-table
2|binary-search-tree
2|red-black-tree
3|fibonacci-dynamic-programming
3|collatz-memoization
3|tower-of-hanoi
3|pascals-triangle
3|zero-one-knapsack
3|weighted-interval-scheduling
3|matrix-chain-multiplication
3|bellman-value-iteration
4|matrix-multiplication
4|gaussian-elimination-partial-pivoting
4|lu-decomposition
4|cholesky-decomposition
4|qr-decomposition
4|power-iteration
4|singular-value-decomposition
5|numerical-differentiation
5|trapezoidal-rule
5|simpsons-rule
5|partial-derivative-approximation
5|gradient-approximation
5|jacobian-matrix-approximation
6|binomial-distribution
6|poisson-distribution
6|normal-distribution
6|exponential-distribution
6|student-t-distribution
6|cumulative-distribution-function
6|inverse-cdf-quantile
6|welford-mean-variance
6|covariance-correlation
6|bayesian-updating
6|maximum-likelihood-estimation
6|student-t-test
7|bisection-method
7|newton-raphson-method
7|brents-method
7|cubic-spline-interpolation
7|gaussian-quadrature
7|adaptive-simpson-integration
8|conjugate-gradient-solver
8|gmres
8|qr-eigenvalue-algorithm
8|sparse-matrix-vector-csr
9|gradient-descent
9|newton-optimization
9|bfgs
9|projected-gradient-descent
9|quadratic-programming-solver
10|xoshiro-prng
10|inverse-transform-sampling
10|box-muller-transform
10|monte-carlo-integration
10|importance-sampling
10|antithetic-variates
10|control-variates
10|sobol-sequence
11|random-walk
11|markov-chain-simulation
11|markov-stationary-distribution
11|poisson-process-simulation
11|brownian-motion-simulation
11|ornstein-uhlenbeck-process
12|simple-moving-average
12|exponential-moving-average
12|autocorrelation-function
12|autoregressive-model
12|arima-model
12|garch-1-1
12|kalman-filter
12|augmented-dickey-fuller-test
13|ordinary-least-squares
13|weighted-least-squares
13|newey-west-standard-errors
13|engle-granger-cointegration
13|vector-autoregression
14|ito-integral-approximation
14|euler-maruyama
14|milstein-method
14|geometric-brownian-motion-sde
14|cox-ingersoll-ross-sde
15|euler-method
15|runge-kutta-fourth-order
15|adaptive-runge-kutta
15|finite-difference-method
15|crank-nicolson
16|simple-log-returns
16|historical-volatility
16|realized-volatility
16|rolling-covariance-matrix
16|exponentially-weighted-covariance
16|maximum-drawdown
16|sharpe-ratio
17|cox-ross-rubinstein-binomial-tree
17|black-scholes-merton
17|black-scholes-greeks
17|implied-volatility-solver
17|american-option-pricing
17|monte-carlo-option-pricing
17|finite-difference-option-pricing
18|minimum-variance-portfolio
18|markowitz-mean-variance
18|efficient-frontier
18|maximum-sharpe-portfolio
18|risk-parity-portfolio
18|transaction-cost-portfolio-optimization
19|historical-value-at-risk
19|parametric-value-at-risk
19|expected-shortfall
19|portfolio-stress-testing
20|limit-order-book
20|order-book-reconstruction
20|price-time-priority-matching
20|order-book-imbalance
20|order-flow-imbalance
20|microprice
20|price-impact-estimation
21|twap-execution
21|vwap-execution
21|participation-of-volume
21|almgren-chriss-execution
21|order-slicing
21|transaction-cost-slippage
22|event-driven-backtesting-engine
22|position-pnl-accounting
22|walk-forward-validation
22|purged-time-series-cross-validation
22|bootstrap-strategy-evaluation
23|bond-pricing
23|yield-to-maturity
23|duration-convexity
23|yield-curve-bootstrapping
23|nelson-siegel-curve-fitting
23|vasicek-model
24|expected-credit-loss
24|credit-transition-matrix
24|kaplan-meier-survival
24|hazard-rate-estimation
24|merton-structural-credit
25|parkinson-volatility
25|garman-klass-volatility
25|yang-zhang-volatility
25|implied-volatility-surface
25|heston-stochastic-volatility
26|rolling-z-score
26|pairs-trading-spread
26|hedge-ratio-estimation
26|mean-reversion-half-life
26|cointegration-pairs-selection
27|parallel-reduction
27|parallel-prefix-sum
27|parallel-merge-sort
27|parallel-matrix-multiplication
27|parallel-monte-carlo
27|work-stealing-scheduler
28|lock-free-spsc-queue
28|lock-free-mpmc-queue
28|concurrent-ring-buffer
28|thread-pool
28|consistent-hashing
29|memory-pool-allocator
29|arena-allocator
29|cache-blocked-matrix-multiplication
29|simd-vector-summation
29|simd-dot-product
29|allocation-free-processing-pipeline
30|gpu-parallel-reduction
30|gpu-matrix-multiplication
30|gpu-monte-carlo
30|gpu-option-pricing
31|discrete-fourier-transform
31|fast-fourier-transform
31|fir-filter
31|welch-power-spectral-density
31|discrete-wavelet-transform
32|shannon-entropy
32|mutual-information
32|kullback-leibler-divergence
32|jensen-shannon-divergence
33|bayesian-linear-regression
33|metropolis-hastings
33|gibbs-sampling
33|particle-filter
34|dijkstras-algorithm
34|bellman-ford
34|minimum-cost-flow
34|currency-arbitrage-detection
35|policy-iteration
35|linear-quadratic-regulator
35|riccati-equation-solver
35|model-predictive-control
36|logistic-regression
36|ridge-lasso-regression
36|principal-component-analysis
36|k-means-clustering
36|decision-tree
36|random-forest
37|multi-armed-bandit-ucb
37|thompson-sampling
37|q-learning
37|reinforce-policy-gradient
CATALOG

# Write once; don't overwrite edits in the main summary.
[[ -e "$ROOT/summary.md" ]] || printf '# Algorithm Roadmap\n\nSee [algorithms.tsv](algorithms.tsv) for the canonical implementation registry.\n' > "$ROOT/summary.md"
[[ -e "$ROOT/docs/README.md" ]] || printf '# Documentation\n\nDocument specifications and numerical assumptions in each algorithm README.\n' > "$ROOT/docs/README.md"

# Build registry: preserve all previously listed records.  The prior generator
# used explicit numbering for the first 32, so keep existing IDs where present.
REGISTRY="$ROOT/algorithms.tsv"
touch "$REGISTRY"
# Resolve earlier names as canonical paths when they are already registered.
while IFS='|' read -r pri num label; do
  pd=$(priority_dir "$pri")
  mkdir -p "$ROOT/$pd/$pri.$num-$label"
done < "$SCOPES_FILE"

while IFS='|' read -r num slug; do
  row=$(awk -F'|' -v n="$num" '$2==n {print; exit}' "$SCOPES_FILE")
  IFS='|' read -r pri sn scope <<< "$row"
  pd=$(priority_dir "$pri")
  path="$pri.$sn-$scope"
  # Exact same slug in this scope already registered? Keep that ID.
  if awk -F'|' -v p="$pd" -v s="$path" -v suffix="-$slug" \
    '$1==p && $2==s && length($3)>=length(suffix) && substr($3,length($3)-length(suffix)+1)==suffix {found=1} END{exit !found}' "$REGISTRY"; then
    continue
  fi
  next=1
  while grep -Eq "^${pd//./\\.}\\|${path//./\\.}\\|${pri//./\\.}\\.${sn}\\.${next}-" "$REGISTRY"; do
    next=$((next+1))
  done
  printf '%s|%s|%s.%s.%s-%s\n' "$pd" "$path" "$pri" "$sn" "$next" "$slug" >> "$REGISTRY"
done < "$CATALOG_FILE"

# All shared, language-specific config lives under development/config/.
mkdir -p "$ROOT/config/nodejs" "$ROOT/config/rust/src" "$ROOT/config/c"
mkdir -p "$ROOT/template/nodejs" "$ROOT/template/rust" "$ROOT/template/c"

write_new() { local p=$1; if [[ ! -e "$p" ]]; then cat > "$p"; else cat >/dev/null; fi; }

write_new "$ROOT/config/nodejs/package.json" <<'EOF'
{
  "name": "quant-roadmap-tests",
  "private": true,
  "type": "module",
  "scripts": {
    "test": "vitest run --config vitest.config.ts",
    "coverage": "vitest run --config vitest.config.ts --coverage",
    "typecheck": "tsc --noEmit -p tsconfig.json"
  },
  "devDependencies": {
    "@types/node": "^24.0.0",
    "@vitest/coverage-v8": "^3.2.0",
    "typescript": "^5.8.0",
    "vitest": "^3.2.0"
  }
}
EOF
write_new "$ROOT/config/nodejs/tsconfig.json" <<'EOF'
{
  "compilerOptions": {
    "target": "ES2022",
    "module": "ESNext",
    "moduleResolution": "Bundler",
    "strict": true,
    "noEmit": true,
    "types": ["node", "vitest/globals"],
    "skipLibCheck": true
  },
  "include": ["../../P*/*/*/nodejs/*.ts", "*.ts", "tests/*.ts"],
  "exclude": ["node_modules", "coverage"]
}
EOF
write_new "$ROOT/config/nodejs/vitest.config.ts" <<'EOF'
import { defineConfig } from "vitest/config";
import { fileURLToPath } from "node:url";

const development = fileURLToPath(new URL("../../", import.meta.url));
export default defineConfig({
  root: development,
  test: {
    include: ["P*/*/*/nodejs/*.test.ts", "config/nodejs/tests/*.test.ts"],
    coverage: {
      provider: "v8",
      reporter: ["text", "html", "lcov"],
      reportsDirectory: "./config/nodejs/coverage",
      include: ["P*/*/*/nodejs/main.ts"],
      exclude: ["**/*.test.ts"]
    }
  }
});
EOF
mkdir -p "$ROOT/config/nodejs/tests"
write_new "$ROOT/config/nodejs/tests/smoke.test.ts" <<'EOF'
import { describe, expect, it } from "vitest";
describe("test infrastructure", () => {
  it("runs Vitest", () => expect(1 + 1).toBe(2));
});
EOF

write_new "$ROOT/config/rust/Cargo.toml" <<'EOF'
[package]
name = "quant-dev-roadmap"
version = "0.1.0"
edition = "2024"

[lib]
path = "src/lib.rs"

[dependencies]
EOF
write_new "$ROOT/config/rust/rustfmt.toml" <<'EOF'
edition = "2024"
EOF
write_new "$ROOT/config/c/.clang-format" <<'EOF'
BasedOnStyle: LLVM
IndentWidth: 4
EOF
write_new "$ROOT/config/c/Makefile" <<'EOF'
# From development/config/c run: make test, make coverage, make clean
CC = gcc
ROOT = ../..
BUILD = $(ROOT)/.build/c
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O0 -g
.PHONY: test coverage clean

test:
	@set -e; mkdir -p $(BUILD); \
	find $(ROOT)/P* -type f -path '*/c/main.test.c' | sort | while IFS= read -r testfile; do \
	  src=$$(dirname "$$testfile")/main.c; \
	  id=$$(basename $$(dirname $$(dirname "$$testfile"))); \
	  output="$(BUILD)/$$id"; \
	  $(CC) $(CFLAGS) "$$src" "$$testfile" -o "$$output"; \
	  "$$output"; \
	done

coverage:
	@set -e; mkdir -p $(BUILD); \
	find $(ROOT)/P* -type f -path '*/c/main.test.c' | sort | while IFS= read -r testfile; do \
	  src=$$(dirname "$$testfile")/main.c; \
	  id=$$(basename $$(dirname $$(dirname "$$testfile"))); \
	  output="$(BUILD)/$$id"; \
	  $(CC) $(CFLAGS) --coverage "$$src" "$$testfile" -o "$$output"; \
	  "$$output"; \
	done
	cd $(ROOT) && gcovr -r . --exclude '.*main\.test\.c$$' --html-details -o config/c/coverage.html

clean:
	rm -rf $(BUILD) $(ROOT)/config/c/coverage.html $(ROOT)/config/c/coverage.*.html
EOF

write_new "$ROOT/template/nodejs/main.ts" <<'EOF'
// Implement the mathematical algorithm here.
export {};
EOF
write_new "$ROOT/template/nodejs/main.test.ts" <<'EOF'
import { it } from "vitest";
it.todo("describe the algorithm using TDD");
EOF
write_new "$ROOT/template/rust/main.rs" <<'EOF'
// Implement the mathematical algorithm here.
EOF
write_new "$ROOT/template/rust/main_test.rs" <<'EOF'
#[test]
#[ignore = "TDD test not written yet"]
fn algorithm_test() {}
EOF
write_new "$ROOT/template/c/main.c" <<'EOF'
/* Implement the mathematical algorithm here. */
EOF
write_new "$ROOT/template/c/main.test.c" <<'EOF'
/* Replace this scaffold with real TDD assertions. */
int main(void) { return 0; }
EOF

# Create all algorithm source/test pairs. Never overwrite preexisting files.
while IFS='|' read -r pd scope algorithm; do
  [[ -n "$pd" && -n "$scope" && -n "$algorithm" ]] || continue
  dest="$ROOT/$pd/$scope/$algorithm"
  for lang in nodejs rust c; do mkdir -p "$dest/$lang"; done
  for file in main.ts main.test.ts; do
    [[ -e "$dest/nodejs/$file" ]] || cp "$ROOT/template/nodejs/$file" "$dest/nodejs/$file"
  done
  for file in main.rs main_test.rs; do
    [[ -e "$dest/rust/$file" ]] || cp "$ROOT/template/rust/$file" "$dest/rust/$file"
  done
  for file in main.c main.test.c; do
    [[ -e "$dest/c/$file" ]] || cp "$ROOT/template/c/$file" "$dest/c/$file"
  done
  if [[ ! -e "$dest/README.md" ]]; then
    printf '# %s\n\n## Mathematical specification\n\nTODO\n\n## Test cases\n\nTODO\n\n## Complexity\n\nTODO\n' "$algorithm" > "$dest/README.md"
  fi
done < "$REGISTRY"

# One Rust crate. Generate module declarations, but never overwrite a
# manually edited lib.rs; only replace when it has our generator marker.
RUST_LIB="$ROOT/config/rust/src/lib.rs"
if [[ ! -e "$RUST_LIB" ]] || grep -q '^// GENERATED BY setup-quant-development.sh$' "$RUST_LIB"; then
  temp_lib=$(mktemp)
  printf '// GENERATED BY setup-quant-development.sh\n#![allow(dead_code)]\n' > "$temp_lib"
  while IFS='|' read -r pd scope algorithm; do
    [[ -n "$pd" && -n "$scope" && -n "$algorithm" ]] || continue
    mod=${algorithm//[^a-zA-Z0-9_]/_}
    printf '\npub mod %s {\n' "$mod" >> "$temp_lib"
    printf '    include!(concat!(env!("CARGO_MANIFEST_DIR"), "/../../%s/%s/%s/rust/main.rs"));\n' "$pd" "$scope" "$algorithm" >> "$temp_lib"
    printf '    #[cfg(test)]\n    mod tests {\n        use super::*;\n' >> "$temp_lib"
    printf '        include!(concat!(env!("CARGO_MANIFEST_DIR"), "/../../%s/%s/%s/rust/main_test.rs"));\n' "$pd" "$scope" "$algorithm" >> "$temp_lib"
    printf '    }\n}\n' >> "$temp_lib"
  done < "$REGISTRY"
  mv "$temp_lib" "$RUST_LIB"
else
  echo 'WARNING: Existing Rust lib.rs is custom; not overwriting. Update module registry manually.' >&2
fi

write_new "$ROOT/.gitignore" <<'EOF'
config/nodejs/node_modules/
config/nodejs/coverage/
config/rust/target/
config/c/coverage*.html
.build/
*.gcda
*.gcno
EOF

printf '\nCreated/verified %s algorithm workspaces in %s scopes.\n' "$(awk -F'|' 'NF==3{n++}END{print n+0}' "$REGISTRY")" "$(wc -l < "$SCOPES_FILE")"
echo 'Next: inspect git status; install dependencies separately after reviewing configs.'
