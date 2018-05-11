#include "heap.h"
#include <iostream>
#include <algorithm>

Heap::Heap(int max_size)
{
	_max_size = max_size;
	_heap_size = 0;
	_heap_data = new double[max_size];
	std::fill(_heap_data, _heap_data + max_size, 0.0);
}

Heap::Heap(const Heap& H)
{
	_max_size = H._max_size;
	_heap_size = H._heap_size;
	_heap_data = new double[_max_size];
	std::copy(H._heap_data, H._heap_data + H._max_size, _heap_data);
}

Heap::~Heap()
{
	delete[]_heap_data;
	_heap_data = NULL;
}

void Heap::operator=(const Heap& H)
{
	_max_size = H._max_size;
	_heap_size = H._heap_size;
	delete[]_heap_data;
	_heap_data = new double[_max_size];
	std::copy(H._heap_data, H._heap_data + H._max_size, _heap_data);
}

// heapify top-down
void Heap::_heapify(int index)
{
	int l = left(index);
	int r = right(index);
	int largest = -1;
	if ((l < _heap_size) && (_heap_data[index] < _heap_data[l]))
		largest = l;
	else
		largest = index;
	if ((r < _heap_size) && (_heap_data[largest] < _heap_data[r]))
		largest = r;
	if ((largest != index) && (largest != -1))
	{
		double tmp = _heap_data[index];
		_heap_data[index] = _heap_data[largest];
		_heap_data[largest] = tmp;
		_heapify(largest);
	}
}

// build heap bottom-up using top-down heapify, O(n)
Heap::Heap(double* data, int heap_size)
{
	_heap_size = heap_size;
	_max_size = heap_size;
	_heap_data = new double[_max_size];
	std::copy(data, data + heap_size, _heap_data);
	// 0 to int(heap_size / 2) are parent nodes
	for (int i = int(heap_size / 2) - 1; i >= 0; i--)
		_heapify(i);
}

void Heap::sort()
{
	if (_heap_size > 1)
	{
		int array_length = _heap_size; double tmp;
		for (int i = 0; i < array_length; i++)
		{
			tmp = _heap_data[0];
			_heap_data[0] = _heap_data[_heap_size - 1];
			_heap_data[_heap_size - 1] = tmp;
			_heap_size--;
			_heapify(0);
		}
	}
}
