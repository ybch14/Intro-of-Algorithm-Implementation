#include "binary_search_tree.h"

BST::BST()
{
	_root = NULL;
}

BST::~BST()
{
	// inorder tree walk and delete node one by one
	std::stack<Node*> s;
	std::vector<Node*> delete_buffer;
	if (_root != NULL)
	{
		s.push(_root);
		Node *cur = _root, *tmp = NULL;
		while (cur->_left != NULL)
		{
			s.push(cur->_left);
			cur = cur->_left;
		}
		while (s.size() > 0)
		{
			cur = s.top();
			s.pop();
			if (cur->_right != NULL)
			{
				s.push(cur->_right);
				tmp = cur->_right;
				while (tmp->_left != NULL)
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
}

bool BST::is_empty()
{
	return _root == NULL;
}

Node* BST::root()
{
	return _root;
}

Node* BST::search(double value)
{
	Node* cur = _root;
	while ((cur != NULL) && (cur->value() != value))
	{
		if (value < cur->value())
			cur = cur->_left;
		else
			cur = cur->_right;
	}
	return cur;
}

Node* BST::successor(Node* cur)
{
	if (cur == NULL)
		return NULL;
	// find the next node in inorder-walk sequence
	if (cur->_right != NULL)
	{
		cur = cur->_right;
		while (cur->_left != NULL)
			cur = cur->_left;
		return cur;
	}
	else
	{
		Node* tmp = cur;
		cur = cur->_parent;
		while ((cur != NULL) && (cur->_left != tmp))
		{
			tmp = cur;
			cur = cur->_parent;
		}
		return cur;
	}
}

Node* BST::predecessor(Node* cur)
{
	if (cur == NULL)
		return NULL;
	// find the previous node in inorder-walk sequence
	if (cur->_left != NULL)
	{
		cur = cur->_left;
		while (cur->_right != NULL)
			cur = cur->_right;
		return cur;
	}
	else
	{
		Node* tmp = cur;
		cur = cur->_parent;
		while ((cur != NULL) && (cur->_right != tmp))
		{
			tmp = cur;
			cur = cur->_parent;
		}
		return cur;
	}
}

void BST::insert(double value)
{
	Node* cur = _root;
	if (cur == NULL)
	{
		_root = new Node(value);
	}
	else
	{
		Node* ref = NULL;
		if (value > cur->value())
			ref = cur->_right;
		else
			ref = cur->_left;
		while (ref != NULL)
		{
			cur = ref;
			if (value > cur->value())
				ref = cur->_right;
			else
				ref = cur->_left;
		}
		if (value < cur->value())
		{
			cur->_left = new Node(value);
			cur->_left->_parent = cur;
		}
		else
		{
			cur->_right = new Node(value);
			cur->_right->_parent = cur;
		}
	}
}

void BST::remove(Node* dst)
{
	if (_root == NULL)
	{
		std::cerr << "Tree is empty!" << std::endl;
		exit(-1);
	}
	else
	{
		if ((dst->_left == NULL) && (dst->_right == NULL)) // no childs
		{
			if (dst->_parent == NULL)
				// root <--- dst
				_root = NULL;
			else
			{
				if (dst->_parent->_left == dst)
					//               root
					//               /  \
					//            node  node
					//             /
					// dst ---> node 
					dst->_parent->_left = NULL;
				else if (dst->_parent->_right == dst)
					//     root
					//     /  \
					//  node  node
					//    \
					//    node <--- dst
					dst->_parent->_right = NULL;
			}
			delete dst;
		}
		else if ((dst->_left != NULL) && (dst->_right != NULL)) // two childs
		{
			Node* suc = this->successor(dst); // no left child
			if (suc->_right != NULL)
			{
				if (suc->_parent->_left == suc)
				{
					//             root
					//             /  \
					// dst ---> node  node
					//          /  \
					//       node  node
					//             /
					//  suc ---> node
					//              \
					//              node
					suc->_parent->_left = suc->_right;
					suc->_right->_parent = suc->_parent;
				}
				else if (suc->_parent->_right == suc)
				{
					//             root
					//             /  \
					// dst ---> node  node
					//          /  \
					//       node  node <--- suc
					//                \
					//                node 
					suc->_parent->_right = suc->_right;
					suc->_right->_parent = suc->_parent;
				}
			}
			else
			{
				if (suc->_parent->_left == suc)
					//             root
					//             /  \
					// dst ---> node  node
					//          /  \
					//       node  node
					//             /
					//  suc ---> node
					suc->_parent->_left = NULL;
				else if (suc->_parent->_right == suc)
					//             root
					//             /  \
					// dst ---> node  node
					//          /  \
					//       node  node <--- suc
					suc->_parent->_right = NULL;
			}
			double tmp = suc->_value;
			suc->_value = dst->_value;
			dst->_value = tmp;
			delete suc;
		}
		else // one child
		{
			if (dst->_parent == NULL)
			{
				if (_root->_left != NULL)
					//    root <--- dst
					//    /
					// node
					_root = _root->_left;
				else if (_root->_right != NULL) 
					// root <--- dst
					//    \
					//    node
					_root = _root->_right;
				_root->_parent = NULL;
			}
			else
			{
				if (dst->_parent->_left == dst)
				{
					if (dst->_left != NULL)
					{
						//       root
						//       /
						//    node <--- dst
						//    /
						// node
						dst->_parent->_left = dst->_left;
						dst->_left->_parent = dst->_parent;
					}
					else if (dst->_right != NULL)
					{
						//   root
						//   /
						// node <--- dst
						//    \
						//    node
						dst->_parent->_left = dst->_right;
						dst->_right->_parent = dst->_parent;
					}
				}
				else if (dst->_parent->_right == dst)
				{
					if (dst->_left != NULL)
					{
						// root
						//    \
						//    node <--- dst
						//    /
						// node
						dst->_parent->_right = dst->_left;
						dst->_left->_parent = dst->_parent;
					}
					else if (dst->_right != NULL)
					{
						// root
						//    \
						//    node <--- dst
						//       \
						//       node
						dst->_parent->_right = dst->_right;
						dst->_right->_parent = dst->_parent;
					}
				}
			}
			delete dst;
		}
	}
}

void printTree(Node* root, int space, int max_width)
{
	if (root == NULL)
		return;
	// Increase distance between levels
	space += 3;
	// Process right child first
	printTree(root->_right, space, max_width);
	// Print current node after space
	std::cout << std::endl;
	for (int i = 3; i < space; i++)
		std::cout << " ";
	std::cout << std::setw(max_width) << root->_value << std::endl;
	// Process left child
	printTree(root->_left, space, max_width);
}

void BST::print(int max_width)
{
	printTree(_root, 0, max_width);
	std::cout << "----------" << std::endl;
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