# Matrix Chain Multiplication Problem

Dynamic programming: matrix chain multiplication problem implementation.

## Task Definition

Consider a sequence of n matrices to be multiplied, whose dimensions are {p0\*p1, p1\*p2, p2\*p3, ..., p(n-1)\*p(n)}. Since matrix multiplication is associative, so all parenthesizations yield the same product. Find a way of parenthesization so that the times of scalar multiplication reach its minimum. 

## File List 

- [`matrix_chain_multiplication.cpp`](matrix_chain_multiplication.cpp): implementation of dynamic programming recurrent structure.
- [`main.cpp`](main.cpp): test samples.

## Test Sample

- {30\*35, 35\*15, 15\*5, 5\*10, 10\*20, 20\*25}
- {5\*10, 10\*3, 3\*12, 12\*5, 5\*50, 50\*6}

## Output

```
Test Sample 1:
Optimal Solution:
((A0(A1A2))((A3A4)A5))
Operations: 15125
Test sample 2
Optimal Solution:
((A0A1)((A2A3)(A4A5)))
Operations: 2010
```