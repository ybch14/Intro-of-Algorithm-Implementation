# Counting Sort

Counting sort algorithm implementation.

## Task definition

Sort an array which contains ***integers*** from 0 to k.

## File List

- [`counting_sort.cpp`](counting_sort.cpp): implementation of counting sort (also includes insert sort for comparison)
- [`main.cpp`](main.cpp): test samples.
- [`data.txt`](data.txt): array to be sorted.

## Test sample

- [1, 5, 6, 3, 4, 5, 6, 2, 1, 0]
- [2, 5, 3, 1, 2, 3, 1, 3]
- random initialized 1000000 integer array (ranges from 0 to 100000) (```data.txt```)

## Output

```
0 1 1 2 3 4 5 5 6 6
1 1 2 2 3 3 3 5
Data loaded!
Counting sort: 0.018s.
Counting sort correct? Yes! :)
Quick sort: 0.074s.
Quick sort correct? Yes! :)
Insert sort: 126.875s.
Insert sort correct? Yes! :)
```