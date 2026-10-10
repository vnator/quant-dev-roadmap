# Quantitative Development — Algorithm Specifications

> **Status:** initial specifications, not implemented code.
> **Source:** 237 entries from `setup-quant-development.sh` (P0–P3). Check actual directory IDs against `development/algorithms.tsv` if they have been renumbered.

## Conventions

- **Title:** identifiable algorithm name.
- **Description:** computational purpose in one sentence.
- **Mathematical definition:** core identity, recurrence, objective, or invariant; not a full proof.
- **ε / limits:** tolerance or input-domain constraints. Exact discrete algorithms have no universal epsilon.
- **Applications:** concrete quantitative-development domains.
- **Precision:** when applicable, use `abs(error) ≤ ε_abs + ε_rel · abs(reference)`. Never impose one fixed epsilon on all algorithms.
- **Notation:** `N` = sample count, `Δt` = time step, `Σ` = covariance matrix.

---

## P0.1 — Math Fundamentals

### P0.1.1 — Euclidean Algorithm

- **Description:** Computes the greatest common divisor through repeated division remainders.
- **Mathematical definition:** `a=qb+r; gcd(a,b)=gcd(b,r); 0<=r<|b|`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.2 — Binary Exponentiation

- **Description:** Implements binary exponentiation according to its defining mathematical relation.
- **Mathematical definition:** `a^n=(a^2)^{n/2} for even n; a(a^2)^{(n-1)/2} otherwise`.
- **ε / limits:** No tolerance for exact integers; for floating point specify error and overflow limits.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.3 — Modular Exponentiation

- **Description:** Implements modular exponentiation according to its defining mathematical relation.
- **Mathematical definition:** `a^n mod m; (xy) mod m=((x mod m)(y mod m)) mod m`.
- **ε / limits:** No tolerance for exact integers; for floating point specify error and overflow limits.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.4 — Factorials Binomial Coefficients

- **Description:** Implements factorials binomial coefficients according to its defining mathematical relation.
- **Mathematical definition:** `n!=prod(k=1..n)k; C(n,k)=n!/[k!(n-k)!]`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.5 — Polynomial Evaluation

- **Description:** Implements polynomial evaluation according to its defining mathematical relation.
- **Mathematical definition:** `p(x)=a_0+x(a_1+x(...+xa_n))`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.6 — Arithmetic Geometric Progressions

- **Description:** Implements arithmetic geometric progressions according to its defining mathematical relation.
- **Mathematical definition:** `AP: S_n=n(2a+(n-1)d)/2; GP: S_n=a(1-r^n)/(1-r), r!=1`.
- **ε / limits:** No tolerance for exact integers; for floating point specify error and overflow limits.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.7 — Numerical Logarithm

- **Description:** Implements numerical logarithm according to its defining mathematical relation.
- **Mathematical definition:** `Find y satisfying exp(y)=x (x>0); log_b(x)=ln(x)/ln(b)`.
- **ε / limits:** No tolerance for exact integers; for floating point specify error and overflow limits.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.8 — Divisibility Criteria

- **Description:** Implements divisibility criteria according to its defining mathematical relation.
- **Mathematical definition:** `n divisible by d iff n mod d=0; decimal digit-sum test for d=3,9`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.9 — Least Common Multiple

- **Description:** Implements least common multiple according to its defining mathematical relation.
- **Mathematical definition:** `lcm(a,b)=|a/gcd(a,b)| |b|`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.10 — Sieve Of Eratosthenes

- **Description:** Implements sieve of eratosthenes according to its defining mathematical relation.
- **Mathematical definition:** `Mark multiples kp for primes p<=sqrt(N); survivors are prime`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.11 — Integer Factorization

- **Description:** Implements integer factorization according to its defining mathematical relation.
- **Mathematical definition:** `n=prod_i p_i^{e_i}, trial divisors <=sqrt(remaining n)`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.12 — Extended Euclidean Algorithm

- **Description:** Implements extended euclidean algorithm according to its defining mathematical relation.
- **Mathematical definition:** `ax+by=gcd(a,b) (Bézout identity)`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.13 — Modular Inverse

- **Description:** Implements modular inverse according to its defining mathematical relation.
- **Mathematical definition:** `a*x congruent 1 (mod m) iff gcd(a,m)=1`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.14 — Euler Totient

- **Description:** Implements euler totient according to its defining mathematical relation.
- **Mathematical definition:** `phi(n)=n prod_{p|n}(1-1/p)`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.15 — Miller Rabin

- **Description:** Implements miller rabin according to its defining mathematical relation.
- **Mathematical definition:** `n-1=2^s d; check a^d mod n and successive squares (probabilistic)`.
- **ε / limits:** Integers n≥2; probabilistic error depends on tested bases/rounds.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.16 — Fibonacci Fast Doubling

- **Description:** Implements fibonacci fast doubling according to its defining mathematical relation.
- **Mathematical definition:** `F_{2k}=F_k(2F_{k+1}-F_k); F_{2k+1}=F_k^2+F_{k+1}^2`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.17 — Matrix Exponentiation

- **Description:** Implements matrix exponentiation according to its defining mathematical relation.
- **Mathematical definition:** `A^n via repeated squaring; recurrence v_n=A^n v_0`.
- **ε / limits:** No tolerance for exact integers; for floating point specify error and overflow limits.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.18 — Permutations With Repetition

- **Description:** Implements permutations with repetition according to its defining mathematical relation.
- **Mathematical definition:** `n! / prod_i (m_i!) for repeated-item multiplicities m_i`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.19 — Derangements

- **Description:** Implements derangements according to its defining mathematical relation.
- **Mathematical definition:** `D_0=1,D_1=0; D_n=(n-1)(D_{n-1}+D_{n-2})`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.20 — Catalan Numbers

- **Description:** Implements catalan numbers according to its defining mathematical relation.
- **Mathematical definition:** `C_n=binom(2n,n)/(n+1)`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.21 — Inclusion Exclusion

- **Description:** Implements inclusion exclusion according to its defining mathematical relation.
- **Mathematical definition:** `|union_i A_i|=sum_{empty!=S}(-1)^{|S|+1}|intersection_{i in S}A_i|`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.22 — Picks Theorem

- **Description:** Implements picks theorem according to its defining mathematical relation.
- **Mathematical definition:** `Area=I+B/2-1 for simple lattice polygon`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.23 — Shoelace Formula

- **Description:** Implements shoelace formula according to its defining mathematical relation.
- **Mathematical definition:** `Area=|sum_i (x_i y_{i+1}-x_{i+1} y_i)|/2`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.24 — Burnsides Lemma

- **Description:** Implements burnsides lemma according to its defining mathematical relation.
- **Mathematical definition:** `Number of orbits=(1/|G|)sum_{g in G}|Fix(g)|`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

### P0.1.25 — Polya Enumeration

- **Description:** Implements polya enumeration according to its defining mathematical relation.
- **Mathematical definition:** `Number of colorings up to symmetry=Z_G(k,k,...,k)`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Computational arithmetic, combinatorics and numerical primitives.

## P0.2 — Introduction to Algorithms

### P0.2.1 — Kadanes Algorithm

- **Description:** Implements kadanes algorithm according to its defining mathematical relation.
- **Mathematical definition:** `bestEnding_i=max(a_i,bestEnding_{i-1}+a_i); answer=max_i bestEnding_i`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Efficient market-data search and organization.

### P0.2.2 — Prefix Sums

- **Description:** Implements prefix sums according to its defining mathematical relation.
- **Mathematical definition:** `P_0=0; P_k=sum_{i<k}a_i; sum_[l,r)=P_r-P_l`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Efficient market-data search and organization.

### P0.2.3 — Bitset Operations

- **Description:** Implements bitset operations according to its defining mathematical relation.
- **Mathematical definition:** `Union A|B; intersection A&B; difference A&~B`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Efficient market-data search and organization.

### P0.2.4 — Binary Search

- **Description:** Processes sequences with binary search, preserving correctness invariants.
- **Mathematical definition:** `For sorted a, shrink [lo,hi) according to a[mid] compared with target`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Efficient market-data search and organization.

### P0.2.5 — Merge Sort

- **Description:** Processes sequences with merge sort, preserving correctness invariants.
- **Mathematical definition:** `Merge two sorted sequences, T(n)=2T(n/2)+O(n)`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Efficient market-data search and organization.

### P0.2.6 — Quick Sort

- **Description:** Processes sequences with quick sort, preserving correctness invariants.
- **Mathematical definition:** `Partition around pivot; T(n)=T(k)+T(n-k-1)+O(n)`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Efficient market-data search and organization.

