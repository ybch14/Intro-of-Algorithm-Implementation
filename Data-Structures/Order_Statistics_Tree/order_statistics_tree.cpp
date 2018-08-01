#include "order_statistics_tree.h"

OSTree::OSTree()
{
	_null._color = BLACK;
	_null._size = 0;
	_null._parent = NULL;
	_null._left = NULL;
	_null._right = NULL;
	_root = &_null;
}

OSTree::~OSTree()
{
	// inorder walk stack
	std::stack<OSTNode*> s;
	// save deleted nodes in order
	std::vector<OSTNode*> delete_buffer;
	OSTNode* cur = _root;
	while (cur != &_null)
	{
		s.push(cur);
		cur = cur->_left;
	}
	OSTNode* tmp = &_null;
	while (s.size() > 0)
	{
		cur = s.top();
		s.pop();
		if (cur->_right != &_null)
		{
			s.push(cur->_right);
			tmp = cur->_right;
			while (tmp->_left != &_null)
			{
				s.push(tmp->_left);
				tmp = tmp->_left;
			}
		}
		delete_buffer.push_back(cur);
	}
	for (int i = 0; i < (int)delete_buffer.size(); i++)
		delete delete_buffer[i];
}

OSTNode* OSTree::search(double value)
{
	OSTNode* cur = _root;
	while ((cur != &_null) && (cur->_value != value))
	{
		if (value < cur->_value)
			cur = cur->_left;
		else
			cur = cur->_right;
	}
	return cur;
}

OSTNode* OSTree::successor(OSTNode* cur)
{
	if (cur == &_null)
		return &_null;
	OSTNode* tmp = &_null;
	if (cur->_right != &_null)
	{
		tmp = cur->_right;
		while (tmp->_left != &_null)
			tmp = tmp->_left;
	}
	else
	{
		tmp = cur->_parent;
		while ((tmp != &_null) && (tmp->_left != cur))
		{
			tmp = tmp->_parent;
			cur = cur->_parent;
		}
	}
	return tmp;
}

void OSTree::transplant(OSTNode* src, OSTNode* dst)
{
	if (src == _root)
	{
		_root = dst;
		_root->_parent = &_null;
	}
	else
	{
		dst->_parent = src->_parent;
		if (src->_parent->_left == src)
			src->_parent->_left = dst;
		else
			src->_parent->_right = dst;
	}
}

void OSTree::left_rotate(OSTNode* x)
{
	OSTNode* y = x->_right;
	x->_right = y->_left;
	if (y->_left != &_null)
		y->_left->_parent = x;
	y->_parent = x->_parent;
	if (x->_parent == &_null)
		_root = y;
	else if (x->_parent->_left == x)
		x->_parent->_left = y;
	else
		x->_parent->_right = y;
	y->_left = x;
	x->_parent = y;
	y->_size = x->_size;
	x->_size = x->_left->_size + x->_right->_size + 1;
}

void OSTree::right_rotate(OSTNode* x)
{
	OSTNode* y = x->_left;
	x->_left = y->_right;
	if (y->_right != &_null)
		y->_right->_parent = x;
	y->_parent = x->_parent;
	if (x->_parent == &_null)
		_root = y;
	else if (x->_parent->_left == x)
		x->_parent->_left = y;
	else
		x->_parent->_right = y;
	y->_right = x;
	x->_parent = y;
	y->_size = x->_size;
	x->_size = x->_left->_size + x->_right->_size + 1;
}

void OSTree::insert_fixup(OSTNode* z)
{
	while (z->_parent->_color == RED)
	{
		if (z->_parent->_parent->_left == z->_parent)
		{
			OSTNode* uncle = z->_parent->_parent->_right;
			if (uncle->_color == RED)
			{
				z->_parent->_color = BLACK;
				uncle->_color = BLACK;
				z->_parent->_parent->_color = RED;
				z = z->_parent->_parent;
			}
			else
			{
				if (z->_parent->_right == z)
				{
					z = z->_parent;
					this->left_rotate(z);
				}
				z->_parent->_color = BLACK;
				z->_parent->_parent->_color = RED;
				this->right_rotate(z->_parent->_parent);
			}
		}
		else
		{
			OSTNode* uncle = z->_parent->_parent->_left;
			if (uncle->_color == RED)
			{
				z->_parent->_color = BLACK;
				uncle->_color = BLACK;
				z->_parent->_parent->_color = RED;
				z = z->_parent->_parent;
			}
			else
			{
				if (z->_parent->_left == z)
				{
					z = z->_parent;
					this->right_rotate(z);
				}
				z->_parent->_color = BLACK;
				z->_parent->_parent->_color = RED;
				this->left_rotate(z->_parent->_parent);
			}
		}
	}
	_root->_color = BLACK;
}

void OSTree::insert(double value)
{
	if (_root == &_null)
	{
		_root = new OSTNode(value, BLACK, &_null);
	}
	else
	{
		OSTNode* cur = _root, *tmp = &_null;
		if (value < cur->_value)
			tmp = cur->_left;
		else
			tmp = cur->_right;
		while (tmp != &_null)
		{
			cur->_size += 1;
			cur = tmp;
			if (value < cur->_value)
				tmp = cur->_left;
			else
				tmp = cur->_right;
		}
		cur->_size += 1;
		if (value < cur->_value)
		{
			cur->_left = new OSTNode(value, RED, &_null);
			cur->_left->_parent = cur;
			this->insert_fixup(cur->_left);
		}
		else
		{
			cur->_right = new OSTNode(value, RED, &_null);
			cur->_right->_parent = cur;
			this->insert_fixup(cur->_right);
		}
	}
}

