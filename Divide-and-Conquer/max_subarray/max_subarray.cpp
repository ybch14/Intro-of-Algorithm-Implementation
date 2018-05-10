#include "subarray.h"

SubArray max_subarray(int* A, int low, int high)
{
	if (high == low)
		return SubArray(low, low, A[low]);
	SubArray max_cross_mid_subarray(int* A, int low, int high);
	int mid = int((high+low)/2);
	SubArray left_max_subarray = max_subarray(A, low, mid);
	SubArray right_max_subarray = max_subarray(A, mid+1, high);
	SubArray cross_max_subarray = max_cross_mid_subarray(A, low, high);
	int left_sum = left_max_subarray.sum();
	int right_sum = right_max_subarray.sum();
	int cross_sum = cross_max_subarray.sum();
	if ((left_sum > right_sum) && (left_sum > cross_sum))
		return left_max_subarray;
	else if ((right_sum > left_sum) && (right_sum > cross_sum))
		return right_max_subarray;
	else
		return cross_max_subarray;
}

SubArray max_cross_mid_subarray(int* A, int low, int high)
{
	if (low == high)
		return SubArray(low, low, A[low]);
	if (low == high-1)
	{
		if ((A[low] > 0) && (A[high] < 0))
			return SubArray(low, low, A[low]);
		else if ((A[low] < 0) && (A[high] > 0))
			return SubArray(high, high, A[high]);
		else
			return SubArray(low, high, A[low]+A[high]);
	}
	int mid = int((low+high)/2);
	int sum = 0, left_max = int(-1e6), left_max_index = mid;
	for (int i = mid, sum = 0; i >= low; i--)
	{
		sum += A[i];
		if (sum > left_max)
		{
			left_max = sum;
			left_max_index = i;
		}
	}
	int right_max = int(-1e6), right_max_index = mid + 1;
	for (int j = mid + 1, sum = 0; j < high; j++)
	{
		sum += A[j];
		if (sum > right_max)
		{
			right_max = sum;
			right_max_index = j;
		}
	}
	int max_sum = left_max + right_max;
	return SubArray(left_max_index, right_max_index, max_sum);
}