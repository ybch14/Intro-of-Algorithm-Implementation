#include <iostream>

void merge_sort(double* A, int low, int high)
{
	void insert_sort(double* A, int length);
	void merge(double* A, int low, int high);
	if ((high - low) <= 100)
		insert_sort(A + low, high - low + 1);
	else
	{
		int mid = int((low + high) / 2);
		//std::cout << "low: " << low << ", mid: " << mid << ", high: " << high << std::endl;
		merge_sort(A, low, mid);
		merge_sort(A, mid + 1, high);
		merge(A, low, high);
	}
}

void merge(double *A, int low, int high)
{
	int mid = int((low + high) / 2), length1 = mid - low + 1, length2 = high - mid;
	double *a1 = new double[length1];
	std::copy(A + low, A + mid + 1, a1);
	double *a2 = new double[length2];
	std::copy(A + mid + 1, A + high + 1, a2);

	int i = 0, j = 0, result_index = low;
	while (i < length1 && j < length2)
	{
		if (a1[i] <= a2[j])
		{
			A[result_index] = a1[i];
			i++;
		}
		else
		{
			A[result_index] = a2[j];
			j++;
		}
		result_index++;
	}
	if ((i == length1) && (j < length2))
		for (int k = j; k < length2; k++)
			A[result_index + k - j] = a2[k];
	else if ((j == length2) && (i < length1))
		for (int k = i; k < length1; k++)
			A[result_index + k - i] = a1[k];
	delete[]a1;
	delete[]a2;
}

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