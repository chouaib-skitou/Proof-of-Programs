# Frama-C Mini-Project

This repository contains a collection of small C programs annotated with [ACSL](https://frama-c.com/acsl.html) specifications. Using [Frama-C](https://frama-c.com/) and its WP plugin, we can generate proof obligations and discharge them with SMT solvers to verify the correctness of these programs.

## Contents

- **maxint.c** – Returns the maximum of two integers.
- **maxint3.c** – Returns the maximum of three integers using `maxint`.
- **swap1.c / swap2.c / swap3.c** – Various implementations of swapping values.
- **loops.c** – Simple loops with annotations demonstrating loop invariants, loop variants, and assigns clauses.
- **abs.c** – Absolute value function with attention to potential overflow on `INT_MIN`.
- **sum.c** – Proves that the sum of the first n odd numbers equals \(n^2\).
- **foo.c** – Demonstrates a function that increments and decrements values in a loop, returning `2*n`.
- **getIndexMin.c** – Returns the index of the minimum element in an array.
- **allZeros.c** – Checks if all elements of an array are zero.
- **equal.c** – Checks if two arrays of the same length are element-wise equal.
- **fill.c** – Fills an array with a given value.
- **fact.c** – Iterative factorial function, proven correct via an axiomatic definition in ACSL.

## Requirements

- [Docker](https://www.docker.com/) >= 19.03  
- An internet connection to pull the Docker image (if it’s not already available locally)

## Directory Structure

```
project/
├── Dockerfile
├── maxint.c
├── maxint3.c
├── swap1.c
├── swap2.c
├── swap3.c
├── loops.c
├── abs.c
├── sum.c
├── foo.c
├── getIndexMin.c
├── allZeros.c
├── equal.c
├── fill.c
├── fact.c
└── README.md (this file)
```

## Getting Started

### 1. Build the Docker Image

From the `project/` directory (where the `Dockerfile` is located), run:

```bash
docker build -t my-frama-c .
```

This will build an image named `my-frama-c`, installing or providing Frama-C and the WP plugin (depending on your Dockerfile approach).

### 2. Run the Container

```bash
docker run -it --name frama-project my-frama-c
```

Inside the container, you’ll land in a shell with Frama-C (and Alt-Ergo, Z3, etc.) installed.

### 3. Prove the C Files

Inside the container shell:

```bash
# Check all proof obligations for maxint.c
frama-c -wp maxint.c

# Optionally specify a particular solver
frama-c -wp -wp-prover alt-ergo maxint.c

# You can do the same for all .c files
frama-c -wp abs.c
frama-c -wp loops.c
# etc.
```

You can also add the runtime checks plugin by running:

```bash
frama-c -wp -wp-rte abs.c
```

This checks for potential runtime errors (integer overflows, invalid pointer dereferences, etc.) and attempts to prove their absence (or reveal that additional preconditions are required).

## Notes and Tips

- **Pre/Post Conditions**: Each function has ACSL annotations specifying preconditions (`requires`) and postconditions (`ensures`).
- **Loop Annotations**: Loops require `loop invariant`, `loop variant`, and `loop assigns` clauses.
- **Axiomatic Definitions**: For factorial (`fact.c`), we introduce a logic function `Fact(n)` via an ACSL axiomatic block to match the mathematical definition of factorial.
- **Overflows**: In `abs.c`, there’s a potential overflow when `x == INT_MIN`. Therefore, we add a precondition `x > INT_MIN`.

## Troubleshooting

### Unproved Obligations:
- Try another SMT solver: `-wp-prover alt-ergo,z3,cvc4`.
- Check if the specification is missing some conditions or if the code does not meet the spec.

### Runtime Errors:
- Use `-wp-rte` to see if out-of-bounds array access or integer overflows appear.

### Docker Permissions:
- Make sure your user is part of the `docker` group (if on Linux) or run Docker as root if needed.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## References

- [Frama-C Official Documentation](https://frama-c.com/documentation.html)
- [ACSL by Example](https://frama-c.com/acsl-by-example.html) for more annotation patterns
- [Why3](http://why3.lri.fr/) for the underlying proof environment

---

Enjoy verifying your C programs with Frama-C and the WP plugin!

