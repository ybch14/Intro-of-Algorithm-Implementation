// square matrix multiplication
#include <iostream>
#include "matrix.h"
// used for print square matrix 
std::ostream& operator<<(std::ostream& os, SquareMatrix M)
{
	int dimension = M.dimension;
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
			os << M.matrix_data[i * dimension + j] << ' ';
		os << std::endl;
	}
	return os;
}

SquareMatrix naive_multiply(const SquareMatrix& A, const SquareMatrix& B)
{
	if (A.dim() != B.dim())
	{
		std::cout << "dimension not equal!" << std::endl;
		exit(-1);
	}
	int dim = A.dim();
	SquareMatrix C(dim);
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			for (int k = 0; k < dim; k++)
				C.matrix_data[i * dim + j] += A.data(i, k) * B.data(k, j);
	return C;
}
SquareMatrix strassen_multiply(const SquareMatrix& A, const SquareMatrix& B)
{
	int dim = A.dim();
	if (dim <= 128)
		return naive_multiply(A, B);
	else
	{
		SquareMatrix result(dim);
		SquareMatrix S1(int(dim/2)), S2(int(dim/2)), S3(int(dim/2)), S4(int(dim/2)), S5(int(dim/2)),
					 S6(int(dim/2)), S7(int(dim/2)), S8(int(dim/2)), S9(int(dim/2)), S10(int(dim/2)),
					 A11(int(dim/2)), B11(int(dim/2)), A22(int(dim/2)), B22(int(dim/2));
		for (int i = 0; i < dim/2; i++)
		{
			for (int j = 0; j < dim/2; j++)
			{
				S1.matrix_data[i * dim/2 + j] = B.data(i, dim/2 + j) - B.data(dim/2 + i, dim/2 + j);
				S2.matrix_data[i * dim/2 + j] = A.data(i, j) + A.data(i, dim/2 + j);
				S3.matrix_data[i * dim/2 + j] = A.data(dim/2 + i, j) + A.data(dim/2 + i, dim/2 + j);
				S4.matrix_data[i * dim/2 + j] = B.data(dim/2 + i, j) - B.data(i, j);
				S5.matrix_data[i * dim/2 + j] = A.data(i, j) + A.data(dim/2 + i, dim/2 + j);
				S6.matrix_data[i * dim/2 + j] = B.data(i, j) + B.data(dim/2 + i, dim/2 + j);
				S7.matrix_data[i * dim/2 + j] = A.data(i, dim/2 + j) - A.data(dim/2 + i, dim/2 + j);
				S8.matrix_data[i * dim/2 + j] = B.data(dim / 2 + i, j) + B.data(dim/2 + i, dim/2 + j);
				S9.matrix_data[i * dim/2 + j] = A.data(i, j) - A.data(dim/2 + i, j);
				S10.matrix_data[i * dim/2 + j] = B.data(i, j) + B.data(i, dim/2 + j);
				A11.matrix_data[i * dim/2 + j] = A.data(i, j);
				A22.matrix_data[i * dim/2 + j] = A.data(dim/2 + i, dim/2 + j);
				B11.matrix_data[i * dim/2 + j] = B.data(i, j);
				B22.matrix_data[i * dim/2 + j] = B.data(dim/2 + i, dim/2 + j);
			}
		}
		SquareMatrix P1 = strassen_multiply(A11, S1);
		SquareMatrix P2 = strassen_multiply(S2, B22);
		SquareMatrix P3 = strassen_multiply(S3, B11);
		SquareMatrix P4 = strassen_multiply(A22, S4);
		SquareMatrix P5 = strassen_multiply(S5, S6);
		SquareMatrix P6 = strassen_multiply(S7, S8);
		SquareMatrix P7 = strassen_multiply(S9, S10);
		for (int i = 0; i < dim/2; i++)
		{
			for (int j = 0; j < dim/2; j++)
			{
				result.matrix_data[i * dim + j] = P5.data(i, j) + P4.data(i, j) - P2.data(i, j) + P6.data(i, j);
				result.matrix_data[i * dim + (dim/2 + j)] = P1.data(i, j) + P2.data(i, j);
				result.matrix_data[(dim/2 + i) * dim + j] = P3.data(i, j) + P4.data(i, j);
				result.matrix_data[(dim/2 + i) * dim + (dim/2 + j)] = P5.data(i, j) + P1.data(i, j) - P3.data(i, j) - P7.data(i, j);
			}
		}
		return result;
	}
}
