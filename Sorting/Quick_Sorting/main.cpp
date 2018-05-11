#include <iostream>
#include <fstream>
#include <time.h>

int main()
{
	void insert_sort(double* A, int length);
	void quick_sort(double* A, int low, int high);
	bool test_sort(double* A, int length);
	double a[10] = { 1, 5, 6, 3, 4, 5, 6, 2, 1, 0 };
	quick_sort(a, 0, 10-1);
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
	quick_sort(array1, 0, length-1);
	std::cout << "Quick sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Quick sort correct? " << (test_sort(array1, length) ? "Yes! :)" : "No! :(") << std::endl;
	start = clock();
	insert_sort(array2, length);
	std::cout << "Insert sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Insert sort correct? " << (test_sort(array2, length) ? "Yes! :)" : "No! :(") << std::endl;
	delete[]array1;
	delete[]array2;
	return 0;
}