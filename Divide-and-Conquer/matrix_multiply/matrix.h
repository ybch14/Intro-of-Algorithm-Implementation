#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <algorithm>
#include <cmath>

class SquareMatrix
{
private:
	int dimension;
	double* matrix_data;
public:
	// constructor with only dimension, initialize matrix with zeros
	SquareMatrix(int dim)
	{
		dimension = dim;
		matrix_data = new double[dim * dim];
		std::fill(matrix_data, matrix_data + dim*dim, 0.0);
	}
	// constructor with dimension and data, deep copy
	SquareMatrix(double* data, int dim)
	{
		dimension = dim;
		matrix_data = new double[dim * dim];
		std::copy(data, data + dim*dim, matrix_data);
	}
	// copy constructor, deep copy
	SquareMatrix(const SquareMatrix& M)
	{
		dimension = M.dimension;
		matrix_data = new double[dimension * dimension];
		std::copy(M.matrix_data, M.matrix_data + dimension*dimension, matrix_data);
	}
	// destructor
	~SquareMatrix()
	{
		delete []matrix_data;
	}
	int dim() const
	{
		return dimension;
	}
	double data(int i, int j) const
	{
		return matrix_data[i * dimension + j];
	}
	// print square matrix
	friend std::ostream& operator<<(std::ostream& os, SquareMatrix M);
	// naive multiple, O(n^3)
	friend SquareMatrix naive_multiply(const SquareMatrix& A, const SquareMatrix& B);
	// strassen_multiple, O(n^(2.807))
	friend SquareMatrix strassen_multiply(const SquareMatrix& A, const SquareMatrix& B);
	// choose multiply algorithm 
	SquareMatrix multiply(SquareMatrix& B, char mode = 'n')
	{
		if (mode == 'n')
			return naive_multiply(*this, B);
		else if (mode == 's')
			return strassen_multiply(*this, B);
		else
		{
			std::cerr << "Invalid mode!";
			exit(-1);
		}
	}
	// add operator
	SquareMatrix operator+(SquareMatrix& B)
	{
		if (dimension != B.dim())
		{
			std::cerr << "dimension not equal!" << std::endl;
			exit(-1);
		}
		SquareMatrix result(dimension);
		for (int i = 0; i < dimension * dimension; i++)
			result.matrix_data[i] = matrix_data[i] + B.matrix_data[i];
		return result;
	}
	// minus operator
	SquareMatrix operator-(SquareMatrix& B)
	{
		if (dimension != B.dim())
		{
			std::cerr << "Dimension mismatch!" << std::endl;
			exit(-1);
		}
		else
		{
			SquareMatrix result(dimension);
			for (int i = 0; i < dimension * dimension; i++)
				result.matrix_data[i] = matrix_data[i] - B.matrix_data[i];
			return result;
		}
	}
	// assignment operator, deep copy
	// if don't define this, "SM C = A; C = A+B;" will be wrong
	void operator=(SquareMatrix& B)
	{
		dimension = B.dim();
		delete []matrix_data;
		matrix_data = new double[B.dim() * B.dim()];
		std::copy(B.matrix_data, B.matrix_data + B.dim() * B.dim(), matrix_data);
	}
	bool operator==(SquareMatrix& B)
	{
		int dim = B.dim();
		if (dim != dimension)
			return false;
		for (int i = 0; i < dimension; i++)
			if (abs(matrix_data[i] - B.matrix_data[i]) > 1e-10)
				return false;
		return true;
	}
};
#endif