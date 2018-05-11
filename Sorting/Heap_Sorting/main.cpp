#include <iostream>
#include <fstream>
#include <time.h>
#include "heap.h"

int main()
{
	void heap_sort(double* A, int length);
	void insert_sort(double* A, int length);
	bool test_sort(double* A, int length);
	double a[10] = { 1, 5, 6, 3, 4, 5, 6, 2, 1, 0 };
	heap_sort(a, 10);
	for (int i = 0; i < 10; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;

	int length = 1000000;
	double *array1 = new double[length];
	std::ifstream f("data.txt");
	for (int i = 0; i < length; i++)
		f >> array1[i];
	double *array2 = new double[length];
	std::copy(array1, array1 + length, array2);
	std::cout << "Data loaded!" << std::endl;
	clock_t start = clock();
	heap_sort(array1, length);
	std::cout << "Heap sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Heap sort correct? " << (test_sort(array1, length) ? "Yes! :)" : "No! :(") << std::endl;
	start = clock();
	insert_sort(array2, length);
	std::cout << "Insert sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Insert sort correct? " << (test_sort(array2, length) ? "Yes! :)" : "No! :(") << std::endl;
	delete[]array1;
	delete[]array2;
	return 0;
}