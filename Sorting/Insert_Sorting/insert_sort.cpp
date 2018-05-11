// sort from small to large
#include <iostream>
void insert_sort(double* A, int length)
{
	double* result = new double[length];
	std::copy(A, A + length, result);
	for (int i = 0; i < length; i++)
	{
		int j = i - 1;
		while ((j >= 0) && (A[j] > result[i]))
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = result[i];
	}
	delete[]result;
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