#include <iostream>
#include <fstream>
#include <time.h>

int main()
{
	double* merge_sort(double* A, int low, int high);
	double* insert_sort(double* A, int length);
	bool test_sort(double* A, int length);
	double a[10] = {1, 5, 6, 3, 4, 5, 6, 2, 1, 0};
	double* result = merge_sort(a, 0, 10-1);
	for (int i = 0; i < 10; i++)
		std::cout << result[i] << ' ';
	std::cout << std::endl;
	delete []result;
	result = NULL;

	int length = 1000000;
	double *array = new double[length];
	std::ifstream f("data.txt");
	for (int i = 0; i < length; i++)
		f >> array[i];
	std::cout << "Data loaded!" << std::endl;
	clock_t start = clock();
	result = merge_sort(array, 0, length-1);
	std::cout << "Merge sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Merge sort correct? " << (test_sort(result, length)?"Yes! :)":"No! :(") << std::endl;
	start = clock();
	result = insert_sort(array, length);
	std::cout << "Insert sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Insert sort correct? " << (test_sort(result, length)?"Yes! :)":"No! :(") << std::endl;
	delete []result;
	return 0;
}