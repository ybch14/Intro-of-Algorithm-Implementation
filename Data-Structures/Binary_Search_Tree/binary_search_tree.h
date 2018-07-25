#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#include <stack>
#include <time.h>
#include <vector>
#include <iomanip> // std::setw
#include <fstream>
#include <iostream>

class Node
{
public:
	double _value;
	Node* _left;
	Node* _right;
	Node* _parent;
	Node(double value)
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
	Node* _root;
public:
	BST();
	~BST();
	bool is_empty();
	Node* root();
	Node* search(double value);
	Node* successor(Node* cur);
	Node* predecessor(Node* cur);
	void insert(double value);
	void remove(Node* dst);
	void print(int max_width);
};

#endif
