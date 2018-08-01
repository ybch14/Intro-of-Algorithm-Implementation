#include "order_statistics_tree.h"

int main()
{
	bool test_order_statistics(double* result, double* gt, int length);
	// Test sample 1
	std::cout << "Test Sample 1:" << std::endl;
	double select(double* A, int low, int high, int rank);
	double a[20] = { 19, 123, 323, 2, 36, 438, 110, 24, 441, 57,
					 13, 980, 20, 3, 231, 46, 213, 8, 45, 1};
	for (int i = 0; i < 20; i++)
		std::cout << select(a, 0, 19, i) << ' ';
	std::cout << std::endl;
	// Test sample 2
	OSTree T;
	double b[20] = { 19, 123, 323, 2, 36, 438, 110, 24, 441, 57,
					 13, 980, 20, 3, 231, 46, 213, 8, 45, 1 };
	std::cout << "Test Sample 2:" << std::endl;
	for (int i = 0; i < 20; i++)
		T.insert(b[i]);
	// T.print(5);
	std::cout << "Select Result:" << std::endl;
	for (int i = 0; i < 20; i++)
		std::cout << T.select(i)->value() << ' ';
	std::cout << std::endl << "Rank Result:" << std::endl;
	for (int i = 0; i < 20; i++)
		std::cout << T.rank(T.search(b[i])) << ' ';
	std::cout << std::endl;
	for (int i = 0; i < 20; i++)
		T.remove(T.search(b[i]));
	// Test Sample 3
	std::cout << "Test Sample 3:" << std::endl;
	int data_length = 1000000;
	int query_length = 100;
	double* data = new double[data_length];
	double* data_copy = new double[data_length];
	int* query = new int[query_length];
	double* query_gt = new double[query_length];
	std::fstream fp("data.txt", std::ios_base::in);
	for (int i = 0; i < data_length; i++)
	{
		fp >> data[i];
		data_copy[i] = data[i];
	}
	fp.close(); fp.clear();
	fp = std::fstream("query.txt", std::ios_base::in);
	for (int i = 0; i < query_length; i++)
		fp >> query_gt[i] >> query[i];
	fp.close(); fp.clear();
	double* linear_result = new double[query_length];
	double* tree_result = new double[query_length];
	std::cout << "Data loaded!" << std::endl;
	clock_t start = clock();
	for (int i = 0; i < query_length; i++)
		linear_result[i] = select(data, 0, data_length - 1, query[i]);
	std::cout << "Linear select: " << (double)(clock()-start) / CLOCKS_PER_SEC << "s." << std::endl;
	std::cout << "Linear select correct? " <<
		(test_order_statistics(linear_result, query_gt, query_length) ? "Yes :)" : "No :(") << std::endl;
	OSTree ost;
	for (int i = 0; i < data_length; i++)
		ost.insert(data_copy[i]);
	start = clock();
	for (int i = 0; i < query_length; i++)
		tree_result[i] = ost.select(query[i])->value();
	std::cout << "Tree select: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s." << std::endl;
	std::cout << "Tree select correct? " <<
		(test_order_statistics(tree_result, query_gt, query_length) ? "Yes :)" : "No :(") << std::endl;
	delete[]linear_result;
	delete[]tree_result;
	delete[]data;
	delete[]query;
	delete[]data_copy;
	delete[]query_gt;
	return 0;
}