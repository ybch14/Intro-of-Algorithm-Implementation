#include <iostream>

int main()
{
	std::cout << "Test Sample 1:" << std::endl;
	int dim[7] = { 30, 35, 15, 5, 10, 20, 25 };
	void matrix_multiplication(int* dim, int length);
	matrix_multiplication(dim, 6);
	std::cout << "Test sample 2" << std::endl;
	int dim2[7] = { 5, 10, 3, 12, 5, 50, 6 };
	matrix_multiplication(dim2, 6);
	return 0;
}