# Bucket Sort

Bucket sort algorithm implementation.

## Task definition

Sort an array (ranges from 0 to 1) from small to large.

## Data structure

```C++
class List
{
private:
	int _list_size;
	int _mem_size;
	double* _list_data;
public:
	List();
	List(int list_size);
	List(double* data, int list_size);
	List(const List& L);
	~List();
	void operator=(List& L);
	int size() const;
    double data(int index) const;
	void insert(double data);
	void sort();
	friend void bucket_sort(double* A, int length);
};
```

## File List

- [`list.h`](list.h): list class definition.
- [`list.cpp`](list.cpp): list class member function implementation.
- [`bucket_sort.cpp`](bucket_sort.cpp): implementation of bucket sort (also includes insert/quick sort for comparison).
- [`main.cpp`](main.cpp): test samples.
- [`A.txt`](A.txt): uniform distributed array to be sorted.
- [`B.txt`](B.txt): normal distributed array to be sorted.

## Test sample

- [1.0, 0.2, 0.25, 0.65, 0.72, 0.881, 0.9, 0.01, 0.32, 0.98, 0.34, 1.0]
- Uniformed distributed 1000000 array from 0 to 1.
- Normal distributed 1000000 array from 0 to 1.

## Output

```
0.01 0.2 0.25 0.32 0.34 0.65 0.72 0.881 0.9 0.98 1 1
Data loaded!
Uniform distributed data:
Bucket sort: 0.31s.
Bucket sort correct? Yes! :)
Quick sort: 0.092s.
Quick sort correct? Yes! :)
Insert sort: 144.145s.
Insert sort correct? Yes! :)
Normal distributed data:
Bucket sort: 144.401s.
Bucket sort correct? Yes! :)
Quick sort: 0.085s.
Quick sort correct? Yes! :)
Insert sort: 154.383s.
Insert sort correct? Yes! :)
```