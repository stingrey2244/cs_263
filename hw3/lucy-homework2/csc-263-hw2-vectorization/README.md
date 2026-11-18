# CSC263 HW2: Vectorization

The program `random_vector_sum.cpp` calculates the sum of two random vectors of ints.

The program `vector_multiplication_by_scalar.cpp` multiplies a random vector by a user-inputed scalar value.

## Instructions

To compile the code, run

```
g++ filename.cpp
```

To compile the code with vectorization, use clang++ with the optimization (-O1, -O2, or -O3), -march, and -Rpass flags,

```
clang++ -O1 -march=native -Rpass=loop-vectorize filename.cpp
```

Then run the executable with 

```
./a.out
```

In `vector_multiplication_by_scalar.cpp`, input your desired scalar value when prompted. This will be used to multiply the random vector by.
