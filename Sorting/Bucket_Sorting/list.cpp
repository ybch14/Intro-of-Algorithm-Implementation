#include <algorithm>
#include <iostream>
#include "list.h"

List::List()
{
	_list_size = 0;
	_mem_size = 10;
	_list_data = new double[_mem_size];
}

List::List(int list_size)
{
	_list_size = list_size;
	_mem_size = list_size;
	_list_data = new double[_mem_size];
	std::fill(_list_data, _list_data + list_size, 0.0);
}

List::List(double* data, int list_size)
{
	_list_size = list_size;
	_mem_size = list_size;
	_list_data = new double[_mem_size];
	std::copy(data, data + _list_size, _list_data);
}

List::List(const List& L)
{
	_list_size = L._list_size;
	_mem_size = L._mem_size;
	_list_data = new double[_mem_size];
	std::copy(L._list_data, L._list_data + _list_size, _list_data);
}

List::~List()
{
	delete[]_list_data;
}

void List::operator=(List& L)
{
	delete[]_list_data;
	_list_size = L._list_size;
	_mem_size = L._mem_size;
	_list_data = new double[_mem_size];
	std::copy(L._list_data, L._list_data + _list_size, _list_data);
}

void List::insert(double data)
{
	if (_list_size + 1 > _mem_size)
	{
		_mem_size *= 2;
		double* tmp = new double[_mem_size];
		std::copy(_list_data, _list_data + _list_size, tmp);
		delete[]_list_data;
		_list_data = tmp;
		tmp = NULL;
	}
	_list_data[_list_size] = data;
	_list_size++;
}

void List::sort()
{
	// insert sort
	double *result = new double[_list_size];
	std::copy(_list_data, _list_data + _list_size, result);
	for (int i = 0; i < _list_size; i++)
	{
		int j = i - 1;
		while ((j >= 0) && (_list_data[j] > result[i]))
		{
			_list_data[j + 1] = _list_data[j];
			j--;
		}
		_list_data[j + 1] = result[i];
	}
	delete[]result;
}