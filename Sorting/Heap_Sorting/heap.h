// max heap
#ifndef _HEAP_H
#define _HEAP_H
class Heap
{
private:
	int _max_size;
	int _heap_size;
	double* _heap_data;
	inline int parent(int index)
	{
		return int((index-1) / 2);
	}
	int left(int index)
	{
		return index * 2 + 1;
	}
	int right(int index)
	{
		return index * 2 + 2;
	}
	void _heapify(int index);
public:
	int max_size() const 
	{
		return _max_size;
	}
	int heap_size() const
	{
		return _heap_size;
	}
	double data(int index) const
	{
		return _heap_data[index];
	}
	Heap(int max_size);
	Heap(double* data, int heap_size);
	Heap(const Heap& H);
	~Heap();
	void operator=(const Heap& H);
	void sort();
};
#endif