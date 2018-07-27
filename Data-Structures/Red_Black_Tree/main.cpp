#include "red_black_tree.h"
#include "binary_search_tree.h"

int main()
{
	// test sample 1
	std::cout << "Test Sample 1:" << std::endl;
	double a[6] = { 41, 38, 31, 12, 19, 8 };
	RBTree T;
	for (int i = 0; i < 6; i++)
	{
		T.insert(a[i]);
		std::cout << "Insert " << a[i] << " :" << std::endl;
		T.print(5);
	}
	double b[6] = { 8, 12, 19, 31, 38, 41 };
	for (int i = 0; i < 6; i++)
	{
		T.remove(T.search(b[i]));
		std::cout << "Delete " << b[i] << " :" << std::endl;
		T.print(5);
	}
	// test sample 2
	std::cout << "Test Sample 2" << std::endl;
	void test_sample2(RBTree& T);
	RBTree TS2;
	test_sample2(TS2);
	TS2.print(5);
	double delete_seq[5] = { 19, 45, 39, 7, 3 };
	for (int i = 0; i < 5; i++)
	{
		TS2.remove(TS2.search(delete_seq[i]));
		std::cout << "Delete " << delete_seq[i] << " :" << std::endl;
		TS2.print(5);
	}
	// test sample 3
	std::cout << "Test Sample 3" << std::endl;
	bool test_search(bool* result, bool* gt, int length);
	int length = 100000;
	double* random_data = new double[length];
	double* partly_sorted_data = new double[length];
	double* totally_sorted_data = new double[length];
	double* query_seq = new double[length];
	bool* query_gt = new bool[length];
	std::fstream fp("query.txt", std::ios_base::in);
	for (int i = 0; i < length; i++)
		fp >> query_seq[i] >> query_gt[i];
	fp.close(); fp.clear();
	fp = std::fstream("random_data.txt", std::ios_base::in);
	for (int i = 0; i < length; i++)
		fp >> random_data[i];
	fp.close(); fp.clear();
	fp = std::fstream("partly_sorted_data.txt", std::ios_base::in);
	for (int i = 0; i < length; i++)
		fp >> partly_sorted_data[i];
	fp.close(); fp.clear();
	fp = std::fstream("totally_sorted_data.txt", std::ios_base::in);
	for (int i = 0; i < length; i++)
		fp >> totally_sorted_data[i];
	fp.close(); fp.clear();
	BST random_bst, partly_bst, totally_bst;
	RBTree random_rbt, partly_rbt, totally_rbt;
	bool* random_bst_result = new bool[length]; 
	std::fill(random_bst_result, random_bst_result + length * sizeof(bool), false);
	bool* partly_bst_result = new bool[length];
	std::fill(partly_bst_result, partly_bst_result + length * sizeof(bool), false);
	bool* totally_bst_result = new bool[length];
	std::fill(totally_bst_result, totally_bst_result + length * sizeof(bool), false);
	bool* random_rbt_result = new bool[length];
	std::fill(random_rbt_result, random_rbt_result + length * sizeof(bool), false);
	bool* partly_rbt_result = new bool[length];
	std::fill(partly_rbt_result, partly_rbt_result + length * sizeof(bool), false);
	bool* totally_rbt_result = new bool[length];
	std::fill(totally_rbt_result, totally_rbt_result + length * sizeof(bool), false);
	
	clock_t start = clock();
	for (int i = 0; i < length; i++)
		random_bst.insert(random_data[i]);
	double random_bst_insert_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	for (int i = 0; i < length; i++)
		partly_bst.insert(partly_sorted_data[i]);
	double partly_bst_insert_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	for (int i = 0; i < length; i++)
		totally_bst.insert(totally_sorted_data[i]);
	double totally_bst_insert_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	for (int i = 0; i < length; i++)
		random_rbt.insert(random_data[i]);
	double random_rbt_insert_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	for (int i = 0; i < length; i++)
		partly_rbt.insert(partly_sorted_data[i]);
	double partly_rbt_insert_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	for (int i = 0; i < length; i++)
		totally_rbt.insert(totally_sorted_data[i]);
	double totally_rbt_insert_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	
	start = clock();
	for (int i = 0; i < length; i++)
		if (random_bst.search(query_seq[i]) != NULL)
			random_bst_result[i] = true;
	double random_bst_search_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	for (int i = 0; i < length; i++)
		if (partly_bst.search(query_seq[i]) != NULL)
			partly_bst_result[i] = true;
	double partly_bst_search_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	for (int i = 0; i < length; i++)
		if (totally_bst.search(query_seq[i]) != NULL)
			totally_bst_result[i] = true;
	double totally_bst_search_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	for (int i = 0; i < length; i++)
		if (random_rbt.search(query_seq[i]) != random_rbt.null())
			random_rbt_result[i] = true;
	double random_rbt_search_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	for (int i = 0; i < length; i++)
		if (partly_rbt.search(query_seq[i]) != partly_rbt.null())
			partly_rbt_result[i] = true;
	double partly_rbt_search_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = clock();
	for (int i = 0; i < length; i++)
		if (totally_rbt.search(query_seq[i]) != totally_rbt.null())
			totally_rbt_result[i] = true;
	double totally_rbt_search_time = (double)(clock() - start) / CLOCKS_PER_SEC;

	bool random_bst_correct = test_search(random_bst_result, query_gt, length);
	bool partly_bst_correct = test_search(partly_bst_result, query_gt, length);
	bool totally_bst_correct = test_search(totally_bst_result, query_gt, length);
	bool random_rbt_correct = test_search(random_rbt_result, query_gt, length);
	bool partly_rbt_correct = test_search(partly_rbt_result, query_gt, length);
	bool totally_rbt_correct = test_search(totally_rbt_result, query_gt, length);

	std::cout << "Insert Time:" << std::endl;
	std::cout << "\t" << "Random\t" << "Partly Sorted\t" << "Sorted" << std::endl;
	std::cout << "BST\t" << random_bst_insert_time << "\t" 
		<< partly_bst_insert_time << "\t\t" << totally_bst_insert_time << std::endl;
	std::cout << "RBT\t" << random_rbt_insert_time << "\t"
		<< partly_rbt_insert_time << "\t\t" << totally_rbt_insert_time << std::endl;

	std::cout << "Search Time:" << std::endl;
	std::cout << "\t" << "Random\t" << "Partly Sorted\t" << "Sorted" << std::endl;
	std::cout << "BST\t" << random_bst_search_time << "\t"
		<< partly_bst_search_time << "\t\t" << totally_bst_search_time << std::endl;
	std::cout << "RBT\t" << random_rbt_insert_time << "\t"
		<< partly_rbt_search_time << "\t\t" << totally_rbt_search_time << std::endl;

	std::cout << "Search correct? " << std::endl;
	std::cout << "\t" << "Random\t" << "Partly Sorted\t" << "Sorted" << std::endl;
	std::cout << "BST\t" << (random_bst_correct?"Yes":"No") << "\t"
		<< (partly_bst_correct ? "Yes" : "No") << "\t\t" << (totally_bst_correct ? "Yes" : "No") << std::endl;
	std::cout << "RBT\t" << (random_rbt_correct ? "Yes" : "No") << "\t"
		<< (partly_rbt_correct ? "Yes" : "No") << "\t\t" << (totally_rbt_correct ? "Yes" : "No") << std::endl;
	delete[]random_data;
	delete[]partly_sorted_data;
	delete[]totally_sorted_data;
	delete[]query_seq;
	delete[]query_gt;
	delete[]random_bst_result;
	delete[]random_rbt_result;
	delete[]partly_bst_result;
	delete[]partly_rbt_result;
	delete[]totally_bst_result;
	delete[]totally_rbt_result;
	return 0;
}