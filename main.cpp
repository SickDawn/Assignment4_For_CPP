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
	cout << "3. 3 * m1 = " << endl;
	cout << m5;
	if (m5 == m4)
	{
		cout << "m5 == m4" << endl;
	}
	else
	{
		cout << "m5 != m4" << endl;
	}
	Matrix m6 = m1 * 1;
	if (m6 == m1)
	{
		cout << "m6 == m1" << endl;
	}
	else
	{
		cout << "m6 != m1" << endl;
	}
	Matrix m7 = m1 - m2;
	cout << "4. m1-m2 = " << endl;
	cout << m7;
	Matrix m8 = m1 + m2;
	cout << "5. m1+m2 = " << endl;
	cout << m8;
	return 0;
}