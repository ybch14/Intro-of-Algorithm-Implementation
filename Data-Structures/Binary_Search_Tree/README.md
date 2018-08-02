# Binary Search Tree

Binary Search Tree data structure implementation.

## Task Definition

Given 100000 float numbers (*data*) , and 100000 query numbers (*query*) , search each query number in *data*.

## Data Structure

```C++
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
```

## File List

- [`binary_search_tree.h`](binary_search_tree.h): BST class definition.
- [`binary_search_tree.cpp`](binary_search_tree.cpp): implementation of BST class member functions.
- [`main.cpp`](main.cpp): test samples.
- [`generate_data.py`](generate_data.py): generate test data.
- [`data.txt`](data.txt): *data* array.
- [`query.txt`](query.txt): *query* array and query results.

## Test Sample

- [15, 5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 7] (Test basis BST operations).
- Randomly generated *data* and *query*. 

## Output

```
Original Tree:

         23

      20

         18

   16

15

         13

      12

         10

                7

             6

    5

       3
----------
Delete 13:

         23

      20

         18

   16

15

      12

         10

                7

             6

    5

       3
----------
Delete 16:

      23

   20

      18

15

      12

         10

                7

             6

    5

       3
----------
Delete 10:

      23

   20

      18

15

      12

             7

          6

    5

       3
----------
Delete 5:

      23

   20

      18

15

      12

          7

    6

       3
----------
Delete 15:

      23

   20

18

      12

          7

    6

       3
----------
Data loaded!
Linear search: 4.642s.
Linear search correct? Yes! :)
BST search: 0.026s.
BST search correct? Yes! :)
```