### P0.2.7 — Heap Sort

- **Description:** Maintains the heap sort state and structural invariants.
- **Mathematical definition:** `Heapify in O(n); repeatedly extract max in O(log n)`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Efficient market-data search and organization.

### P0.2.8 — Quickselect

- **Description:** Implements quickselect according to its defining mathematical relation.
- **Mathematical definition:** `Partition around pivot and recurse only into order-statistic side`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Efficient market-data search and organization.

### P0.2.9 — Binary Heap

- **Description:** Maintains the binary heap state and structural invariants.
- **Mathematical definition:** `Heap parent index (i-1)//2; children 2i+1,2i+2`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Efficient market-data search and organization.

### P0.2.10 — Hash Table

- **Description:** Maintains the hash table state and structural invariants.
- **Mathematical definition:** `h(k) mod capacity; resolve collisions by chaining/probing`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Efficient market-data search and organization.

### P0.2.11 — Binary Search Tree

- **Description:** Maintains the binary search tree state and structural invariants.
- **Mathematical definition:** `All left subtree keys < node key < right subtree keys`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Efficient market-data search and organization.

### P0.2.12 — Red Black Tree

- **Description:** Maintains the red black tree state and structural invariants.
- **Mathematical definition:** `Balanced BST maintains color constraints and equal black height`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Efficient market-data search and organization.

## P0.3 — Dynamic Programming

### P0.3.1 — Fibonacci Dynamic Programming

- **Description:** Implements fibonacci dynamic programming according to its defining mathematical relation.
- **Mathematical definition:** `F_n=F_{n-1}+F_{n-2}; cache or bottom-up tabulate`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Sequential optimization and recurring subproblems.

### P0.3.2 — Collatz Memoization

- **Description:** Implements collatz memoization according to its defining mathematical relation.
- **Mathematical definition:** `C(n)=1+C(n/2) if even; 1+C(3n+1) if odd (n>1)`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Sequential optimization and recurring subproblems.

### P0.3.3 — Tower Of Hanoi

- **Description:** Implements tower of hanoi according to its defining mathematical relation.
- **Mathematical definition:** `T(n)=2T(n-1)+1; solve T(n)=2^n-1`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Sequential optimization and recurring subproblems.

### P0.3.4 — Pascals Triangle

- **Description:** Implements pascals triangle according to its defining mathematical relation.
- **Mathematical definition:** `C(n,k)=C(n-1,k-1)+C(n-1,k)`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Sequential optimization and recurring subproblems.

### P0.3.5 — Zero One Knapsack

- **Description:** Implements zero one knapsack according to its defining mathematical relation.
- **Mathematical definition:** `DP[i,w]=max(DP[i-1,w],v_i+DP[i-1,w-w_i]) when w_i<=w`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Sequential optimization and recurring subproblems.

### P0.3.6 — Weighted Interval Scheduling

- **Description:** Implements weighted interval scheduling according to its defining mathematical relation.
- **Mathematical definition:** `OPT(j)=max(v_j+OPT(p(j)),OPT(j-1))`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Sequential optimization and recurring subproblems.

### P0.3.7 — Matrix Chain Multiplication

- **Description:** Implements matrix chain multiplication according to its defining mathematical relation.
- **Mathematical definition:** `m[i,j]=min_{i<=k<j}(m[i,k]+m[k+1,j]+p_{i-1}p_kp_j)`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Sequential optimization and recurring subproblems.

### P0.3.8 — Bellman Value Iteration

- **Description:** Implements bellman value iteration according to its defining mathematical relation.
- **Mathematical definition:** `V_{k+1}(s)=max_a [r(s,a)+gamma sum_{s'}P(s'|s,a)V_k(s')]`.
- **ε / limits:** Exact integer result; define domain and overflow policy.
- **Applications:** Sequential optimization and recurring subproblems.

## P0.4 — Linear Algebra

### P0.4.1 — Matrix Multiplication

- **Description:** Implements matrix multiplication according to its defining mathematical relation.
- **Mathematical definition:** `C_ij=sum_k A_ik B_kj`.
- **ε / limits:** Absolute/relative tolerance and dimension limits; guard against singularity/cancellation.
- **Applications:** Matrix operations in financial models.

### P0.4.2 — Gaussian Elimination Partial Pivoting

- **Description:** Implements gaussian elimination partial pivoting according to its defining mathematical relation.
- **Mathematical definition:** `PA=LU and LUx=Pb`.
- **ε / limits:** Absolute/relative tolerance and dimension limits; guard against singularity/cancellation.
- **Applications:** Matrix operations in financial models.

### P0.4.3 — LU Decomposition

- **Description:** Implements lu decomposition according to its defining mathematical relation.
- **Mathematical definition:** `PA=LU, with L lower and U upper triangular`.
- **ε / limits:** Absolute/relative tolerance and dimension limits; guard against singularity/cancellation.
- **Applications:** Matrix operations in financial models.

### P0.4.4 — Cholesky Decomposition

- **Description:** Implements cholesky decomposition according to its defining mathematical relation.
- **Mathematical definition:** `A=LL^T for symmetric positive definite A`.
- **ε / limits:** Absolute/relative tolerance and dimension limits; guard against singularity/cancellation.
- **Applications:** Matrix operations in financial models.

### P0.4.5 — QR Decomposition

- **Description:** Implements qr decomposition according to its defining mathematical relation.
- **Mathematical definition:** `A=QR with Q^T Q=I and R upper triangular`.
- **ε / limits:** Absolute/relative tolerance and dimension limits; guard against singularity/cancellation.
- **Applications:** Matrix operations in financial models.

### P0.4.6 — Power Iteration

- **Description:** Implements power iteration according to its defining mathematical relation.
- **Mathematical definition:** `v_{k+1}=Av_k/||Av_k||; lambda approx v^TAv`.
- **ε / limits:** Absolute/relative tolerance and dimension limits; guard against singularity/cancellation.
- **Applications:** Matrix operations in financial models.

### P0.4.7 — Singular Value Decomposition

- **Description:** Implements singular value decomposition according to its defining mathematical relation.
- **Mathematical definition:** `A=U Sigma V^T`.
- **ε / limits:** Absolute/relative tolerance and dimension limits; guard against singularity/cancellation.
- **Applications:** Matrix operations in financial models.

## P0.5 — Calculus

### P0.5.1 — Numerical Differentiation

- **Description:** Implements numerical differentiation according to its defining mathematical relation.
- **Mathematical definition:** `f'(x) approx [f(x+h)-f(x-h)]/(2h)`.
- **ε / limits:** Absolute/relative tolerance and dimension limits; guard against singularity/cancellation.
- **Applications:** Sensitivities and integration in continuous models.

### P0.5.2 — Trapezoidal Rule

- **Description:** Implements trapezoidal rule according to its defining mathematical relation.
- **Mathematical definition:** `integral_a^b f dx approx h[(f(a)+f(b))/2+sum interior f(x_i)]`.
- **ε / limits:** Absolute/relative tolerance and dimension limits; guard against singularity/cancellation.
- **Applications:** Sensitivities and integration in continuous models.

### P0.5.3 — Simpsons Rule

- **Description:** Implements simpsons rule according to its defining mathematical relation.
- **Mathematical definition:** `Simpson composite: h/3[f_0+f_n+4 sum odd f_i+2 sum even f_i]`.
- **ε / limits:** Absolute/relative tolerance and dimension limits; guard against singularity/cancellation.
- **Applications:** Sensitivities and integration in continuous models.

### P0.5.4 — Partial Derivative Approximation

- **Description:** Implements partial derivative approximation according to its defining mathematical relation.
- **Mathematical definition:** `partial_i f approx [f(x+h e_i)-f(x-h e_i)]/(2h)`.
- **ε / limits:** Absolute/relative tolerance and dimension limits; guard against singularity/cancellation.
- **Applications:** Sensitivities and integration in continuous models.

### P0.5.5 — Gradient Approximation

- **Description:** Implements gradient approximation according to its defining mathematical relation.
- **Mathematical definition:** `grad f=(partial_1 f,...,partial_n f)`.
- **ε / limits:** Absolute/relative tolerance and dimension limits; guard against singularity/cancellation.
- **Applications:** Sensitivities and integration in continuous models.

### P0.5.6 — Jacobian Matrix Approximation

- **Description:** Implements jacobian matrix approximation according to its defining mathematical relation.
- **Mathematical definition:** `J_ij=partial f_i / partial x_j`.
- **ε / limits:** Absolute/relative tolerance and dimension limits; guard against singularity/cancellation.
- **Applications:** Sensitivities and integration in continuous models.

