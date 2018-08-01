#include "order_statistics_tree.h"

void insert_sort(double* A, int low, int high)
{
	int j = low - 1;
	double tmp = 0.;
	for (int i = low; i <= high; i++)
	{
		j = i - 1;
		tmp = A[i - low];
		while ((j >= low) && (A[j] > tmp))
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = tmp;
	}
}

double find_median(double* A, int low, int high)
{
	// seperate groups
	std::vector<std::vector<double>> groups;
	std::vector<double> tmp;
	for (int i = low; i <= high; i++)
	{
		if ((i - low) % 5 == 0)
		{
			std::vector<double> push_tmp;
			groups.push_back(push_tmp);
		}
		groups[(int)groups.size() - 1].push_back(A[i]);
	}
	// calculate group medians
	// except for the last group, all groups have 5 numbers
	// so the median is the 3rd element
	std::vector<double> medians;
	for (int i = 0; i < (int)groups.size() - 1; i++)
	{
		std::sort(groups[i].begin(), groups[i].end());
		medians.push_back(groups[i][2]);
	}
	// last group's size is not sure
	// if even, use the lower median
	std::vector<double> last_group = groups[groups.size() - 1];
	std::sort(last_group.begin(), last_group.end());
	int last_group_size = (int)last_group.size();
	if (last_group_size == 1)
		medians.push_back(last_group[0]);
	else if (last_group_size % 2 == 0)
		medians.push_back(last_group[last_group_size / 2 - 1]);
	else
		medians.push_back(last_group[last_group_size / 2]);
	// sort all medians and get median-of medians
	std::sort(medians.begin(), medians.end());
	if ((int)medians.size() % 2 == 0)
		return medians[(int)medians.size() / 2 - 1];
	else
		return medians[(int)medians.size() / 2];
}

int partition(double *A, int low, int high, double median)
{
	int median_index = low - 1;
	for (int i = low; i <= high; i++)
	{
		if (A[i] == median)
		{
			median_index = i;
			break;
		}
	}
	double tmp = 0.0;
	tmp = A[median_index];
	A[median_index] = A[high];
	A[high] = tmp;
	double x = A[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (A[j] <= x)
		{
			i++;
			tmp = A[j];
			A[j] = A[i];
			A[i] = tmp;
		}
	}
	tmp = A[i + 1];
	A[i + 1] = A[high];
	A[high] = tmp;
	return i + 1;
}

double select(double* A, int low, int high, int rank)
{
	double median = find_median(A, low, high);
	int mid = partition(A, low, high, median);
	if (mid == rank)
		return A[mid];
	else if (mid > rank)
		return select(A, low, mid - 1, rank);
	else
		return select(A, mid + 1, high, rank);
}

bool test_order_statistics(double* result, double* gt, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (result[i] != gt[i])
			return false;
	}
	return true;
}