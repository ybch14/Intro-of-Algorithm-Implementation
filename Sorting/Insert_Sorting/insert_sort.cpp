// sort from small to large
#include <iostream>
void insert_sort(double* A, int length)
{
	int j = 0; double tmp = 0.;
	for (int i = 0; i < length; i++)
	{
		j = i - 1;
		tmp = A[i];
		while ((j >= 0) && (A[j] > tmp))
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = tmp;
	}
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