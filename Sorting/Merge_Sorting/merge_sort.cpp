#include <iostream>

double* merge_sort(double* A, int low, int high)
{
	double* insert_sort(double* A, int length);
	double* merge(double* a1, int length1, double* a2, int length2);
	if ((high-low) <= 10000)
		return insert_sort(A+low, high-low+1);
	int mid = int((low + high) / 2);
	//std::cout << "low: " << low << ", mid: " << mid << ", high: " << high << std::endl;
	double *left = merge_sort(A, low, mid);
	double *right = merge_sort(A, mid+1, high);
	double *result = merge(left, mid-low+1, right, high-mid);
	delete []left;
	delete []right;
	return result;
}

double* merge(double* a1, int length1, double* a2, int length2)
{
	int i = 0, j = 0, result_index = 0;
	double *result = new double[length1 + length2];
	while (i < length1 && j < length2)
	{
		if (a1[i] <= a2[j])
		{
			result[result_index] = a1[i];
			i++;
		}
		else
		{
			result[result_index] = a2[j];
			j++;
		}
		result_index++;
	}
	if ((i == length1) && (j < length2))
		for (int k = j; k < length2; k++)
			result[result_index+k-j] = a2[k];
	else if ((j == length2) && (i < length1))
		for (int k = i; k < length1; k++)
			result[result_index+k-i] = a1[k];
	return result;
}

double* insert_sort(double* A, int length)
{
	double* result = new double[length];
	for (int i = 0; i < length; i++)
	{
		int j = i-1;
		while ((j >= 0) && (result[j] > A[i]))
		{
			result[j+1] = result[j];
			j--;
		}
		result[j+1] = A[i];
	}
	return result;
}

bool test_sort(double* A, int length)
{
	for (int i = 0; i < length-1; i++)
	{
		if (A[i] > A[i+1])
		{
			std::cout << "Wrong at " << i << std::endl;
			return false;
		}
	}
	return true;
}