# Heap Sort

Heap Sort algorithm implemetation. 

## Task definition

Sort a array from small to large.

## Data structure

```C++
class Heap
{
private:
    int _max_size;
    int _heap_size;
    double* _heap_data;
    inline int parent(int index);
    inline int left(int index);
    inline int right(int index);
    void _heapify(int index);
public:
    int max_size() const;
    int heap_size() const;
    double data(int index) const;
    void copy(double* dst, int length) const;
    Heap(int max_size);
    Heap(double* data, int heap_size);
    Heap(const Heap& H);
    ~Heap();
    void operator=(const Heap& H);
    void sort();
}
```

## File List

- [`heap.h`](heap.h): heap class definition
- [`heap.cpp`](heap.cpp): implementation of heap class member functions.
- [`heap_sort.cpp`](heap_sort.cpp): implementation of heap sort (also includes insert sort for comparison).
- [`main.cpp`](main.cpp): test samples.
- [`data.txt`](data.txt): array to be sorted.

## Test sample

- [1, 5, 6, 3, 4, 5, 6, 2, 1, 0]
- Standard normal distributed random-initialized 1000000 array (```data.txt```)

## Output

```
0 1 1 2 3 4 5 5 6 6
Data loaded!
Heap sort: 0.284s.
Heap sort correct? Yes! :)
Insert sort: 172.767s.
Insert sort correct? Yes! :)
```