## P0.6 — Probability & Statistics

### P0.6.1 — Binomial Distribution

- **Description:** Estimates or computes binomial distribution from input data.
- **Mathematical definition:** `P(X=k)=C(n,k)p^k(1-p)^{n-k}`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Statistical inference, risk and calibration.

### P0.6.2 — Poisson Distribution

- **Description:** Estimates or computes poisson distribution from input data.
- **Mathematical definition:** `P(X=k)=exp(-lambda)lambda^k/k!`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Statistical inference, risk and calibration.

### P0.6.3 — Normal Distribution

- **Description:** Estimates or computes normal distribution from input data.
- **Mathematical definition:** `f(x)=exp(-(x-mu)^2/(2sigma^2))/(sigma sqrt(2pi))`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Statistical inference, risk and calibration.

### P0.6.4 — Exponential Distribution

- **Description:** Estimates or computes exponential distribution from input data.
- **Mathematical definition:** `f(x)=lambda exp(-lambda x), x>=0`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Statistical inference, risk and calibration.

### P0.6.5 — Student T Distribution

- **Description:** Estimates or computes student t distribution from input data.
- **Mathematical definition:** `f(x)=Gamma((nu+1)/2)/[sqrt(nu pi)Gamma(nu/2)]*(1+x^2/nu)^(-(nu+1)/2)`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Statistical inference, risk and calibration.

### P0.6.6 — Cumulative Distribution Function

- **Description:** Estimates or computes cumulative distribution function from input data.
- **Mathematical definition:** `F(x)=P(X<=x)=integral_-inf^x f(t)dt`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Statistical inference, risk and calibration.

### P0.6.7 — Inverse CDF Quantile

- **Description:** Implements inverse cdf quantile according to its defining mathematical relation.
- **Mathematical definition:** `Q(p)=inf{x:F(x)>=p}, 0<=p<=1`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Statistical inference, risk and calibration.

### P0.6.8 — Welford Mean Variance

- **Description:** Estimates or computes welford mean variance from input data.
- **Mathematical definition:** `n_new=n+1; delta=x-mean; mean+=delta/n_new; M2+=delta*(x-mean)`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Statistical inference, risk and calibration.

### P0.6.9 — Covariance Correlation

- **Description:** Estimates or computes covariance correlation from input data.
- **Mathematical definition:** `cov(X,Y)=E[(X-EX)(Y-EY)]; rho=cov/(sigma_X sigma_Y)`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Statistical inference, risk and calibration.

### P0.6.10 — Bayesian Updating

- **Description:** Implements bayesian updating according to its defining mathematical relation.
- **Mathematical definition:** `posterior(theta|data) proportional likelihood(data|theta)*prior(theta)`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Statistical inference, risk and calibration.

### P0.6.11 — Maximum Likelihood Estimation

- **Description:** Estimates or computes maximum likelihood estimation from input data.
- **Mathematical definition:** `theta_hat=argmax_theta sum_i log p(x_i|theta)`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Statistical inference, risk and calibration.

### P0.6.12 — Student T Test

- **Description:** Estimates or computes student t test from input data.
- **Mathematical definition:** `t=(sample_mean-mu0)/(s/sqrt(n))`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Statistical inference, risk and calibration.

## P1.7 — Numerical Methods

### P1.7.1 — Bisection Method

- **Description:** Solves bisection method with an explicit stopping criterion.
- **Mathematical definition:** `If f(a)f(b)<=0, m=(a+b)/2; retain sign-changing half interval`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Equation solving and integration for pricing.

### P1.7.2 — Newton Raphson Method

- **Description:** Solves newton raphson method with an explicit stopping criterion.
- **Mathematical definition:** `x_{k+1}=x_k-f(x_k)/f'(x_k)`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Equation solving and integration for pricing.

### P1.7.3 — Brents Method

- **Description:** Solves brents method with an explicit stopping criterion.
- **Mathematical definition:** `Bracket-preserving hybrid of bisection, secant, inverse quadratic interpolation`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Equation solving and integration for pricing.

### P1.7.4 — Cubic Spline Interpolation

- **Description:** Implements cubic spline interpolation according to its defining mathematical relation.
- **Mathematical definition:** `Piecewise cubic S_i(x) with S,S',S'' continuous at knots`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Equation solving and integration for pricing.

### P1.7.5 — Gaussian Quadrature

- **Description:** Implements gaussian quadrature according to its defining mathematical relation.
- **Mathematical definition:** `integral_a^b f dx approx sum_i w_i f(x_i)`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Equation solving and integration for pricing.

### P1.7.6 — Adaptive Simpson Integration

- **Description:** Implements adaptive simpson integration according to its defining mathematical relation.
- **Mathematical definition:** `Recursively split interval until |S_left+S_right-S_whole|/15<=eps`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Equation solving and integration for pricing.

## P1.8 — Numerical Linear Algebra

### P1.8.1 — Conjugate Gradient Solver

- **Description:** Solves conjugate gradient solver with an explicit stopping criterion.
- **Mathematical definition:** `For SPD A, minimize (1/2)x^TAx-b^Tx via conjugate directions`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Large linear systems and calibration decompositions.

### P1.8.2 — GMRES

- **Description:** Implements gmres according to its defining mathematical relation.
- **Mathematical definition:** `Minimize ||beta e1 - H_m y||_2 in a Krylov subspace`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Large linear systems and calibration decompositions.

### P1.8.3 — QR Eigenvalue Algorithm

- **Description:** Implements qr eigenvalue algorithm according to its defining mathematical relation.
- **Mathematical definition:** `A_{k+1}=R_k Q_k from QR(A_k); converge toward Schur form`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Large linear systems and calibration decompositions.

### P1.8.4 — Sparse Matrix Vector CSR

- **Description:** Implements sparse matrix vector csr according to its defining mathematical relation.
- **Mathematical definition:** `y_i=sum_{j=rowptr[i]}^{rowptr[i+1]-1} val_j*x_col[j]`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Large linear systems and calibration decompositions.

## P1.9 — Numerical Optimization

### P1.9.1 — Gradient Descent

- **Description:** Solves gradient descent with an explicit stopping criterion.
- **Mathematical definition:** `x_{k+1}=x_k-alpha_k grad f(x_k)`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Parameter calibration and optimal allocation.

### P1.9.2 — Newton Optimization

- **Description:** Solves newton optimization with an explicit stopping criterion.
- **Mathematical definition:** `x_{k+1}=x_k-[H_f(x_k)]^{-1}grad f(x_k)`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Parameter calibration and optimal allocation.

### P1.9.3 — BFGS

- **Description:** Solves bfgs with an explicit stopping criterion.
- **Mathematical definition:** `p_k=-H_k grad f(x_k); update inverse-Hessian approximation by rank-2 BFGS`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Parameter calibration and optimal allocation.

### P1.9.4 — Projected Gradient Descent

- **Description:** Solves projected gradient descent with an explicit stopping criterion.
- **Mathematical definition:** `x_{k+1}=Projection_C(x_k-alpha grad f(x_k))`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Parameter calibration and optimal allocation.

### P1.9.5 — Quadratic Programming Solver

- **Description:** Solves quadratic programming solver with an explicit stopping criterion.
- **Mathematical definition:** `min (1/2)x^TQx+c^Tx subject to Ax<=b, Ex=d`.
- **ε / limits:** Absolute/relative tolerance; iteration cap; check convergence and conditioning.
- **Applications:** Parameter calibration and optimal allocation.

## P1.10 — Monte Carlo Simulation

### P1.10.1 — Xoshiro PRNG

- **Description:** Implements xoshiro prng according to its defining mathematical relation.
- **Mathematical definition:** `Deterministic fixed-width state recurrence generating pseudorandom bits`.
- **ε / limits:** N samples and reproducible seed; sampling error typically scales as 1/√N.
- **Applications:** Stochastic pricing and risk estimation.

### P1.10.2 — Inverse Transform Sampling

- **Description:** Implements inverse transform sampling according to its defining mathematical relation.
- **Mathematical definition:** `X=F^{-1}(U), U~Uniform(0,1)`.
- **ε / limits:** N samples and reproducible seed; sampling error typically scales as 1/√N.
- **Applications:** Stochastic pricing and risk estimation.

### P1.10.3 — Box Muller Transform

- **Description:** Implements box muller transform according to its defining mathematical relation.
- **Mathematical definition:** `Z=sqrt(-2 ln U1)cos(2pi U2), U_i~Uniform(0,1)`.
- **ε / limits:** N samples and reproducible seed; sampling error typically scales as 1/√N.
- **Applications:** Stochastic pricing and risk estimation.

