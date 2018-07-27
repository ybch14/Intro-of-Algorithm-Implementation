#include "red_black_tree.h"

void test_sample2(RBTree& T)
{
	T.insert(36);
	T.root()->_left = new RBTNode(16, RED, T.null());
	T.root()->_left->_parent = T.root();
	T.root()->_right = new RBTNode(41, BLACK, T.null());
	T.root()->_right->_parent = T.root();
	T.root()->_left->_left = new RBTNode(4, BLACK, T.null());
	T.root()->_left->_left->_parent = T.root()->_left;
	T.root()->_left->_right = new RBTNode(22, BLACK, T.null());
	T.root()->_left->_right->_parent = T.root()->_left;
	T.root()->_right->_left = new RBTNode(39, BLACK, T.null());
	T.root()->_right->_left->_parent = T.root()->_right;
	T.root()->_right->_right = new RBTNode(48, RED, T.null());
	T.root()->_right->_right->_parent = T.root()->_right;
	T.root()->_left->_left->_left = new RBTNode(3, BLACK, T.null());
	T.root()->_left->_left->_left->_parent = T.root()->_left->_left;
	T.root()->_left->_left->_right = new RBTNode(9, RED, T.null());
	T.root()->_left->_left->_right->_parent = T.root()->_left->_left;
	T.root()->_left->_right->_left = new RBTNode(19, BLACK, T.null());
	T.root()->_left->_right->_left->_parent = T.root()->_left->_right;
	T.root()->_left->_right->_right = new RBTNode(27, BLACK, T.null());
	T.root()->_left->_right->_right->_parent = T.root()->_left->_right;
	T.root()->_right->_right->_left = new RBTNode(45, BLACK, T.null());
	T.root()->_right->_right->_left->_parent = T.root()->_right->_right;
	T.root()->_right->_right->_right = new RBTNode(52, BLACK, T.null());
	T.root()->_right->_right->_right->_parent = T.root()->_right->_right;
	T.root()->_left->_left->_left->_left = new RBTNode(1, RED, T.null());
	T.root()->_left->_left->_left->_left->_parent = T.root()->_left->_left->_left;
	T.root()->_left->_left->_right->_left = new RBTNode(7, BLACK, T.null());
	T.root()->_left->_left->_right->_left->_parent = T.root()->_left->_left->_right;
	T.root()->_left->_left->_right->_right = new RBTNode(10, BLACK, T.null());
	T.root()->_left->_left->_right->_right->_parent = T.root()->_left->_left->_right;
	T.root()->_left->_right->_right->_left = new RBTNode(24, RED, T.null());
	T.root()->_left->_right->_right->_left->_parent = T.root()->_left->_right->_right;
	T.root()->_right->_right->_right->_left = new RBTNode(51, RED, T.null());
	T.root()->_right->_right->_right->_left->_parent = T.root()->_right->_right->_right;
	T.root()->_right->_right->_right->_right = new RBTNode(55, RED, T.null());
	T.root()->_right->_right->_right->_right->_parent = T.root()->_right->_right->_right;
}

bool test_search(bool* result, bool* gt, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (result[i] != gt[i])
			return false;
	}
	return true;
}