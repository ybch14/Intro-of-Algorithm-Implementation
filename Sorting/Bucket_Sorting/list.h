#ifndef _LIST_H
#define _LIST_H

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
	int size() const
	{
		return _list_size;
	}
	double data(int index) const
	{
		return _list_data[index];
	}
	void insert(double data);
	void sort();
	friend void bucket_sort(double* A, int length);
};

#endif