### P1.10.4 — Monte Carlo Integration

- **Description:** Simulates monte carlo integration under specified assumptions and parameters.
- **Mathematical definition:** `I_hat=(1/N)sum_i f(U_i), U_i sampled on domain`.
- **ε / limits:** N samples and reproducible seed; sampling error typically scales as 1/√N.
- **Applications:** Stochastic pricing and risk estimation.

### P1.10.5 — Importance Sampling

- **Description:** Implements importance sampling according to its defining mathematical relation.
- **Mathematical definition:** `E_p[f(X)]=E_q[f(X)p(X)/q(X)]`.
- **ε / limits:** N samples and reproducible seed; sampling error typically scales as 1/√N.
- **Applications:** Stochastic pricing and risk estimation.

### P1.10.6 — Antithetic Variates

- **Description:** Implements antithetic variates according to its defining mathematical relation.
- **Mathematical definition:** `Use coupled U and 1-U; average two estimates`.
- **ε / limits:** N samples and reproducible seed; sampling error typically scales as 1/√N.
- **Applications:** Stochastic pricing and risk estimation.

### P1.10.7 — Control Variates

- **Description:** Implements control variates according to its defining mathematical relation.
- **Mathematical definition:** `Estimate E[f(X)-beta(g(X)-E[g(X)])]`.
- **ε / limits:** N samples and reproducible seed; sampling error typically scales as 1/√N.
- **Applications:** Stochastic pricing and risk estimation.

### P1.10.8 — Sobol Sequence

- **Description:** Implements sobol sequence according to its defining mathematical relation.
- **Mathematical definition:** `Use low-discrepancy points u_i to approximate integral by mean f(u_i)`.
- **ε / limits:** N samples and reproducible seed; sampling error typically scales as 1/√N.
- **Applications:** Stochastic pricing and risk estimation.

## P1.11 — Stochastic Processes

### P1.11.1 — Random Walk

- **Description:** Simulates random walk under specified assumptions and parameters.
- **Mathematical definition:** `X_n=X_0+sum_{k=1}^n xi_k`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** Random evolution of prices, events and rates.

### P1.11.2 — Markov Chain Simulation

- **Description:** Simulates markov chain simulation under specified assumptions and parameters.
- **Mathematical definition:** `P(X_{t+1}=j|X_t=i)=P_ij`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** Random evolution of prices, events and rates.

### P1.11.3 — Markov Stationary Distribution

- **Description:** Estimates or computes markov stationary distribution from input data.
- **Mathematical definition:** `pi P=pi and sum_i pi_i=1`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** Random evolution of prices, events and rates.

### P1.11.4 — Poisson Process Simulation

- **Description:** Simulates poisson process simulation under specified assumptions and parameters.
- **Mathematical definition:** `N(t+delta)-N(t)~Poisson(lambda delta)`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** Random evolution of prices, events and rates.

### P1.11.5 — Brownian Motion Simulation

- **Description:** Simulates brownian motion simulation under specified assumptions and parameters.
- **Mathematical definition:** `W_{t+delta}=W_t+sqrt(delta)Z, Z~N(0,1)`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** Random evolution of prices, events and rates.

### P1.11.6 — Ornstein Uhlenbeck Process

- **Description:** Simulates ornstein uhlenbeck process under specified assumptions and parameters.
- **Mathematical definition:** `dX_t=kappa(theta-X_t)dt+sigma dW_t`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** Random evolution of prices, events and rates.

## P1.12 — Time Series Analysis

### P1.12.1 — Simple Moving Average

- **Description:** Implements simple moving average according to its defining mathematical relation.
- **Mathematical definition:** `SMA_t=(1/n)sum_{i=0}^{n-1}x_{t-i}`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Volatility, filtering and returns series.

### P1.12.2 — Exponential Moving Average

- **Description:** Implements exponential moving average according to its defining mathematical relation.
- **Mathematical definition:** `EMA_t=alpha x_t+(1-alpha)EMA_{t-1}, 0<alpha<=1`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Volatility, filtering and returns series.

### P1.12.3 — Autocorrelation Function

- **Description:** Estimates or computes autocorrelation function from input data.
- **Mathematical definition:** `rho(k)=Cov(X_t,X_{t-k})/Var(X_t)`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Volatility, filtering and returns series.

### P1.12.4 — Autoregressive Model

- **Description:** Implements autoregressive model according to its defining mathematical relation.
- **Mathematical definition:** `X_t=c+sum_{i=1}^p phi_i X_{t-i}+eps_t`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Volatility, filtering and returns series.

### P1.12.5 — ARIMA Model

- **Description:** Implements arima model according to its defining mathematical relation.
- **Mathematical definition:** `phi(B)(1-B)^d X_t=theta(B)eps_t`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Volatility, filtering and returns series.

### P1.12.6 — GARCH 1 1

- **Description:** Implements garch 1 1 according to its defining mathematical relation.
- **Mathematical definition:** `sigma_t^2=omega+alpha eps_{t-1}^2+beta sigma_{t-1}^2`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Volatility, filtering and returns series.

### P1.12.7 — Kalman Filter

- **Description:** Implements kalman filter according to its defining mathematical relation.
- **Mathematical definition:** `Prediction x_hat=F x; update K=P H^T(H P H^T+R)^-1`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Volatility, filtering and returns series.

### P1.12.8 — Augmented Dickey Fuller Test

- **Description:** Estimates or computes augmented dickey fuller test from input data.
- **Mathematical definition:** `Delta y_t=alpha+gamma y_{t-1}+sum_i beta_i Delta y_{t-i}+eps_t`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Volatility, filtering and returns series.

## P1.13 — Econometrics

### P1.13.1 — Ordinary Least Squares

- **Description:** Implements ordinary least squares according to its defining mathematical relation.
- **Mathematical definition:** `beta_hat=argmin_beta ||y-X beta||_2^2`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Estimation and testing of asset relationships.

### P1.13.2 — Weighted Least Squares

- **Description:** Implements weighted least squares according to its defining mathematical relation.
- **Mathematical definition:** `beta_hat=argmin_beta (y-Xbeta)^T W(y-Xbeta), W positive definite`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Estimation and testing of asset relationships.

### P1.13.3 — Newey West Standard Errors

- **Description:** Implements newey west standard errors according to its defining mathematical relation.
- **Mathematical definition:** `Var(beta_hat) using HAC sum of lagged residual covariance terms`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Estimation and testing of asset relationships.

### P1.13.4 — Engle Granger Cointegration

- **Description:** Implements engle granger cointegration according to its defining mathematical relation.
- **Mathematical definition:** `Regress y_t on x_t, then test residuals for a unit root`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Estimation and testing of asset relationships.

### P1.13.5 — Vector Autoregression

- **Description:** Implements vector autoregression according to its defining mathematical relation.
- **Mathematical definition:** `Y_t=c+sum_{i=1}^p A_i Y_{t-i}+eps_t`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Estimation and testing of asset relationships.

## P1.14 — Stochastic Calculus

### P1.14.1 — ITO Integral Approximation

- **Description:** Implements ito integral approximation according to its defining mathematical relation.
- **Mathematical definition:** `integral_0^T H_t dW_t approx sum_k H(t_k)(W_{k+1}-W_k)`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** Price modeling using stochastic equations.

### P1.14.2 — Euler Maruyama

- **Description:** Implements euler maruyama according to its defining mathematical relation.
- **Mathematical definition:** `X_{k+1}=X_k+a(X_k,t_k)h+b(X_k,t_k)Delta W_k`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** Price modeling using stochastic equations.

### P1.14.3 — Milstein Method

- **Description:** Solves milstein method with an explicit stopping criterion.
- **Mathematical definition:** `Euler-Maruyama + (1/2)b b_x[(Delta W)^2-h]`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** Price modeling using stochastic equations.

### P1.14.4 — Geometric Brownian Motion SDE

- **Description:** Simulates geometric brownian motion sde under specified assumptions and parameters.
- **Mathematical definition:** `dS_t=mu S_t dt+sigma S_t dW_t`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** Price modeling using stochastic equations.

### P1.14.5 — Cox Ingersoll Ross SDE

- **Description:** Simulates cox ingersoll ross sde under specified assumptions and parameters.
- **Mathematical definition:** `dr_t=kappa(theta-r_t)dt+sigma sqrt(max(r_t,0))dW_t`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** Price modeling using stochastic equations.

## P1.15 — Differential Equations

### P1.15.1 — Euler Method

