# Longest Common Subseqence Problem

Dynamic programming: longest common subsequence problem implementation.

## Task Definition

A sequence Z is called a subsequence of X if and only if 
all elements of Z appears in X in order, but not necessarily
consecutively. For example, {B, C, B, A} is a subsequence of 
{A, B, C, D, B, C, A}. Find a longest subsequence of two given 
sequence X and Y. 

## File List

- [`longest_common_subsequence.cpp`](longest_common_subsequence.cpp): implementation of dynamic programming solution.
- [`main.cpp`](main.cpp): test samples.

## Test Sample

- "ABCBDAB" & "BDCABA"
- "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA" & "GTCGTTCGGAATGCCGTTGCTCTGTAAA"

## Output 

```
Test Sample 1:
Longest length: 4
Optimal Solution: BCBA
Test Sample 2:
Longest length: 20
Optimal Solution: GTCGTCGGAAGCCGGCCGAA
```