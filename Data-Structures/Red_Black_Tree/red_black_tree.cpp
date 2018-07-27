#include "red_black_tree.h"

RBTree::RBTree()
{
	_null._color = BLACK;
	_null._parent = NULL;
	_null._left = NULL;
	_null._right = NULL;
	_root = &_null;
}

RBTree::~RBTree()
{
	// inorder tree walk and delete node one by one 
	std::stack<RBTNode*> s; // inorder tree walk stack
	std::vector<RBTNode*> delete_buffer; // save undeleted node in order
	if (_root != &_null)
	{
		s.push(_root);
		RBTNode* cur = _root;
		while (cur->_left != &_null)
		{
			s.push(cur->_left);
			cur = cur->_left;
		}
		RBTNode* tmp = &_null;
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
		for (int i = 0; i < int(delete_buffer.size()); i++)
			delete delete_buffer[i];
	}
}

RBTNode* RBTree::search(double value)
{
	RBTNode* cur = _root;
	while ((cur != &_null) && (cur->_value != value))
	{
		if (value < cur->_value)
			cur = cur->_left;
		else
			cur = cur->_right;
	}
	return cur;
}

RBTNode* RBTree::successor(RBTNode* cur)
{
	if (cur == &_null)
		return &_null;
	RBTNode* tmp = &_null;
	if (cur->_right != &_null)
	{
		tmp = cur->_right;
		while (tmp->_left != &_null)
			tmp = tmp->_left;
		return tmp;
	}
	else
	{
		tmp = cur->_parent;
		while ((tmp != &_null) && (tmp->_left != cur))
		{
			tmp = tmp->_parent;
			cur = cur->_parent;
		}
		return tmp;
	}
}

void RBTree::transplant(RBTNode* src, RBTNode* dst)
{
	if (src == _root)
		_root = dst;
	else
	{
		dst->_parent = src->_parent;
		if (src->_parent->_left == src)
			src->_parent->_left = dst;
		else
			src->_parent->_right = dst;
	}
}

void RBTree::left_rotate(RBTNode* x)
{
	RBTNode* y = x->_right;
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
}

void RBTree::right_rotate(RBTNode* x)
{
	RBTNode* y = x->_left;
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
}

