#ifndef _ORDER_STATISTICS_TREE_H
#define _ORDER_STATISTICS_TREE_H

#define RED true
#define BLACK false

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <vector>
#include <stack> // ~OSTree


class OSTNode
{
public:
	double _value;
	bool _color;
	int _size;
	OSTNode* _parent;
	OSTNode* _left;
	OSTNode* _right;
	OSTNode()
	{
		_value = 0.0;
		_color = BLACK;
		_size = 1;
		_parent = NULL;
		_left = NULL;
		_right = NULL;
	}
	OSTNode(double value, bool color, OSTNode* _null)
	{
		_value = value;
		_color = color;
		_size = 1;
		_parent = _null;
		_left = _null;
		_right = _null;
	}
	~OSTNode()
	{
		_parent = NULL;
		_left = NULL;
		_right = NULL;
	}
	double value() { return _value; }
	bool color() { return _color; }
	int size() { return _size; }
};

class OSTree
{
private:
	OSTNode* _root;
	OSTNode _null;
public:
	OSTree();
	~OSTree();
	OSTNode* root() { return _root; }
	OSTNode* null() { return &_null; }
	OSTNode* search(double value);
	OSTNode* successor(OSTNode* cur);
	void transplant(OSTNode* src, OSTNode* dst);
	void left_rotate(OSTNode* x);
	void right_rotate(OSTNode* x);
	void insert_fixup(OSTNode* x);
	void insert(double value);
	void remove_fixup(OSTNode* x);
	void remove(OSTNode* x);
	OSTNode* select(int rank);
	int rank(OSTNode* x);
	void print(int max_width);
};

#endif