- **Description:** Solves euler method with an explicit stopping criterion.
- **Mathematical definition:** `y_{n+1}=y_n+h f(t_n,y_n)`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** System simulation and pricing PDEs.

### P1.15.2 — Runge Kutta Fourth Order

- **Description:** Implements runge kutta fourth order according to its defining mathematical relation.
- **Mathematical definition:** `y_{n+1}=y_n+(h/6)(k1+2k2+2k3+k4)`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** System simulation and pricing PDEs.

### P1.15.3 — Adaptive Runge Kutta

- **Description:** Implements adaptive runge kutta according to its defining mathematical relation.
- **Mathematical definition:** `Adapt step h using embedded Runge-Kutta local truncation error`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** System simulation and pricing PDEs.

### P1.15.4 — Finite Difference Method

- **Description:** Solves finite difference method with an explicit stopping criterion.
- **Mathematical definition:** `partial_xx u approx (u_{i+1}-2u_i+u_{i-1})/h^2`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** System simulation and pricing PDEs.

### P1.15.5 — Crank Nicolson

- **Description:** Implements crank nicolson according to its defining mathematical relation.
- **Mathematical definition:** `Crank-Nicolson: (I-dt L/2)u^{n+1}=(I+dt L/2)u^n`.
- **ε / limits:** Step Δt>0, horizon T, discretization tolerance and stability constraints.
- **Applications:** System simulation and pricing PDEs.

## P2.16 — Quantitative Algorithms

### P2.16.1 — Simple Log Returns

- **Description:** Computes simple log returns under explicit financial conventions.
- **Mathematical definition:** `Simple r_t=P_t/P_{t-1}-1; log r_t=ln(P_t/P_{t-1})`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Financial return and risk metrics.

### P2.16.2 — Historical Volatility

- **Description:** Estimates or computes historical volatility from input data.
- **Mathematical definition:** `sigma_hat=sqrt(sum_i(r_i-mean r)^2/(n-1))`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Financial return and risk metrics.

### P2.16.3 — Realized Volatility

- **Description:** Estimates or computes realized volatility from input data.
- **Mathematical definition:** `RV=sum_{i=1}^n (Delta log P_i)^2`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Financial return and risk metrics.

### P2.16.4 — Rolling Covariance Matrix

- **Description:** Estimates or computes rolling covariance matrix from input data.
- **Mathematical definition:** `Sigma_t=(1/(w-1))sum_i(r_i-rbar)(r_i-rbar)^T`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Financial return and risk metrics.

### P2.16.5 — Exponentially Weighted Covariance

- **Description:** Estimates or computes exponentially weighted covariance from input data.
- **Mathematical definition:** `Sigma_t=lambda Sigma_{t-1}+(1-lambda)r_t r_t^T (zero-mean convention)`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Financial return and risk metrics.

### P2.16.6 — Maximum Drawdown

- **Description:** Computes maximum drawdown under explicit financial conventions.
- **Mathematical definition:** `D_t=1-V_t/max_{s<=t}V_s; MDD=max_t D_t`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Financial return and risk metrics.

### P2.16.7 — Sharpe Ratio

- **Description:** Computes sharpe ratio under explicit financial conventions.
- **Mathematical definition:** `Sharpe=(mean r-r_f)/sigma_r`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Financial return and risk metrics.

## P2.17 — Derivatives Pricing

### P2.17.1 — Cox Ross Rubinstein Binomial Tree

- **Description:** Maintains the cox ross rubinstein binomial tree state and structural invariants.
- **Mathematical definition:** `C=e^{-rT}[p C_up+(1-p)C_down]; p=(e^{r dt}-d)/(u-d)`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Derivatives valuation and sensitivities.

### P2.17.2 — Black Scholes Merton

- **Description:** Implements black scholes merton according to its defining mathematical relation.
- **Mathematical definition:** `C=S0 N(d1)-K exp(-rT)N(d2)`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Derivatives valuation and sensitivities.

### P2.17.3 — Black Scholes Greeks

- **Description:** Implements black scholes greeks according to its defining mathematical relation.
- **Mathematical definition:** `Delta=partial V/partial S, Gamma=partial^2 V/partial S^2, Vega=partial V/partial sigma`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Derivatives valuation and sensitivities.

### P2.17.4 — Implied Volatility Solver

- **Description:** Solves implied volatility solver with an explicit stopping criterion.
- **Mathematical definition:** `Find sigma>0 such that BS_price(sigma)-market_price=0`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Derivatives valuation and sensitivities.

### P2.17.5 — American Option Pricing

- **Description:** Computes american option pricing under explicit financial conventions.
- **Mathematical definition:** `American: V=max(intrinsic, discounted continuation)`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Derivatives valuation and sensitivities.

### P2.17.6 — Monte Carlo Option Pricing

- **Description:** Simulates monte carlo option pricing under specified assumptions and parameters.
- **Mathematical definition:** `V_hat=e^{-rT}(1/N)sum_i payoff(S_T^i)`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Derivatives valuation and sensitivities.

### P2.17.7 — Finite Difference Option Pricing

- **Description:** Computes finite difference option pricing under explicit financial conventions.
- **Mathematical definition:** `Black-Scholes PDE: V_t+(sigma^2 S^2/2)V_SS+rS V_S-rV=0`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Derivatives valuation and sensitivities.

## P2.18 — Portfolio Optimization

### P2.18.1 — Minimum Variance Portfolio

- **Description:** Estimates or computes minimum variance portfolio from input data.
- **Mathematical definition:** `min_w w^T Sigma w subject to 1^T w=1`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Portfolio construction and allocation constraints.

### P2.18.2 — Markowitz Mean Variance

- **Description:** Estimates or computes markowitz mean variance from input data.
- **Mathematical definition:** `max_w [mu^T w-(lambda/2)w^T Sigma w] with constraints`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Portfolio construction and allocation constraints.

### P2.18.3 — Efficient Frontier

- **Description:** Implements efficient frontier according to its defining mathematical relation.
- **Mathematical definition:** `For risk target v, minimize w^T Sigma w subject to mu^T w>=v`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Portfolio construction and allocation constraints.

### P2.18.4 — Maximum Sharpe Portfolio

- **Description:** Computes maximum sharpe portfolio under explicit financial conventions.
- **Mathematical definition:** `max_w (mu^T w-r_f)/sqrt(w^T Sigma w)`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Portfolio construction and allocation constraints.

### P2.18.5 — Risk Parity Portfolio

- **Description:** Computes risk parity portfolio under explicit financial conventions.
- **Mathematical definition:** `Risk contribution RC_i=w_i(Sigma w)_i/sqrt(w^T Sigma w); target equal RC_i`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Portfolio construction and allocation constraints.

### P2.18.6 — Transaction Cost Portfolio Optimization

- **Description:** Solves transaction cost portfolio optimization with an explicit stopping criterion.
- **Mathematical definition:** `min_w risk(w)+lambda sum_i cost_i|w_i-w_i_old|`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Portfolio construction and allocation constraints.

## P2.19 — Financial Risk

### P2.19.1 — Historical Value At Risk

- **Description:** Computes historical value at risk under explicit financial conventions.
- **Mathematical definition:** `VaR_alpha=-empirical_quantile(PnL,1-alpha)`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Loss measurement and stress testing.

### P2.19.2 — Parametric Value At Risk

- **Description:** Computes parametric value at risk under explicit financial conventions.
- **Mathematical definition:** `VaR_alpha=-[mu+sigma Phi^-1(1-alpha)] for normal PnL`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Loss measurement and stress testing.

### P2.19.3 — Expected Shortfall

- **Description:** Implements expected shortfall according to its defining mathematical relation.
- **Mathematical definition:** `ES_alpha=-E[PnL|PnL<=-VaR_alpha]`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Loss measurement and stress testing.

### P2.19.4 — Portfolio Stress Testing

- **Description:** Estimates or computes portfolio stress testing from input data.
- **Mathematical definition:** `Scenario value V_s=f(positions, shocks_s); loss_s=V_base-V_s`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Loss measurement and stress testing.

## P2.20 — Market Microstructure

### P2.20.1 — Limit Order Book

- **Description:** Implements limit order book according to its defining mathematical relation.
- **Mathematical definition:** `Maintain ordered bid/ask price levels and FIFO queues at each price`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Order books, liquidity and order flow.

### P2.20.2 — Order Book Reconstruction

- **Description:** Implements order book reconstruction according to its defining mathematical relation.
- **Mathematical definition:** `Apply ordered add/modify/cancel/trade events to book state`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Order books, liquidity and order flow.

