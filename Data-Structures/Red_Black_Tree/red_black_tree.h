#ifndef _RED_BLACK_TREE_H
#define _RED_BLACK_TREE_H

#define RED true
#define BLACK false

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <vector>
#include <stack> // ~RBTree()

class RBTNode
{
public:
	double _value;
	bool _color;
	RBTNode* _parent;
	RBTNode* _left;
	RBTNode* _right;
	RBTNode()
	{
		_value = 0.0;
		_color = BLACK;
		_parent = NULL;
		_left = NULL;
		_right = NULL;
	}
	RBTNode(double value, bool color, RBTNode* _null)
	{
		_value = value;
		_color = color;
		_parent = _null;
		_left = _null;
		_right = _null;
	}
	~RBTNode()
	{
		_parent = NULL;
		_left = NULL;
		_right = NULL;
	}
	double value() { return _value; }
	bool color() { return _color;	}
};

class RBTree
{
private:
	RBTNode _null;
	RBTNode* _root;
public:
	RBTree();
	~RBTree();
	RBTNode* root() { return _root; }
	RBTNode* null() { return &_null; }
	RBTNode* search(double value);
	RBTNode* successor(RBTNode* cur);
	void transplant(RBTNode* src, RBTNode* dst);
	void left_rotate(RBTNode* x);
	void right_rotate(RBTNode* x);
	void insert_fixup(RBTNode* x);
	void insert(double value);
	void remove_fixup(RBTNode* x);
	void remove(RBTNode* dst);
	void print(int max_width);
};

#endif
