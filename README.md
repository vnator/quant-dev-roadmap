# quant-dev-roadmap
A roadmap with my studies and material for consolidate my career as a quantitative developer.

# Quantitative Development Study Roadmap

## 1. Fundamentals

### Algorithms Fundamentals
- [ ] **Algorithm Analysis (Análise de Algoritmos)**
  - [ ] **Focus:** Big-O notation, recurrence relations, master theorem, and algorithmic complexity.
  - [ ] **Book:** [*Introduction to Algorithms (CLRS)*](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/) by Thomas H. Cormen et al.
  - [ ] **Course:** [MIT 6.046J - Design and Analysis of Algorithms](https://ocw.mit.edu/courses/6-046j-design-and-analysis-of-algorithms-spring-2015/) (MIT OpenCourseWare).
- [ ] **Data Structures and Core Algorithms**
  - [ ] **Focus:** Hash tables, balanced search trees, graph traversals, and sorting.
  - [ ] **Book:** [*Algorithms*](https://algs4.cs.princeton.edu/home/) by Robert Sedgewick and Kevin Wayne.
  - [ ] **Course:** [MIT 6.006 - Introduction to Algorithms](https://archive.org/details/MIT6.006S20) (MIT OpenCourseWare).
- [ ] **Dynamic Programming (Programação Dinâmica)**
  - [ ] **Focus:** Overlapping subproblems, optimal substructure, memoization, and tabulation (crucial for option pricing trees and optimal execution).
  - [ ] **Book:** [*Dynamic Programming and Optimal Control*](http://www.athenasc.com/dpbook.html) by Dimitri P. Bertsekas.
  - [ ] **Course:** [MIT 6.006 - Dynamic Programming Modules](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-fall-2011/video_galleries/lecture-videos/) (MIT OpenCourseWare).

### Computer Science Fundamentals
- [ ] **Computer Architecture & Memory Hierarchy**
  - [ ] **Focus:** Cache locality, memory barriers, branch prediction, and CPU pipelines.
  - [ ] **Book:** [*Computer Systems: A Programmer's Perspective*](https://csapp.cs.cmu.edu/) by Randal E. Bryant and David R. O'Hallaron.
  - [ ] **Course:** [MIT 6.004 - Computation Structures](https://ocw.mit.edu/courses/6-004-computation-structures-spring-2009/).
- [ ] **Operating Systems & Systems Programming**
  - [ ] **Focus:** Process scheduling, multithreading, concurrency, kernel bypass, and POSIX internals.
  - [ ] **Book:** [*Operating Systems: Three Easy Pieces*](https://pages.cs.wisc.edu/~remzi/OSTEP/) by Remzi H. Arpaci-Dusseau.
  - [ ] **Course:** [UC Berkeley CS162 - Operating Systems](https://cs162.org/).

### Mathematics Fundamentals
- [ ] **Elementary Mathematics (Matemática Elementar)**
  - [ ] **Focus:** Foundational building blocks divided into core subjects.
  - [ ] *Sets, Functions, and Arithmetic (Conjuntos e Funções)* 
  - [ ] *Geometry and Trigonometry (Geometria e Trigonometria)*
  - [ ] *Combinatorics and Probability (Combinatória e Probabilidade)*
  - [ ] **Book:** [*A Matemática do Ensino Médio (Vol 1, 2, 3)*](https://loja.sbm.org.br/index.php/colecoes/colecao-do-professor-de-matematica/a-matematica-do-ensino-medio-vol-1.html) by Elon Lages Lima, Paulo Cezar Pinto Carvalho, Eduardo Wagner, Augusto César Morgado (Coleção do Professor de Matemática - SBM/IMPA).
  - [ ] **Course:** [IMPA - Programa de Aperfeiçoamento de Professores de Matemática do Ensino Médio (PAPMEM)](https://www.youtube.com/playlist?list=PLo4jXE-LdDTQ_r7pU19A075h0qJ_qA25-) (IMPA YouTube).
- [ ] **Analytic Geometry (Geometria Analítica)**
  - [ ] **Focus:** Vectors, lines, planes, conics, and quadrics in $R^2$ and $R^3$.
  - [ ] **Book:** [*Geometria Analítica: Um Tratamento Vetorial*](https://www.amazon.com.br/Geometria-Anal%C3%ADtica-Tratamento-Paulo-Boulos/dp/8581438054) by Paulo Boulos and Ivan de Camargo.
  - [ ] **Course:** [USP - Geometria Analítica (UNIVESP)](https://www.youtube.com/playlist?list=PLxI8Can9yAHd2Uka-YQh7w9XzMhZ4gM0A).
- [ ] **Calculus 1 (Single Variable Calculus)**
  - [ ] **Focus:** Limits, derivatives, integrals, and the fundamental theorem of calculus.
  - [ ] **Book:** [*Calculus*](https://www.amazon.com/Calculus-4th-Michael-Spivak/dp/0914098918) by Michael Spivak.
  - [ ] **Course:** [MIT 18.01 - Single Variable Calculus](https://ocw.mit.edu/courses/18-01-single-variable-calculus-fall-2006/).
- [ ] **Calculus 2 (Multivariable Calculus)**
  - [ ] **Focus:** Partial derivatives, double/triple integrals, and optimization in multiple dimensions.
  - [ ] **Book:** [*Calculus, Vol. 2*](https://www.wiley.com/en-us/Calculus%2C+Volume+2%3A+Multi+Variable+Calculus+and+Linear+Algebra+with+Applications+to+Differential+Equations+and+Probability%2C+2nd+Edition-p-9780471000075) by Tom M. Apostol.
  - **Course:** [MIT 18.02 - Multivariable Calculus](https://ocw.mit.edu/courses/18-02-multivariable-calculus-fall-2007/).
- [ ] **Calculus 3 (Vector Calculus & Differential Equations)**
  - **Focus:** Line integrals, surface integrals, Green's, Stokes', and Divergence theorems, plus ODEs.
  - **Book:** [*Equações Diferenciais Aplicadas*](https://loja.sbm.org.br/index.php/equacoes-diferenciais-aplicadas.html) by Djairo Guedes de Figueiredo (SBM/IMPA).
  - **Course:** [MIT 18.03 - Differential Equations](https://ocw.mit.edu/courses/18-03-differential-equations-spring-2010/).
- [ ] **Linear Algebra**
  - [ ] **Focus:** Matrix operations, eigenvalues, eigenvectors, and vector spaces.
  - [ ] **Book:** [*Álgebra Linear*](https://loja.sbm.org.br/index.php/algebra-linear.html) by Elon Lages Lima (Coleção Matemática Universitária - SBM/IMPA).
  - [ ] **Course:** [MIT 18.06 - Linear Algebra](https://ocw.mit.edu/courses/18-06-linear-algebra-spring-2010/).

---

## 2. Advanced

### Advanced Algorithms
- [ ] **Numerical Algorithms & Numerical Calculus (Cálculos Numéricos)**
  - [ ] **Focus:** Root finding, interpolation, solving systems of linear equations numerically, and finite difference methods for PDEs (crucial for pricing derivatives).
  - [ ] **Book:** [*Cálculo Numérico: Aspectos Teóricos e Computacionais*](https://www.amazon.com.br/C%C3%A1lculo-Num%C3%A9rico-Aspectos-Te%C3%B3ricos-Computacionais/dp/8534602042) by Márcia A. Gomes Ruggiero and Vera Lúcia da Rocha Lopes.
  - [ ] **Course:** [MIT 18.330 - Introduction to Numerical Analysis](https://ocw.mit.edu/courses/18-330-introduction-to-numerical-analysis-spring-2012/).
- [ ] **Nature-Inspired Algorithms (Algoritmos Naturais)**
  - [ ] **Focus:** Genetic algorithms, ant colony optimization, and particle swarm optimization. Useful for hyperparameter tuning and alternative optimization schemas in quantitative trading.
  - [ ] **Book:** [*Introduction to Evolutionary Computing*](https://link.springer.com/book/10.1007/978-3-662-44874-8) by A.E. Eiben and J.E. Smith.
  - [ ] **Course:** [NPTEL - Traditional and Non-Traditional Optimization Tools](https://nptel.ac.in/courses/112103301).
- [ ] **Monte Carlo Simulation Algorithms**
  - [ ] **Focus:** Random number generation, variance reduction techniques, and stochastic simulations.
  - [ ] **Book:** [*Monte Carlo Methods in Financial Engineering*](https://link.springer.com/book/10.1007/978-0-387-21617-1) by Paul Glasserman.

### Advanced Computer Science
- [ ] **Parallel Programming (Programação Paralela)**
  - [ ] **Focus:** GPU computing, CUDA, MPI, OpenMP, and accelerating matrix operations for quantitative research.
  - [ ] **Book:** [*Programming Massively Parallel Processors: A Hands-on Approach*](https://www.elsevier.com/books/programming-massively-parallel-processors/kirk/978-0-12-811986-0) by David B. Kirk and Wen-mei W. Hwu.
  - [ ] **Course:** [Stanford CS149 - Parallel Computing](https://stanford.edu/class/cs149/).
- [ ] **Performance Engineering & Low-Latency Optimization**
  - [ ] **Focus:** SIMD vectorization, lock-free programming, and compiler optimizations.
  - [ ] **Book:** [*C++ Concurrency in Action*](https://www.manning.com/books/c-plus-plus-concurrency-in-action-second-edition) by Anthony Williams.
  - [ ] **Course:** [MIT 6.172 - Performance Engineering of Software Systems](https://ocw.mit.edu/courses/6-172-performance-engineering-of-software-systems-fall-2018/).

### Advanced Mathematics
- [ ] **Real Analysis (Análise Matemática)**
  - [ ] **Focus:** Rigorous foundation of calculus, limits, continuity, compactness, and metric spaces.
  - [ ] **Book:** [*Análise Real (Vol. 1: Funções de Uma Variável)*](https://loja.sbm.org.br/index.php/analise-real-volume-1-funcoes-de-uma-variavel-108.html) by Elon Lages Lima (Coleção Matemática Universitária - IMPA).
  - [ ] **Course:** [IMPA - Curso de Análise Real](https://www.youtube.com/playlist?list=PLo4jXE-LdDTRl-1pE7aV98L_l0Z1ZJ2A-) (IMPA YouTube).
- [ ] **Fundamentals of Abstract Algebra (Fundamentos de Álgebra Abstrata)**
  - [ ] **Focus:** Groups, rings, fields, and Galois theory (important for advanced cryptographic algorithms and certain areas of pure quantitative theory).
  - [ ] **Book:** [*Curso de Álgebra (Vol. 1)*](https://loja.sbm.org.br/index.php/curso-de-algebra-vol-1.html) by Abramo Hefez (Coleção Matemática Universitária - IMPA).
  - [ ] **Course:** [Harvard Math 122 - Abstract Algebra](https://people.math.harvard.edu/~gross/math122/).
- [ ] **Numerical Linear Algebra (Álgebra Numérica)**
  - [ ] **Focus:** Floating-point arithmetic, conditioning, stability, and algorithms for matrix decompositions (SVD, QR).
  - [ ] **Book:** [*Numerical Linear Algebra*](https://bookstore.siam.org/ot50/) by Lloyd N. Trefethen and David Bau III.
  - [ ] **Course:** [MIT 18.335J - Introduction to Numerical Methods](https://ocw.mit.edu/courses/18-335j-introduction-to-numerical-methods-spring-2019/).
- [ ] **Operations Research (Pesquisa Operacional)**
  - [ ] **Focus:** Linear programming, simplex method, network flow models, and integer programming for optimal portfolio execution and routing.
  - [ ] **Book:** [*Introduction to Operations Research*](https://www.mheducation.com/highered/product/introduction-operations-research-hillier-lieberman/M9781259872990.html) by Frederick S. Hillier and Gerald J. Lieberman.
  - [ ] **Course:** [MIT 15.053 - Optimization Methods in Management Science](https://ocw.mit.edu/courses/15-053-optimization-methods-in-management-science-spring-2013/).
- [ ] **Mathematical Modeling (Modelagem Matemática)**
  - [ ] **Focus:** Translating real-world financial phenomena into mathematical equations and discrete/continuous models.
  - [ ] **Book:** [*A First Course in Mathematical Modeling*](https://www.cengage.com/c/a-first-course-in-mathematical-modeling-5e-giordano/9781285050904/) by Frank R. Giordano et al.
  - [ ] **Course:** [Coursera - Mathematical Modelling Basics (TU Delft)](https://www.coursera.org/learn/mathematical-modelling).
- [ ] **Regression Analysis (Análise de Regressão)**
  - [ ] **Focus:** Simple/multiple linear regression, residual analysis, ANOVA, and predictive modeling for asset returns.
  - [ ] **Book:** [*Applied Linear Statistical Models*](https://www.mheducation.com/highered/product/applied-linear-statistical-models-kutner-nachtsheim/M9780073108742.html) by Michael H. Kutner et al.
  - [ ] **Course:** [MIT 18.650 - Statistics for Applications](https://ocw.mit.edu/courses/18-650-statistics-for-applications-fall-2016/).