### P2.20.3 — Price Time Priority Matching

- **Description:** Computes price time priority matching under explicit financial conventions.
- **Mathematical definition:** `Match best price, then earliest order timestamp within price level`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Order books, liquidity and order flow.

### P2.20.4 — Order Book Imbalance

- **Description:** Implements order book imbalance according to its defining mathematical relation.
- **Mathematical definition:** `Imbalance=(Q_bid-Q_ask)/(Q_bid+Q_ask)`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Order books, liquidity and order flow.

### P2.20.5 — Order Flow Imbalance

- **Description:** Implements order flow imbalance according to its defining mathematical relation.
- **Mathematical definition:** `OFI=sum signed change of volume at best bid/ask levels`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Order books, liquidity and order flow.

### P2.20.6 — Microprice

- **Description:** Computes microprice under explicit financial conventions.
- **Mathematical definition:** `Microprice=(ask*Q_bid+bid*Q_ask)/(Q_bid+Q_ask)`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Order books, liquidity and order flow.

### P2.20.7 — Price Impact Estimation

- **Description:** Estimates or computes price impact estimation from input data.
- **Mathematical definition:** `Impact(q,tau)=E[P_{t+tau}-P_t|signed trade size=q]`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Order books, liquidity and order flow.

## P2.21 — Algorithmic Execution

### P2.21.1 — TWAP Execution

- **Description:** Implements twap execution according to its defining mathematical relation.
- **Mathematical definition:** `Slice total Q into equal time-bucket quantities q_i, sum_i q_i=Q`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Algorithmic execution and trading costs.

### P2.21.2 — VWAP Execution

- **Description:** Implements vwap execution according to its defining mathematical relation.
- **Mathematical definition:** `Allocate q_i proportional to estimated volume profile v_i`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Algorithmic execution and trading costs.

### P2.21.3 — Participation Of Volume

- **Description:** Implements participation of volume according to its defining mathematical relation.
- **Mathematical definition:** `Execute q_t=rho*market_volume_t, 0<=rho<=1`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Algorithmic execution and trading costs.

### P2.21.4 — Almgren Chriss Execution

- **Description:** Implements almgren chriss execution according to its defining mathematical relation.
- **Mathematical definition:** `minimize expected impact cost + lambda*execution risk over schedule q_t`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Algorithmic execution and trading costs.

### P2.21.5 — Order Slicing

- **Description:** Implements order slicing according to its defining mathematical relation.
- **Mathematical definition:** `Partition parent Q into children q_i>0 with sum q_i=Q`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Algorithmic execution and trading costs.

### P2.21.6 — Transaction Cost Slippage

- **Description:** Implements transaction cost slippage according to its defining mathematical relation.
- **Mathematical definition:** `Slippage=(execution_price-reference_price)*signed_quantity`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Algorithmic execution and trading costs.

## P2.22 — Backtesting

### P2.22.1 — Event Driven Backtesting Engine

- **Description:** Estimates or computes event driven backtesting engine from input data.
- **Mathematical definition:** `State_{t+1}=transition(State_t,event_t), deterministic event ordering`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Temporal strategy validation and P&L.

### P2.22.2 — Position PNL Accounting

- **Description:** Implements position pnl accounting according to its defining mathematical relation.
- **Mathematical definition:** `PnL_t=equity_t-equity_{t-1}; equity=cash+sum_i position_i*price_i`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Temporal strategy validation and P&L.

### P2.22.3 — Walk Forward Validation

- **Description:** Implements walk forward validation according to its defining mathematical relation.
- **Mathematical definition:** `Train on [t0,t1], test on (t1,t2]; roll forward`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Temporal strategy validation and P&L.

### P2.22.4 — Purged Time Series Cross Validation

- **Description:** Implements purged time series cross validation according to its defining mathematical relation.
- **Mathematical definition:** `Exclude train samples with information intervals overlapping validation window`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Temporal strategy validation and P&L.

### P2.22.5 — Bootstrap Strategy Evaluation

- **Description:** Implements bootstrap strategy evaluation according to its defining mathematical relation.
- **Mathematical definition:** `Bootstrap strategy statistic from resampled returns/blocks`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Temporal strategy validation and P&L.

## P2.23 — Fixed Income

### P2.23.1 — Bond Pricing

- **Description:** Computes bond pricing under explicit financial conventions.
- **Mathematical definition:** `Bond price=sum_t CF_t*(1+r_t)^(-t) (convention-dependent)`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Bond pricing and yield curves.

### P2.23.2 — Yield To Maturity

- **Description:** Implements yield to maturity according to its defining mathematical relation.
- **Mathematical definition:** `Find y with P=sum_t CF_t/(1+y/m)^{mt}`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Bond pricing and yield curves.

### P2.23.3 — Duration Convexity

- **Description:** Implements duration convexity according to its defining mathematical relation.
- **Mathematical definition:** `Duration_Mac=sum_t t*PV(CF_t)/P; convexity from price second derivative`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Bond pricing and yield curves.

### P2.23.4 — Yield Curve Bootstrapping

- **Description:** Implements yield curve bootstrapping according to its defining mathematical relation.
- **Mathematical definition:** `Solve discount factors D(t_i) sequentially from instrument prices`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Bond pricing and yield curves.

### P2.23.5 — Nelson Siegel Curve Fitting

- **Description:** Implements nelson siegel curve fitting according to its defining mathematical relation.
- **Mathematical definition:** `Yield y(t)=beta0+beta1((1-e^-x)/x)+beta2(((1-e^-x)/x)-e^-x), x=t/tau`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Bond pricing and yield curves.

### P2.23.6 — Vasicek Model

- **Description:** Implements vasicek model according to its defining mathematical relation.
- **Mathematical definition:** `dr_t=kappa(theta-r_t)dt+sigma dW_t`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Bond pricing and yield curves.

## P2.24 — Credit Risk

### P2.24.1 — Expected Credit Loss

- **Description:** Implements expected credit loss according to its defining mathematical relation.
- **Mathematical definition:** `ECL=PD*LGD*EAD (simplified, one horizon)`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Default and credit-loss estimation.

### P2.24.2 — Credit Transition Matrix

- **Description:** Implements credit transition matrix according to its defining mathematical relation.
- **Mathematical definition:** `(P^n)_{ij}=Pr(rating at t+n=j|rating at t=i)`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Default and credit-loss estimation.

### P2.24.3 — Kaplan Meier Survival

- **Description:** Implements kaplan meier survival according to its defining mathematical relation.
- **Mathematical definition:** `S_hat(t)=prod_{t_i<=t}(1-d_i/n_i)`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Default and credit-loss estimation.

### P2.24.4 — Hazard Rate Estimation

- **Description:** Estimates or computes hazard rate estimation from input data.
- **Mathematical definition:** `h(t)=lim_{dt->0}Pr(t<=T<t+dt|T>=t)/dt`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Default and credit-loss estimation.

### P2.24.5 — Merton Structural Credit

- **Description:** Implements merton structural credit according to its defining mathematical relation.
- **Mathematical definition:** `DD=[ln(V_A/D)+(r_A-sigma_A^2/2)T]/(sigma_A sqrt(T))`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Default and credit-loss estimation.

## P2.25 — Volatility Modeling

### P2.25.1 — Parkinson Volatility

- **Description:** Estimates or computes parkinson volatility from input data.
- **Mathematical definition:** `sigma_P^2=[1/(4n ln 2)]sum_i ln(H_i/L_i)^2`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Volatility measurement and calibration.

### P2.25.2 — Garman Klass Volatility

- **Description:** Estimates or computes garman klass volatility from input data.
- **Mathematical definition:** `sigma_GK^2=(1/n)sum_i[0.5 ln(H/L)^2-(2ln2-1)ln(C/O)^2]`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Volatility measurement and calibration.

### P2.25.3 — Yang Zhang Volatility

- **Description:** Estimates or computes yang zhang volatility from input data.
- **Mathematical definition:** `Yang-Zhang variance combines overnight, open-close and Rogers-Satchell components`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Volatility measurement and calibration.

### P2.25.4 — Implied Volatility Surface

- **Description:** Estimates or computes implied volatility surface from input data.
- **Mathematical definition:** `Interpolate sigma_imp(K,T) across observed strikes and maturities under chosen constraints`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Volatility measurement and calibration.

### P2.25.5 — Heston Stochastic Volatility

- **Description:** Estimates or computes heston stochastic volatility from input data.
- **Mathematical definition:** `dS=mu Sdt+sqrt(v)S dW1; dv=kappa(theta-v)dt+xi sqrt(v)dW2`.
- **ε / limits:** Valid financial inputs, explicit conventions and pricing/calibration tolerances.
- **Applications:** Volatility measurement and calibration.

