#include <iostream>

int main()
{
	void longest_common_subsequence(char* x, char* y, int m, int n);
	std::cout << "Test Sample 1:" << std::endl;
	char X[8] = "ABCBDAB", Y[7] = "BDCABA";
	longest_common_subsequence(X, Y, 7, 6);
	std::cout << "Test Sample 2:" << std::endl;
	char x[30] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
	char y[29] = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
	longest_common_subsequence(x, y, 29, 28);
	return 0;
}