void RBTree::insert_fixup(RBTNode* z)
{
	// Fix up broken red-black properties when insert nodes.
	// Red black properties:
	//     1. RBTNode color is either red or black;
	//     2. Root node is black;
	//     3. Leaf node (NULL) is black;
	//     4. Red nodes' children are all black;
	//     5. For each node, all simple paths from the node to NULL
	//        contain the same number of black nodes.
	// Inserted node is colored red, so property 2 and 4 can be violated.
	// The condition that needs to fix up is z->_parent->_color is RED.
	// If z->_parent == _root, then z->_parent is black, jump to the last line.
	// If z->_parent->_color == RED, then z->_parent->_parent exists.
	while (z->_parent->_color == RED)
	{
		if (z->_parent->_parent->_left == z->_parent)
		{
			RBTNode* uncle = z->_parent->_parent->_right;
			// case 1, z's parent and uncle are RED
			// color z's parent and uncle BLACK
			// color z's grandparent RED, which can violate red-black properties
			// so set z's grandparent as new z
			if (uncle->_color == RED)
			{
				z->_parent->_color = BLACK;
				uncle->_color = BLACK;
				z->_parent->_parent->_color = RED;
				z = z->_parent->_parent;
			}
			else
			{
				// case 2, z = z->_parent->_right
				// left rotate z->_parent 
				// turn to case 3
				if (z->_parent->_right == z)
				{
					z = z->_parent;
					this->left_rotate(z);
				}
				// case 3, z = z->_parent->_left
				// color z's parent black to balance with z's uncle
				// color z's grandparent red to balance the additional black node
				// right rotate so that the subtree root is black
				z->_parent->_color = BLACK;
				z->_parent->_parent->_color = RED;
				this->right_rotate(z->_parent->_parent);
			}
		}
		else
		{
			RBTNode* uncle = z->_parent->_parent->_left;
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

void RBTree::insert(double value)
{
	RBTNode* cur = _root;
	if (cur == &_null)
	{
		_root = new RBTNode(value, BLACK, &_null);
	}
	else
	{
		RBTNode* tmp = &_null;
		if (value < cur->_value)
			tmp = cur->_left;
		else
			tmp = cur->_right;
		while (tmp != &_null)
		{
			cur = tmp;
			if (value < cur->_value)
				tmp = cur->_left;
			else
				tmp = cur->_right;
		}
		if (value < cur->_value)
		{
			cur->_left = new RBTNode(value, RED, &_null);
			cur->_left->_parent = cur;
			this->insert_fixup(cur->_left);
		}
		else
		{
			cur->_right = new RBTNode(value, RED, &_null);
			cur->_right->_parent = cur;
			this->insert_fixup(cur->_right);
		}
	}
}

void RBTree::remove_fixup(RBTNode* x)
{
	// Fix up broken red-black properties when remove nodes.
	// Red black properties:
	//     1. RBTNode color is either red or black;
	//     2. Root node is black;
	//     3. Leaf node (NULL) is black;
	//     4. Red nodes' children are all black;
	//     5. For each node, all simple paths from the node to NULL
	//        contain the same number of black nodes.
	// Deleting a node may cause violating property 5.
	// When deleting a node and call remove_fixup, the pointer x contains an 
	// extra black count, so we need to move x's extra black count until x 
	// points to a red node, or x point to tree's root node (add a black count
	// on root node doesn't violate property 5).
	while ((x != _root) && (x->_color == BLACK))
	{
		if (x->_parent->_left == x)
		{
			// w cannot be _null, otherwise will violate property 5.
			RBTNode* w = x->_parent->_right;
			// case 1, brother's color is RED
			// switch color and left rotate
			// turn to case 2, 3 or 4
			if (w->_color == RED)
			{
				//std::cout << "Case 1" << std::endl;
				x->_parent->_color = RED;
				w->_color = BLACK;
				this->left_rotate(x->_parent);
				w = x->_parent->_right;
			}
			// case 2, brother's color is BLACK
			// brother's two children are all BLACK (or NULL)
			// switch brother's color and move x to x's parent
			if ((w->_left->_color == BLACK) && (w->_right->_color == BLACK))
			{
				//std::cout << "Case 2" << std::endl;
				w->_color = RED;
				x = x->_parent;
			}
			else
			{
				// case 3, brother's color is BLACK
				// brother's left child is RED and right children is BLACK
				// switch w and w->_left's color and right rotate
				// turn to case 4
				if (w->_right->_color == BLACK)
				{
					//std::cout << "Case 3" << std::endl;
					w->_color = RED;
					w->_left->_color = BLACK;
					this->right_rotate(w);
					w = x->_parent->_right;
				}
				// case 4, brother's color is BLACK
				// brother's right child is RED
				// switch some colors and some rotations
				// terminate the loop
				//std::cout << "Case 4" << std::endl;
				w->_color = x->_parent->_color;
				x->_parent->_color = BLACK;
				w->_right->_color = BLACK;
				this->left_rotate(x->_parent);
				x = _root;
			}
		}
		else
		{
			RBTNode* w = x->_parent->_left;
			if (w->_color == RED)
			{
				x->_parent->_color = RED;
				w->_color = BLACK;
				this->right_rotate(x->_parent);
				w = x->_parent->_left;
			}
			if ((w->_left->_color == BLACK) &&(w->_right->_color == BLACK))
			{
				w->_color = RED;
				x = x->_parent;
			}
			else
			{
				if (w->_left->_color == BLACK)
				{
					w->_color = RED;
					w->_right->_color = BLACK;
					this->left_rotate(w);
					w = x->_parent->_left;
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

void RBTree::remove(RBTNode* z)
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
		RBTNode* x = &_null, *y = z;
		bool y_original_color = y->_color;
		if (z->_left == &_null)
		{
			x = z->_right;
			transplant(z, z->_right);
			delete z;
		}
		else if (z->_right == &_null)
		{
			x = z->_left;
			transplant(z, z->_left);
			delete z;
		}
		else
		{
			y = successor(z);
			y_original_color = y->_color;
			x = y->_right; // y is z's successor, so y does not have left child
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
			delete z;
		}
		if (y_original_color == BLACK)
			remove_fixup(x);
	}
}

void printTree(RBTNode* root, int space, int max_width, RBTNode* _null)
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
		std::cout << std::setw(max_width) << root->_value << ":" << (root->_color ? "R" : "B") << std::endl;
	else
		std::cout << std::endl;
	// Process left child
	printTree(root->_left, space, max_width, _null);
}

void RBTree::print(int max_width)
{
	printTree(_root, 0, max_width, &_null);
	std::cout << "----------" << std::endl;
}