## P2.26 — Statistical Arbitrage

### P2.26.1 — Rolling Z Score

- **Description:** Implements rolling z score according to its defining mathematical relation.
- **Mathematical definition:** `z_t=(spread_t-rolling_mean)/rolling_std`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Relative-value strategies and mean reversion.

### P2.26.2 — Pairs Trading Spread

- **Description:** Computes pairs trading spread under explicit financial conventions.
- **Mathematical definition:** `spread_t=price_A,t-beta*price_B,t`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Relative-value strategies and mean reversion.

### P2.26.3 — Hedge Ratio Estimation

- **Description:** Estimates or computes hedge ratio estimation from input data.
- **Mathematical definition:** `beta_hat=argmin_beta sum_t(y_t-alpha-beta x_t)^2`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Relative-value strategies and mean reversion.

### P2.26.4 — Mean Reversion Half Life

- **Description:** Implements mean reversion half life according to its defining mathematical relation.
- **Mathematical definition:** `OU half-life=ln(2)/kappa for fitted kappa>0`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Relative-value strategies and mean reversion.

### P2.26.5 — Cointegration Pairs Selection

- **Description:** Processes sequences with cointegration pairs selection, preserving correctness invariants.
- **Mathematical definition:** `Choose pairs whose residual spread rejects unit-root null (with validation)`.
- **ε / limits:** Require adequate sample/window size; handle near-zero variance and missing data.
- **Applications:** Relative-value strategies and mean reversion.

## P3.27 — Parallel Programming

### P3.27.1 — Parallel Reduction

- **Description:** Implements parallel reduction according to its defining mathematical relation.
- **Mathematical definition:** `sum_i x_i computed as tree reduction, O(log n) depth`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Multicore acceleration of quantitative calculations.

### P3.27.2 — Parallel Prefix Sum

- **Description:** Implements parallel prefix sum according to its defining mathematical relation.
- **Mathematical definition:** `prefix_i=sum_{j<=i}x_j with associative scan operator`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Multicore acceleration of quantitative calculations.

### P3.27.3 — Parallel Merge Sort

- **Description:** Processes sequences with parallel merge sort, preserving correctness invariants.
- **Mathematical definition:** `Divide array; sort subarrays in parallel; merge`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Multicore acceleration of quantitative calculations.

### P3.27.4 — Parallel Matrix Multiplication

- **Description:** Implements parallel matrix multiplication according to its defining mathematical relation.
- **Mathematical definition:** `C_ij=sum_k A_ik B_kj over independently scheduled blocks`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Multicore acceleration of quantitative calculations.

### P3.27.5 — Parallel Monte Carlo

- **Description:** Simulates parallel monte carlo under specified assumptions and parameters.
- **Mathematical definition:** `Compute independent Monte Carlo paths on workers; aggregate estimates`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Multicore acceleration of quantitative calculations.

### P3.27.6 — Work Stealing Scheduler

- **Description:** Maintains the work stealing scheduler state and structural invariants.
- **Mathematical definition:** `Tasks deque; idle worker steals ready tasks from other queues`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Multicore acceleration of quantitative calculations.

## P3.28 — Concurrent & Distributed Algorithms

### P3.28.1 — Lock Free SPSC Queue

- **Description:** Maintains the lock free spsc queue state and structural invariants.
- **Mathematical definition:** `SPSC queue uses atomic head/tail; capacity invariant 0<=tail-head<=N`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Concurrent market-data pipelines.

### P3.28.2 — Lock Free MPMC Queue

- **Description:** Maintains the lock free mpmc queue state and structural invariants.
- **Mathematical definition:** `MPMC queue uses atomic sequence numbers/CAS to publish/consume slots`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Concurrent market-data pipelines.

### P3.28.3 — Concurrent Ring Buffer

- **Description:** Maintains the concurrent ring buffer state and structural invariants.
- **Mathematical definition:** `Circular buffer index=counter mod capacity with ordered concurrent access`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Concurrent market-data pipelines.

### P3.28.4 — Thread Pool

- **Description:** Implements thread pool according to its defining mathematical relation.
- **Mathematical definition:** `Workers consume queued independent tasks and publish results`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Concurrent market-data pipelines.

### P3.28.5 — Consistent Hashing

- **Description:** Implements consistent hashing according to its defining mathematical relation.
- **Mathematical definition:** `hash(key) maps to first clockwise ring node; use virtual nodes`.
- **ε / limits:** No general numeric ε; require event ordering, capacity bounds, and invariants.
- **Applications:** Concurrent market-data pipelines.

## P3.29 — Low-Latency Optimization

### P3.29.1 — Memory Pool Allocator

- **Description:** Maintains the memory pool allocator state and structural invariants.
- **Mathematical definition:** `Fixed-size slots allocated from free list; allocate/free O(1)`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Low latency and predictable memory use.

### P3.29.2 — Arena Allocator

- **Description:** Maintains the arena allocator state and structural invariants.
- **Mathematical definition:** `Bump pointer p_new=align_up(p,size_align)+size within arena capacity`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Low latency and predictable memory use.

### P3.29.3 — Cache Blocked Matrix Multiplication

- **Description:** Implements cache blocked matrix multiplication according to its defining mathematical relation.
- **Mathematical definition:** `Tile C_ij+=sum_{k block}A_ik B_kj, improve cache reuse`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Low latency and predictable memory use.

### P3.29.4 — SIMD Vector Summation

- **Description:** Implements simd vector summation according to its defining mathematical relation.
- **Mathematical definition:** `Vector lanes compute partial sums; horizontal reduce`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Low latency and predictable memory use.

### P3.29.5 — SIMD Dot Product

- **Description:** Implements simd dot product according to its defining mathematical relation.
- **Mathematical definition:** `s=sum_lanes(a_lanes*b_lanes) then horizontal reduction`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Low latency and predictable memory use.

### P3.29.6 — Allocation Free Processing Pipeline

- **Description:** Simulates allocation free processing pipeline under specified assumptions and parameters.
- **Mathematical definition:** `Process records using preallocated buffers, bound allocations per record=0`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Low latency and predictable memory use.

## P3.30 — GPU Computing

### P3.30.1 — GPU Parallel Reduction

- **Description:** Implements gpu parallel reduction according to its defining mathematical relation.
- **Mathematical definition:** `GPU tree reduction of sum_i x_i with synchronization per stage`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Massively parallel simulations.

### P3.30.2 — GPU Matrix Multiplication

- **Description:** Implements gpu matrix multiplication according to its defining mathematical relation.
- **Mathematical definition:** `GPU tiled C_ij=sum_k A_ik B_kj`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Massively parallel simulations.

### P3.30.3 — GPU Monte Carlo

- **Description:** Simulates gpu monte carlo under specified assumptions and parameters.
- **Mathematical definition:** `Independent simulated paths assigned to GPU threads`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Massively parallel simulations.

### P3.30.4 — GPU Option Pricing

- **Description:** Computes gpu option pricing under explicit financial conventions.
- **Mathematical definition:** `GPU evaluate discounted option payoffs and parallel reduction`.
- **ε / limits:** Reduction error depends on floating-point order; specify sizes, threads and reproducibility.
- **Applications:** Massively parallel simulations.

## P3.31 — Signal Processing

### P3.31.1 — Discrete Fourier Transform

- **Description:** Implements discrete fourier transform according to its defining mathematical relation.
- **Mathematical definition:** `X_k=sum_{n=0}^{N-1}x_n exp(-2pi i kn/N)`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Spectral analysis and time-series filtering.

### P3.31.2 — Fast Fourier Transform

- **Description:** Implements fast fourier transform according to its defining mathematical relation.
- **Mathematical definition:** `FFT exploits even/odd decomposition: X_k=E_k+omega_N^k O_k`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Spectral analysis and time-series filtering.

### P3.31.3 — FIR Filter

- **Description:** Implements fir filter according to its defining mathematical relation.
- **Mathematical definition:** `y[n]=sum_{k=0}^{M-1}h[k]x[n-k]`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Spectral analysis and time-series filtering.

### P3.31.4 — Welch Power Spectral Density

- **Description:** Implements welch power spectral density according to its defining mathematical relation.
- **Mathematical definition:** `PSD_hat(f)=average_j (|FFT(window*segment_j)|^2/normalization)`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Spectral analysis and time-series filtering.

### P3.31.5 — Discrete Wavelet Transform