void OSTree::remove_fixup(OSTNode* x)
{
	while ((x != _root) && (x->_color == BLACK))
	{
		if (x->_parent->_left == x)
		{
			OSTNode* w = x->_parent->_right;
			if (w->_color == RED)
			{
				x->_parent->_color = RED;
				w->_color = BLACK;
				this->left_rotate(x->_parent);
				w = x->_parent->_right;
			}
			if ((w->_left->_color == BLACK) && (w->_right->_color == BLACK))
			{
				w->_color = RED;
				x = x->_parent;
			}
			else
			{
				if (w->_right->_color == BLACK)
				{
					w->_left->_color = BLACK;
					w->_color = RED;
					this->right_rotate(w);
					w = x->_parent->_right;
				}
				w->_color = x->_parent->_color;
				x->_parent->_color = BLACK;
				w->_right->_color = BLACK;
				this->left_rotate(x->_parent);
				x = _root;
			}
		}
		else
		{
			OSTNode* w = x->_parent->_left;
 			if (w->_color == RED)
			{
				x->_parent->_color = RED;
				w->_color = BLACK;
				this->right_rotate(x->_parent);
				w = x->_parent->_left;
			}
			if ((w->_left->_color == BLACK) && (w->_right->_color == BLACK))
			{
				w->_color = RED;
				x = x->_parent;
			}
			else
			{
				if (w->_left->_color == BLACK)
				{
					w->_right->_color = BLACK;
					w->_color = RED;
					this->left_rotate(w);
					w = x->_parent->_right;
				}
				w->_color = x->_parent->_color;
				x->_parent->_color = BLACK;
				w->_left->_color = BLACK;
				this->right_rotate(x->_parent);
				x = _root;
			}
		}
	}
	x->_color = BLACK;
}

void OSTree::remove(OSTNode* z)
{
	if (_root == &_null)
	{
		std::cerr << "Tree is empty!" << std::endl;
		exit(-1);
	}
	else if (z == &_null)
	{
		return;
	}
	else
	{
		OSTNode* y = z, *x = &_null;
		bool y_original_color = y->_color;
		if (z->_left == &_null)
		{
			OSTNode* tmp = z;
			while (tmp != _root)
			{
				tmp->_size -= 1;
				tmp = tmp->_parent;
			}
			_root->_size -= 1;
			x = z->_right;
			transplant(z, z->_right);
			delete z;
		}
		else if (z->_right == &_null)
		{
			OSTNode* tmp = z;
			while (tmp != _root)
			{
				tmp->_size -= 1;
				tmp = tmp->_parent;
			}
			_root->_size -= 1;
			x = z->_left;
			transplant(z, z->_left);
			delete z;
		}
		else
		{
			y = this->successor(z);
			y_original_color = y->_color;
			OSTNode* tmp = y;
			while (tmp != _root)
			{
				tmp->_size -= 1;
				tmp = tmp->_parent;
			}
			_root->_size -= 1;
			x = y->_right;
			if (y->_parent == z)
				x->_parent = y;
			else
			{
				transplant(y, y->_right);
				y->_right = z->_right;
				y->_right->_parent = y;
			}
			transplant(z, y);
			y->_left = z->_left;
			y->_left->_parent = y;
			y->_color = z->_color;
			y->_size = z->_size;
			delete z;
		}
		if (y_original_color == BLACK)
			remove_fixup(x);
	}
}

OSTNode* OSTree::select(int rank)
{
	// rank starts from 0
	if (_root == &_null)
	{
		std::cerr << "Tree is empty!" << std::endl;
		exit(-1);
	}
	else
	{
		rank += 1;
		OSTNode* cur = _root;
		int r = cur->_left->_size + 1;
		while (r != rank)
		{
			if (r > rank)
				cur = cur->_left;
			else
			{
				cur = cur->_right;
				rank -= r;
			}
			r = cur->_left->_size + 1;
		}
		return cur;
	}
}

int OSTree::rank(OSTNode* x)
{
	// rank starts from 0
	int r = x->_left->_size + 1;
	OSTNode* y = x;
	while (y != _root)
	{
		if (y == y->_parent->_right)
			r += y->_parent->_left->_size + 1;
		y = y->_parent;
	}
	return r - 1;
}

void printTree(OSTNode* root, int space, int max_width, OSTNode* _null)
{
	if (root == NULL)
		return;
	// Increase distance between levels
	space += 5;
	// Process right child first
	printTree(root->_right, space, max_width, _null);
	// Print current node after space
	for (int i = 5; i < space; i++)
		std::cout << " ";
	if (root != _null)
		std::cout << std::setw(max_width) << root->_value << ":" 
			<< (root->_color ? "R" : "B") << ":" << root->_size << std::endl;
	else
		std::cout << std::endl;
	// Process left child
	printTree(root->_left, space, max_width, _null);
}

void OSTree::print(int max_width)
{
	printTree(_root, 0, max_width, &_null);
	std::cout << "----------" << std::endl;
}
