#include <iostream>
#include <fstream>
#include <time.h>

int main()
{
	double* insert_sort(double* A, int length);
	bool test_sort(double* A, int length);
	double a[10] = {1, 5, 6, 3, 4, 5, 6, 2, 1, 0};
	double* result = insert_sort(a, 10);
	for (int i = 0; i < 10; i++)
		std::cout << result[i] << ' ';
	std::cout << std::endl;
	delete []result;
	result = NULL;

	double *array = new double[1000000];
	std::ifstream f("data.txt");
	for (int i = 0; i < 1000000; i++)
		f >> array[i];
	std::cout << "Data loaded!" << std::endl;
	clock_t start = clock();
	result = insert_sort(array, 1000000);
	std::cout << "Insert sorting: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Sort correct? " << (test_sort(result, 1000000)?"Yes! :)":"No! :(") << std::endl;
	delete []result;
	return 0;
}