#include "heap.h"
#include <iostream>

double* heap_sort(double* A, int length)
{
	Heap heap(A, length);
	heap.sort();
	double* result = new double[length];
	for (int i = 0; i < length; i++)
		result[i] = heap.data(i);
	return result;
}

double* insert_sort(double* A, int length)
{
	double* result = new double[length];
	for (int i = 0; i < length; i++)
	{
		int j = i - 1;
		while ((j >= 0) && (result[j] > A[i]))
		{
			result[j + 1] = result[j];
			j--;
		}
		result[j + 1] = A[i];
	}
	return result;
}

bool test_sort(double* A, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		if (A[i] > A[i + 1])
		{
			std::cout << "Wrong at " << i << std::endl;
			return false;
		}
	}
	return true;
}