#include "matrix.h"

using namespace std;
#define sizeOfMatrix 16
int main()
{
	Matrix m1(sizeOfMatrix, sizeOfMatrix, 1),m2(sizeOfMatrix, sizeOfMatrix, 1);
    cout << "The two base are: " << endl;
	cout << m1;
	cout << "The next: " << endl;
	cout << m2;
	cout << "Some other Matrixs: " << endl;
	Matrix m3 = m1 * m2;
	cout << "1. m1 * m2= " << endl;
	cout << m3;
	Matrix m4 = m1 * 2;
	cout << "2. m1 * 2 = " << endl;
	cout << m4;
	Matrix m5 = 3 * m1;
	cout << "3. 2 * m1 = " << endl;
	cout << m5;
	return 0;
}