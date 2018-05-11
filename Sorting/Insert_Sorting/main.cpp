#include <iostream>
#include <fstream>
#include <time.h>

int main()
{
	void insert_sort(double* A, int length);
	bool test_sort(double* A, int length);
	double a[10] = { 1, 5, 6, 3, 4, 5, 6, 2, 1, 0 };
	insert_sort(a, 10);
	for (int i = 0; i < 10; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;

	int length = 1000000;
	double *array = new double[length];
	std::ifstream f("data.txt");
	for (int i = 0; i < length; i++)
		f >> array[i];
	std::cout << "Data loaded!" << std::endl;
	clock_t start = clock();
	insert_sort(array, length);
	std::cout << "Insert sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Insert sort correct? " << (test_sort(array, length) ? "Yes! :)" : "No! :(") << std::endl;
	return 0;
}