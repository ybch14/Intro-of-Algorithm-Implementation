#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#include <stack>
#include <time.h>
#include <vector>
#include <iomanip> // std::setw
#include <fstream>
#include <iostream>

class BSTNode
{
public:
	double _value;
	BSTNode* _left;
	BSTNode* _right;
	BSTNode* _parent;
	BSTNode(double value)
	{
		_value = value;
		_left = NULL;
		_right = NULL;
		_parent = NULL;
	}
	double value()
	{
		return _value;
	}
};

class BST
{
private:
	BSTNode* _root;
public:
	BST();
	~BST();
	bool is_empty();
	BSTNode* root();
	BSTNode* search(double value);
	BSTNode* successor(BSTNode* cur);
	BSTNode* predecessor(BSTNode* cur);
	void insert(double value);
	void remove(BSTNode* dst);
	void print(int max_width);
};

#endif