- **Description:** Implements discrete wavelet transform according to its defining mathematical relation.
- **Mathematical definition:** `Wavelet detail/approx coefficients via paired low/high-pass filter banks`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Spectral analysis and time-series filtering.

## P3.32 — Information Theory

### P3.32.1 — Shannon Entropy

- **Description:** Implements shannon entropy according to its defining mathematical relation.
- **Mathematical definition:** `H(X)=-sum_x p(x)ln p(x)`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Signal selection and distribution divergence.

### P3.32.2 — Mutual Information

- **Description:** Implements mutual information according to its defining mathematical relation.
- **Mathematical definition:** `I(X;Y)=sum_{x,y}p(x,y)ln[p(x,y)/(p(x)p(y))]`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Signal selection and distribution divergence.

### P3.32.3 — Kullback Leibler Divergence

- **Description:** Implements kullback leibler divergence according to its defining mathematical relation.
- **Mathematical definition:** `D_KL(P||Q)=sum_x p(x)ln(p(x)/q(x))`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Signal selection and distribution divergence.

### P3.32.4 — Jensen Shannon Divergence

- **Description:** Implements jensen shannon divergence according to its defining mathematical relation.
- **Mathematical definition:** `JSD(P,Q)=0.5 D_KL(P||M)+0.5 D_KL(Q||M), M=(P+Q)/2`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Signal selection and distribution divergence.

## P3.33 — Bayesian Inference

### P3.33.1 — Bayesian Linear Regression

- **Description:** Implements bayesian linear regression according to its defining mathematical relation.
- **Mathematical definition:** `posterior(beta|X,y) proportional likelihood(y|X,beta)*prior(beta)`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Probabilistic inference and sequential filtering.

### P3.33.2 — Metropolis Hastings

- **Description:** Implements metropolis hastings according to its defining mathematical relation.
- **Mathematical definition:** `Accept proposed theta' with min(1,pi(theta')q(theta|theta')/[pi(theta)q(theta'|theta)])`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Probabilistic inference and sequential filtering.

### P3.33.3 — Gibbs Sampling

- **Description:** Implements gibbs sampling according to its defining mathematical relation.
- **Mathematical definition:** `Draw each parameter theta_i from conditional p(theta_i|theta_-i,data)`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Probabilistic inference and sequential filtering.

### P3.33.4 — Particle Filter

- **Description:** Implements particle filter according to its defining mathematical relation.
- **Mathematical definition:** `Particles: propagate, weight w_i proportional p(y_t|x_t^i), normalize, resample`.
- **ε / limits:** Valid distribution parameters; ε for normalization, convergence and tail behavior.
- **Applications:** Probabilistic inference and sequential filtering.

## P3.34 — Graph Algorithms

### P3.34.1 — Dijkstras Algorithm

- **Description:** Implements dijkstras algorithm according to its defining mathematical relation.
- **Mathematical definition:** `d(v)=min_{(u,v)}[d(u)+w(u,v)] for nonnegative edge weights`.
- **ε / limits:** Exact for discrete paths; finite weights and tolerance for floating-point costs.
- **Applications:** Routing, flows and arbitrage detection.

### P3.34.2 — Bellman Ford

- **Description:** Implements bellman ford according to its defining mathematical relation.
- **Mathematical definition:** `Relax d(v)>d(u)+w(u,v) for |V|-1 rounds; detect negative cycles`.
- **ε / limits:** Exact for discrete paths; finite weights and tolerance for floating-point costs.
- **Applications:** Routing, flows and arbitrage detection.

### P3.34.3 — Minimum Cost Flow

- **Description:** Implements minimum cost flow according to its defining mathematical relation.
- **Mathematical definition:** `min sum_e c_e f_e subject to flow conservation and capacities`.
- **ε / limits:** Exact for discrete paths; finite weights and tolerance for floating-point costs.
- **Applications:** Routing, flows and arbitrage detection.

### P3.34.4 — Currency Arbitrage Detection

- **Description:** Implements currency arbitrage detection according to its defining mathematical relation.
- **Mathematical definition:** `Transform exchange rates r_ij into weights -ln(r_ij); negative cycle implies arbitrage`.
- **ε / limits:** Exact for discrete paths; finite weights and tolerance for floating-point costs.
- **Applications:** Routing, flows and arbitrage detection.

## P3.35 — Optimal Control

### P3.35.1 — Policy Iteration

- **Description:** Implements policy iteration according to its defining mathematical relation.
- **Mathematical definition:** `pi_{k+1}(s)=argmax_a [r(s,a)+gamma sum P(s'|s,a)V^{pi_k}(s')]`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Execution and dynamic risk control.

### P3.35.2 — Linear Quadratic Regulator

- **Description:** Implements linear quadratic regulator according to its defining mathematical relation.
- **Mathematical definition:** `u=-Kx, K=(R+B^TPB)^-1 B^TPA for discrete LQR`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Execution and dynamic risk control.

### P3.35.3 — Riccati Equation Solver

- **Description:** Solves riccati equation solver with an explicit stopping criterion.
- **Mathematical definition:** `P=A^TPA-A^TPB(R+B^TPB)^-1B^TPA+Q`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Execution and dynamic risk control.

### P3.35.4 — Model Predictive Control

- **Description:** Implements model predictive control according to its defining mathematical relation.
- **Mathematical definition:** `At each t minimize horizon objective subject to dynamics; implement first control`.
- **ε / limits:** Feasible constraints; numerical tolerance for optimality, risk and budget conservation.
- **Applications:** Execution and dynamic risk control.

## P3.36 — Machine Learning

### P3.36.1 — Logistic Regression

- **Description:** Implements logistic regression according to its defining mathematical relation.
- **Mathematical definition:** `Pr(y=1|x)=sigmoid(w^Tx+b)`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Statistical modeling and factor extraction.

### P3.36.2 — Ridge Lasso Regression

- **Description:** Implements ridge lasso regression according to its defining mathematical relation.
- **Mathematical definition:** `Ridge min ||y-Xw||^2+lambda||w||_2^2; Lasso +lambda||w||_1`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Statistical modeling and factor extraction.

### P3.36.3 — Principal Component Analysis

- **Description:** Implements principal component analysis according to its defining mathematical relation.
- **Mathematical definition:** `Find leading eigenvectors of centered-data covariance matrix`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Statistical modeling and factor extraction.

### P3.36.4 — K Means Clustering

- **Description:** Implements k means clustering according to its defining mathematical relation.
- **Mathematical definition:** `min_{centroids}sum_i min_k ||x_i-mu_k||^2`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Statistical modeling and factor extraction.

### P3.36.5 — Decision Tree

- **Description:** Maintains the decision tree state and structural invariants.
- **Mathematical definition:** `Choose feature split maximizing impurity reduction`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Statistical modeling and factor extraction.

### P3.36.6 — Random Forest

- **Description:** Implements random forest according to its defining mathematical relation.
- **Mathematical definition:** `Prediction=aggregate outputs of independently randomized decision trees`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Statistical modeling and factor extraction.

## P3.37 — Reinforcement Learning

### P3.37.1 — Multi Armed Bandit UCB

- **Description:** Implements multi armed bandit ucb according to its defining mathematical relation.
- **Mathematical definition:** `UCB_i=mean_reward_i+c sqrt(ln(t)/n_i)`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Sequential decisions and reward learning.

### P3.37.2 — Thompson Sampling

- **Description:** Implements thompson sampling according to its defining mathematical relation.
- **Mathematical definition:** `Sample theta_i from posterior and pick arm with maximum sampled reward`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Sequential decisions and reward learning.

### P3.37.3 — Q Learning

- **Description:** Implements q learning according to its defining mathematical relation.
- **Mathematical definition:** `Q(s,a)<-Q(s,a)+alpha[r+gamma max_a'Q(s',a')-Q(s,a)]`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Sequential decisions and reward learning.

### P3.37.4 — Reinforce Policy Gradient

- **Description:** Implements reinforce policy gradient according to its defining mathematical relation.
- **Mathematical definition:** `grad J(theta)=E[sum_t grad log pi_theta(a_t|s_t) G_t]`.
- **ε / limits:** Input limits and numerical tolerance defined for the implemented variant.
- **Applications:** Sequential decisions and reward learning.

---

## Documentation completion criteria

- Specify input/output types, conventions and units before implementation.
- Add reference, boundary and mathematical-property tests in C, Rust and TypeScript.
- Refine per-algorithm limits and tolerances during TDD; these are initial contracts, not guaranteed universal limits.
- Use `algorithms.tsv` as the authoritative directory registry; do not duplicate implementations when documenting.
