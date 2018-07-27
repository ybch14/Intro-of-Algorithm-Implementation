# Red Black Tree

Red black tree data structure implementation.

## Task definition

Given 100000 float numbers (*data*) , and 100000 query numbers (*query*) , search each query number in *data*. If query number is in *data*, give ```true```.

## Data Structure

```C++
class RBTNode
{
public:
	double _value;
	bool _color;
	RBTNode* _parent;
	RBTNode* _left;
	RBTNode* _right;
	RBTNode();
	RBTNode(double value, bool color, RBTNode* _null);
	~RBTNode();
	double value();
	bool color();
};

class RBTree
{
private:
	RBTNode _null;
	RBTNode* _root;
public:
	RBTree();
	~RBTree();
	RBTNode* root();
	RBTNode* null();
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
```

## Test Sample

- Insert [41, 38, 31, 12, 19, 8] and delete in [8, 12, 19, 31, 38, 41] (Sample from *Introduction of Algorithm*).
- Red black tree from [this example](http://alrightchiu.github.io/SecondRound/red-black-tree-deleteshan-chu-zi-liao-yu-fixupxiu-zheng.html).
- Randomly generated *data* and *query*. *Data* has three versions: randomed, partly sorted and totally sorted. 

## Output

```
Test Sample 1:
Insert 41 :

   41:B

----------
Insert 38 :

   41:B

        38:R

----------
Insert 31 :

        41:R

   38:B

        31:R

----------
Insert 12 :

        41:B

   38:B

        31:B

             12:R

----------
Insert 19 :

        41:B

   38:B

             31:R

        19:B

             12:R

----------
Insert 8 :

        41:B

   38:B

             31:B

        19:R

             12:B

                   8:R

----------
Delete 8 :

        41:B

   38:B

             31:B

        19:R

             12:B

----------
Delete 12 :

        41:B

   38:B

             31:R

        19:B

----------
Delete 19 :

        41:B

   38:B

        31:B

----------
Delete 31 :

        41:R

   38:B

----------
Delete 38 :

   41:B

----------
Delete 41 :

----------
Test Sample 2

                       55:R

                  52:B

                       51:R

             48:R

                  45:B

        41:B

             39:B

   36:B

                  27:B

                       24:R

             22:B

                  19:B

        16:R

                       10:B

                   9:R

                        7:B

              4:B

                   3:B

                        1:R

----------
Delete 19 :

                       55:R

                  52:B

                       51:R

             48:R

                  45:B

        41:B

             39:B

   36:B

                  27:B

             24:B

                  22:B

        16:R

                       10:B

                   9:R

                        7:B

              4:B

                   3:B

                        1:R

----------
Delete 45 :

                  55:B

             52:R

                       51:R

                  48:B

        41:B

             39:B

   36:B

                  27:B

             24:B

                  22:B

        16:R

                       10:B

                   9:R

                        7:B

              4:B

                   3:B

                        1:R

----------
Delete 39 :

             55:B

        52:B

                  51:B

             48:R

                  41:B

   36:B

                  27:B

             24:B

                  22:B

        16:R

                       10:B

                   9:R

                        7:B

              4:B

                   3:B

                        1:R

----------
Delete 7 :

             55:B

        52:B

                  51:B

             48:R

                  41:B

   36:B

                  27:B

             24:B

                  22:B

        16:R

                       10:R

                   9:B

              4:B

                   3:B

                        1:R

----------
Delete 3 :

             55:B

        52:B

                  51:B

             48:R

                  41:B

   36:B

                  27:B

             24:B

                  22:B

        16:R

                       10:R

                   9:B

              4:B

                   1:B

----------
Test Sample 3
Insert Time:
        Random  Partly Sorted   Sorted
BST     0.023   0.019           18.469
RBT     0.027   0.023           0.012
Search Time:
        Random  Partly Sorted   Sorted
BST     0.03    0.032           19.003
RBT     0.027   0.024           0.021
Search correct?
        Random  Partly Sorted   Sorted
BST     Yes     Yes             Yes
RBT     Yes     Yes             Yes
```