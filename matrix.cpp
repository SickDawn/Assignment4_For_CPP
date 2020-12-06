#include "matrix.h"

using namespace std;


Matrix operator *(float re, Matrix& yourMatrix)
{
	Matrix result(yourMatrix.row, yourMatrix.col, 0);
	for (int i = 0; i < yourMatrix.row; i++)
	{
		for (int j = 0; j < yourMatrix.col; j++)
		{
			result.myMatrix[i][j] = yourMatrix(i, j) * re;
		}
	}
	return result;
}

Matrix operator *( Matrix& yourMatrix,float re)
{
	Matrix result(yourMatrix.row, yourMatrix.col, 0);
	for (int i = 0; i < yourMatrix.row; i++)
	{
		for (int j = 0; j < yourMatrix.col; j++)
		{
			result.myMatrix[i][j] = yourMatrix(i, j) * re;
		}
	}
	return result;
}


std::ostream& operator <<(std::ostream& os, const Matrix& yourMatrix)
{
	for (int i = 0; i < yourMatrix.row; i++)
	{
		for (int j = 0; j < yourMatrix.col; j++)
		{
			os << yourMatrix(i, j) << " ";
		}
		os << endl;
	}
	return os;
};


