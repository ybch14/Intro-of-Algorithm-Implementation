# Rod Cutting Problem

Dynamic programming: rod cutting problem implementation.

## Task Definition

Each rod piece has its unique price. A rod is of length i.
Find a way of cutting this rod so that the price sum of all
pieces reach the maximum. Return the optimal price and solution.

## File List

- [`rod_cutting.cpp`](rod_cutting.cpp): implementation of dynamic programming recurrent structure.
- [`main.cpp`](main.cpp): test samples.

## Test Sample

|Length|1|2|3|4|5|6|7|8|9|10|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|Price|1|5|8|9|10|17|17|20|24|30|

## Output 

```
Length  1 optimal Price:  1 (1)
Length  2 optimal Price:  5 (2)
Length  3 optimal Price:  8 (3)
Length  4 optimal Price: 10 (2+2)
Length  5 optimal Price: 13 (2+3)
Length  6 optimal Price: 17 (6)
Length  7 optimal Price: 18 (1+6)
Length  8 optimal Price: 22 (2+6)
Length  9 optimal Price: 25 (3+6)
Length 10 optimal Price: 30 (10)
```