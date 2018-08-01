# Order Statistics Tree

Order statistics tree (a extension of red-black tree) algorithm implementation. 

## Task Definition

Given a 1000000 double array `data` and a 100 int array `query`,
 find the `query[i]`th element of `data`.

## Data Structure


```C++
class OSTNode
{
public:
	double _value;
	bool _color;
	int _size;
	OSTNode* _parent;
	OSTNode* _left;
	OSTNode* _right;
	OSTNode();
	OSTNode(double value, bool color, OSTNode* _null);
	~OSTNode();
	double value();
	bool color();
	int size();
};

class OSTree
{
private:
	OSTNode* _root;
	OSTNode _null;
public:
	OSTree();
	~OSTree();
	OSTNode* root();
	OSTNode* null();
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
```

## Test Sample

- [19, 123, 323, 2, 36, 438, 110, 24, 441, 57, 13, 980, 20, 3, 231, 46, 213, 8, 45, 1]
(Test linear order statistics algorithm's correctness)
- [19, 123, 323, 2, 36, 438, 110, 24, 441, 57, 13, 980, 20, 3, 231, 46, 213, 8, 45, 1]
(Test order statistics tree's correctness and memory robustness)
- Randomly generated `data` and `query`.

## Output

```
Test Sample 1:
1 2 3 8 13 19 20 24 36 45 46 57 110 123 213 231 323 438 441 980
Test Sample 2:
Select Result:
1 2 3 8 13 19 20 24 36 45 46 57 110 123 213 231 323 438 441 980
Rank Result:
5 13 16 1 8 17 12 7 18 11 4 19 6 2 15 10 14 3 9 0
Test Sample 3:
Data loaded!
Linear select: 23.827s.
Linear select correct? Yes :)
Tree select: 0s.
Tree select correct? Yes :)
```