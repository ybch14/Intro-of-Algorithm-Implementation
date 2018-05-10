#ifndef ARRAY_H
#define ARRAY_H

class SubArray
{
private:
	int left_index;
	int right_index;
	int array_sum;
public:
	SubArray(int left, int right, int sum)
	{
		left_index = left;
		right_index = right;
		array_sum = sum;
	}
	int left()
	{
		return left_index;
	}
	int right()
	{
		return right_index;
	}
	int sum()
	{
		return array_sum;
	}
};

#endif