#include <iostream>
#include <fstream>
#include <time.h>
#include "matrix.h"

int main()
{
	// raw test sample
	double a[16] = {1.0, 2.0, 3.0, 4.0, 
				   5.0, 6.0, 7.0, 8.0,
				   9.0, 10.0, 11.0, 12.0,
				   13.0, 14.0, 15.0, 16.0};
	double b[16] = {1.0, -1.0, 1.0, -1.0,
					2.0, -2.0, 3.0, -3.0,
					4.0, -4.0, 5.0, -5.0,
					3.0, -3.0, 6.0, -6.0};
	SquareMatrix A(a, 4), B(b, 4);
	std::cout << "A:\n" << A << "B: \n" << B;
	SquareMatrix C = A.multiply(B);
	std::cout << "naive A*B:\n" << C;
	SquareMatrix S = A.multiply(B, 's');
	std::cout << "strassen A*B:\n" << S;
	C = A+B;
	std::cout << "A+B:\n" << C;
	C = B-A;
	std::cout << "B-A:\n" << C;
	C = SquareMatrix(2);
	std::cout << "C:\n" << C;

	// file bigger test sample
	std::ifstream fa("A.txt", std::ios_base::in);
	std::ifstream fb("B.txt", std::ios_base::in);
	double *M1 = new double[1024 * 1024], *M2 = new double[1024 * 1024];
	double tmp = 0.0;
	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 1024; j++)
		{
			fa >> M1[i * 1024 + j];
			fb >> M2[i * 1024 + j];
		}
	}
	A = SquareMatrix(M1, 1024);
	B = SquareMatrix(M2, 1024);
	clock_t start = clock();
	C = A.multiply(B);
	std::cout << "naive multiply time: " << (double)(clock() - start) / CLOCKS_PER_SEC << 's' << std::endl;
	start = clock();
	S = A.multiply(B, 's');
	std::cout << "strassen multiply time: " << (double)(clock() - start) / CLOCKS_PER_SEC << 's' << std::endl;
	std::cout << "C == S? " << ((C == S)?"Yes!:)":"No!:(") << std::endl;
	return 0;
}