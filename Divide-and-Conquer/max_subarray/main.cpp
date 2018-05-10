#include <iostream> // cout 
#include "subarray.h" // SubArray
using namespace std;

int main()
{
	SubArray max_subarray(int* A, int low, int high);
	int a[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	cout << "array:";
	for (int i = 0; i < 16; i++)
		cout << a[i] << ' ';
	cout << endl;
	SubArray result = max_subarray(a, 0, 15);
	cout << "max array:";
	for (int i = result.left(); i <= result.right(); i++)
		cout << a[i] << ' ';
	cout << endl;

	int b[4] = {1, -4, 3, -4};
	cout << "array:";
	for (int i = 0; i < 4; i++)
		cout << b[i] << ' ';
	cout << endl;
	result = max_subarray(b, 0, 3);
	cout << "max array: ";
	for (int i = result.left(); i <= result.right(); i++)
		cout << b[i] << ' ';
	cout << endl;

	int c[5] = {-2, -4, -5, -1, -5};
	cout << "array:";
	for (int i = 0; i < 5; i++)
		cout << c[i] << ' ';
	cout << endl;
	result = max_subarray(c, 0, 4);
	cout << "max array: ";
	for (int i = result.left(); i <= result.right(); i++)
		cout << c[i] << ' ';
	cout << endl;
	return 0;
}