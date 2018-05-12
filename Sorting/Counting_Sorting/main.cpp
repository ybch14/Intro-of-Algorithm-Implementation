#include <iostream>
#include <fstream>
#include <time.h>

int main()
{
	void counting_sort(int* A, int length, int upbound);
	void quick_sort(int* A, int low, int high);
	void insert_sort(int* A, int length);
	bool test_sort(int* A, int length);
	int a[10] = { 1, 5, 6, 3, 4, 5, 6, 2, 1, 0 };
	counting_sort(a, 10, 6);
	for (int i = 0; i < 10; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;

	int b[8] = { 2, 5, 3, 1, 2, 3, 1, 3 };
	counting_sort(b, 8, 5);
	for (int i = 0; i < 8; i++)
		std::cout << b[i] << ' ';
	std::cout << std::endl;

	int length = 1000000, upbound = 100000;
	std::ifstream f("data.txt");
	int *c1 = new int[length];
	for (int i = 0; i < length; i++)
		f >> c1[i];
	int *c2 = new int[length], *c3 = new int[length];
	std::copy(c1, c1 + length, c2);
	std::copy(c1, c1 + length, c3);
	std::cout << "Data loaded!" << std::endl;
	clock_t start = clock();
	counting_sort(c1, length, upbound);
	std::cout << "Counting sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Counting sort correct? " << (test_sort(c1, length)?"Yes! :)":"No! :(") << std::endl;
	start = clock();
	quick_sort(c2, 0, length - 1);
	std::cout << "Quick sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Quick sort correct? " << (test_sort(c2, length) ? "Yes! :)" : "No! :(") << std::endl;
	start = clock();
	insert_sort(c3, length);
	std::cout << "Insert sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Insert sort correct? " << (test_sort(c3, length) ? "Yes! :)" : "No! :(") << std::endl;
}