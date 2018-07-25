#include "list.h"

int main()
{
	void bucket_sort(double* A, int length);
	void insert_sort(double* A, int length);
	void quick_sort(double* A, int low, int high);
	bool test_sort(double* A, int length);
	double a[12] = { 1.0, 0.2, 0.25, 0.65, 0.72, 0.881, 0.9, 0.01, 0.32, 0.98, 0.34, 1.0 };
	bucket_sort(a, 12);
	for (int i = 0; i < 12; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;

	int length = 1000000;
	double *a1 = new double[length], *a2 = new double[length], *a3 = new double[length];
	double *b1 = new double[length], *b2 = new double[length], *b3 = new double[length];
	std::ifstream f("A.txt");
	for (int i = 0; i < length; i++)
		f >> a1[i];
	std::copy(a1, a1 + length, a2);
	std::copy(a1, a1 + length, a3);
	f.close(); f.clear();
	f = std::ifstream("B.txt");
	for (int i = 0; i < length; i++)
		f >> b1[i];
	std::copy(b1, b1 + length, b2);
	std::copy(b1, b1 + length, b3);
	f.close(); f.clear();
	std::cout << "Data loaded!" << std::endl << "Uniform distributed data:" << std::endl;
	clock_t start = clock();
	bucket_sort(a1, length);
	std::cout << "Bucket sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Bucket sort correct? " << (test_sort(a1, length) ? "Yes! :)" : "No! :(") << std::endl;
	start = clock();
	quick_sort(a2, 0, length-1);
	std::cout << "Quick sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Quick sort correct? " << (test_sort(a2, length) ? "Yes! :)" : "No! :(") << std::endl;
	start = clock();
	insert_sort(a3, length);
	std::cout << "Insert sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Insert sort correct? " << (test_sort(a3, length) ? "Yes! :)" : "No! :(") << std::endl;
	std::cout << "Normal distributed data: " << std::endl;
	bucket_sort(b1, length);
	std::cout << "Bucket sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Bucket sort correct? " << (test_sort(b1, length) ? "Yes! :)" : "No! :(") << std::endl;
	start = clock();
	quick_sort(b2, 0, length - 1);
	std::cout << "Quick sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Quick sort correct? " << (test_sort(b2, length) ? "Yes! :)" : "No! :(") << std::endl;
	start = clock();
	insert_sort(b3, length);
	std::cout << "Insert sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Insert sort correct? " << (test_sort(b3, length) ? "Yes! :)" : "No! :(") << std::endl;
	delete[]a1, a2, a3, b1, b2, b3;
}