# Hash Table

Hash table data structure implementation. To compare the average detect time, linear hash and double hash algorithms are implemented. 

## Task definition

Given 1000000 strings (distinct strings 300000), count the appearance time of every distinct string. Since some of the strings are duplicated, we combine link method and open address method to solve collision.

## Test sample

- `['0', '1', '2', ..., '19', '0', '1', '2', ..., '19', '0', '1', '2', ..., '9']`
- random generalized strings, distinct count 300000. ([`generate_data.py`](generate_data.py))

## Output

```
Test HashTable:
0 -> 18 -> 18
0 -> 17 -> 17
0 -> 0 -> 0 -> 0
0 -> 1 -> 1 -> 1
0 -> 2 -> 2 -> 2
0 -> 3 -> 3 -> 3
0 -> 4 -> 4 -> 4
0 -> 5 -> 5 -> 5
0 -> 6 -> 6 -> 6
0 -> 7 -> 7 -> 7
0 -> 8 -> 8 -> 8
0 -> 9 -> 9 -> 9
0 -> 16 -> 16
0 -> 14 -> 14
0
0 -> 13 -> 13
0 -> 15 -> 15
0 -> 12 -> 12
0
0 -> 11 -> 11
0
0 -> 10 -> 10
0 -> 19 -> 19
Data loaded!
Double Hashing: 3.488s.
Double Hashing correct? Yes! :)
Linear Hashing: 123.683s.
Linear Hashing correct? Yes! :)
```