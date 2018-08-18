// Longest common subsequence problem dynamic programming solution.
// Problem definition:
//     A sequence Z is called a subsequence of X if and only if 
//     all elements of Z appears in X in order, but not necessarily
//     consecutively. For example, {B, C, B, A} is a subsequence of 
//     {A, B, C, D, B, C, A}. Find a longest subsequence of two given 
//     sequence X and Y. 
// Recursive solution:
//     Note X's length as m and y's length as n, c[i, j] as the length
//     of the longest common subsequenc of {x1, x2, ..., xi} and {y1,
//     y2, ..., yj}, then we have:
//         - if x_i == y_j, then c[i, j] = c[i-1, j-1] + 1
//         - if x_i != y_j, then c[i, j] = max(c[i-1, j], c[i, j-1])

#include <iostream>

void longest_common_subsequence_bottom_up(int* c, char* x, char* y, int m, int n)
{
	for (int i = 0; i <= m; i++)
		c[i] = 0;
	for (int i = 0; i <= n; i++)
		c[i * (m + 1)] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
				c[j * (m + 1) + i] = c[(j - 1) * (m + 1) + (i - 1)] + 1;
			else
			{
				if (c[j * (m + 1) + (i - 1)] >= c[(j - 1) * (m + 1) + i])
					c[j * (m + 1) + i] = c[j * (m + 1) + (i - 1)];
				else
					c[j * (m + 1) + i] = c[(j - 1) * (m + 1) + i];
			}
		}
	}
}

void print_lcs(int* c, char* x, char* y, int m, int n)
{
	int i = m, j = n;
	int length = c[n * (m + 1) + m]; int L = length;
	std::cout << "Longest length: " << length << std::endl;
	char* s = new char[length];
	while ((i > 0) && (j > 0))
	{
		if (x[i - 1] == y[j - 1])
		{
			s[length - 1] = x[i - 1];
			length--; i--; j--;
		}
		else
		{
			if (c[j * (m + 1) + (i - 1)] >= c[(j - 1) * (m + 1) + i])
				i--;
			else
				j--;
		}
	}
	std::cout << "Optimal Solution: ";
	for (int i = 0; i < L; i++)
		std::cout << s[i];
	std::cout << std::endl;
}

void longest_common_subsequence(char* x, char* y, int m, int n)
{
	int* c = new int[(m + 1) * (n + 1)];
	longest_common_subsequence_bottom_up(c, x, y, m, n);
	print_lcs(c, x, y, m, n);
	delete[]c;
}