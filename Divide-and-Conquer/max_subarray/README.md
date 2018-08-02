# Max Subarray Problem

Max Subarray Divide-and-Conquer Implementation.

## Task definition

Find the subarray whose values have the largest sum.

## Data structure

```C++
class SubArray
{
private:
    int left_index;
    int right_index;
    int array_sum;
public:
    SubArray(int left, int right, int sum);
    int left();
    int right();
    int sum();
};
```

## File List

- [`subarray.h`](subarray.h): class definition.
- [`max_subarray.cpp`](max_subarray.h): find max subarray using divide-and-conquer method.
- [`main.cpp`](main.cpp): test samples.

## Test sample 

- [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
- [1, -4, 3, -4]
- [-2, -4, -5, -1, -5]
- [1, 2, 3, 4, 5]

## Output

```
array: 13 -3 -25 20 -3 -16 -23 18 20 -7 12 -5 -22 15 -4 7
max array: 18 20 -7 12

array: 1 -4 3 -4
max array: 3

array: -2 -4 -5 -1 -5
max array: -1

array: 1 2 3 4 5
max array: 1 2 3 4 5
```