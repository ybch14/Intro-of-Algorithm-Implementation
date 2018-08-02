# Strassen's Matrix Multiplication

Strassen's matrix multiplication implementation.

## Task definition

Multiply two square matrices (dimension restricted to power of 2 for simplification).

## Data structure

```C++
class SquareMatrix
{
private:
    int dimension;
    double* matrix_data;
public:
    SquareMatrix(int dim);
    SquareMatrix(double* data, int dim);
    SquareMatrix(const SquareMatrix& M);
    ~SquareMatrix();
    int dim() const;
    double data(int i, int j) const;
    friend std::ostream& operator<<(std::ostream& os, SquareMatrix M);
    friend SquareMatrix naive_multiply(const SquareMatrix& A, const SquareMatrix& B);
    friend SquareMatrix strassen_multiply(const SquareMatrix& A, const SquareMatrix& B);
    SquareMatrix multiply(SquareMatrix& B, char mode = 'n');
    SquareMatrix operator+(SquareMatrix& B);
    SquareMatrix operator-(SquareMatrix& B);
    void operator=(SquareMatrix& B);
    bool operator==(SquareMatrix& B);
};
```

## File List

- [`matrix.h`](matrix.h): square matrix class definition.
- [`multiplication.cpp`](multiplication.cpp): implementation of naive and strassen's multiplication.
- [`main.cpp`](main.cpp): test samples.
- [`A.txt`](A.txt), [`B.txt`](B.txt): two large matrices.

## Test sample

- Small matrix
    - A = { 1.0, 2.0, 3.0, 4.0; 5.0, 6.0, 7.0, 8.0;	9.0, 10.0, 11.0, 12.0; 13.0, 14.0, 15.0, 16.0 }
    - B = { 1.0, -1.0, 1.0, -1.0; 2.0, -2.0, 3.0, -3.0; 4.0, -4.0, 5.0, -5.0; 3.0, -3.0, 6.0, -6.0 }
    - C = A * B (naive)
    - S = A * B (strassen)
    - C = A + B
    - C = B - A
    - C = {0.0, 0.0; 0.0, 0.0} (test for memory robustness)
- Big Matrix
    - A, B: standard normal distributed random-initialized 1024 * 1024 matrix (```A/B.txt```)
	- C = A * B (naive)
    - S = A * B (strassen)

## Output

```
A:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
B:
1 -1 1 -1
2 -2 3 -3
4 -4 5 -5
3 -3 6 -6
naive A*B:
29 -29 46 -46
69 -69 106 -106
109 -109 166 -166
149 -149 226 -226
strassen A*B:
29 -29 46 -46
69 -69 106 -106
109 -109 166 -166
149 -149 226 -226
A+B:
2 1 4 3
7 4 10 5
13 6 16 7
16 11 21 10
B-A:
0 -3 -2 -5
-3 -8 -4 -11
-5 -14 -6 -17
-10 -17 -9 -22
C:
0 0
0 0
naive multiply: 22.161s
strassen multiply: 2.658s
C == S? Yes! :)
```