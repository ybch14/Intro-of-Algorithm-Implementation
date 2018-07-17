#include <iostream>
#include <fstream>
#include <time.h>
#include "binary_search_tree.h"

int main()
{
	void printTree(Node* root, int space);
	bool test_search(bool* result, bool* gt, int length);
	double data[12] = { 15., 5., 16., 3.,
					   12., 20., 10., 13.,
					   18., 23., 6., 7. };
	int max_width = 2;
	BST tree;
	for (int i = 0; i < 12; i++)
		tree.insert(data[i]);
	std::cout << "Original Tree:" << std::endl;
	tree.print(max_width);
	tree.remove(tree.root()->_left->_right->_right);
	std::cout << "Delete 13:" << std::endl;
	tree.print(max_width);
	tree.remove(tree.root()->_right);
	std::cout << "Delete 16:" << std::endl;
	tree.print(max_width);
	tree.remove(tree.root()->_left->_right->_left);
	std::cout << "Delete 10:" << std::endl;
	tree.print(max_width);
	tree.remove(tree.root()->_left);
	std::cout << "Delete 5:" << std::endl;
	tree.print(max_width);
	tree.remove(tree.root());
	std::cout << "Delete 15:" << std::endl;
	tree.print(max_width);
	for (int i = 0; i < 7; i++)
		tree.remove(tree.root());

	int length = 100000;
	double *bst_data = new double[length];
	double *query_seq = new double[length];
	bool *query_gt = new bool[length];
	std::fstream fp("query.txt", std::ios_base::in);
	for (int i = 0; i < length; i++)
		fp >> query_seq[i] >> query_gt[i];
	fp.close(); fp.clear();
	std::fstream data_fp("data.txt", std::ios_base::in);
	for (int i = 0; i < length; i++)
		data_fp >> bst_data[i];
	BST query_tree;
	for (int i = 0; i < length; i++)
		query_tree.insert(bst_data[i]);
	bool *bst_query_result = new bool[length];
	bool *lin_query_result = new bool[length];
	for (int i = 0; i < length; i++)
	{
		bst_query_result[i] = false;
		lin_query_result[i] = false;
	}
	std::cout << "Data loaded!" << std::endl;
	clock_t start = clock();
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (query_seq[i] == bst_data[j])
			{
				lin_query_result[i] = true;
				break;
			}
		}		
	}
	std::cout << "Linear search: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s." << std::endl;
	std::cout << "Linear search correct? " << (test_search(lin_query_result, query_gt, length) ? "Yes! :)" : "No! :(") << std::endl;

	start = clock();
	for (int i = 0; i < length; i++)
		if (query_tree.search(query_seq[i]) != NULL)
			bst_query_result[i] = true;
	std::cout << "BST search: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s." << std::endl;
	std::cout << "BST search correct? " << (test_search(bst_query_result, query_gt, length) ? "Yes! :)" : "No! :(") << std::endl;
	return 0;
}