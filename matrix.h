#pragma once
#include <cstdlib>
#include <iostream>
#ifndef MARTIX_H
#define MARTIX_H

class Matrix
{
private:
	float** myMatrix;
	size_t row, col;

public:

	Matrix(size_t r, size_t c) :row(r), col(c)  //make a matrix with r rows and c column, but without initialized;
	{
		if (!col || !row) { return; }
		myMatrix = (float**)malloc(col * sizeof(float*));    // define the column of the matrix;
		float** starting = myMatrix;
		float** ending = myMatrix + col; // pointer and ending are the address of matrix's beginning column and ending column;
		do
		{
			*(starting++) = (float*)malloc(row * sizeof(float));
		} while (starting != ending);
	};

	Matrix(size_t r, size_t c, const float initial) : row(r), col(c)
	{
		if (!col || !row) { return; }
		myMatrix = (float**)malloc(col * sizeof(float*)); //make a matrix with r rows and c column, also with initialized;
		float** starting = myMatrix;
		float** ending = myMatrix + col;
		float* ele_pointer, * ele_end;
		do
		{
			ele_pointer = *(starting) = (float*)malloc(row * sizeof(float));
			ele_end = ele_pointer + row;
			do
			{
				*(ele_pointer++) = initial;
			} while (ele_pointer != ele_end);
			starting++;
		} while (starting != ending);
	};

	float& operator()(size_t c, size_t r) { return myMatrix[r][c]; }
	const float operator()(size_t c, size_t r)const { return myMatrix[r][c]; }
	Matrix operator*(const Matrix& yourMatrix)
	{
		if (col != yourMatrix.row) return *this;
		Matrix result(row, yourMatrix.col, 0);
		float* tr[4];
		int i(0), j(0);
		do {
			tr[i++] = (float*)malloc(sizeof(float) * col);
		} while (i < 4);
		do {
			i = 0;
			do {
				tr[0][i] = myMatrix[i][j];
				tr[1][i] = myMatrix[i][j + 1];
				tr[2][i] = myMatrix[i][j + 2];
				tr[3][i] = myMatrix[i][j + 3];
			} while ((++i) < col);
			i = 0;
			do {
				mult_kernel(result.myMatrix, tr, yourMatrix.myMatrix, j, i);
				i += 4;
			} while (i < yourMatrix.col);
			j += 4;
		} while (j < row);
		return result;
	};
	friend Matrix operator *(float re, Matrix& yourMatrix);
	friend Matrix operator *( Matrix& yourMatrix, float re);
	bool operator==(const Matrix& yourMatrix)
	{
		bool flag = true;
		if (col != yourMatrix.col || row != yourMatrix.row)
		{
			flag = false;
			return flag;
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < yourMatrix.col; j++)
			{
				if ((*this)(i, j) != yourMatrix(i, j))
				{
					flag = false;
				}
				if (!flag) { break; }
			}
			if (!flag) { break; }
		}
		return flag;
	};
	Matrix operator+(const Matrix& yourMatrix)
	{
		if (col != yourMatrix.col || row != yourMatrix.row)
		{
			return yourMatrix;
		}
		Matrix result(row, yourMatrix.col, 0);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < yourMatrix.col; j++)
			{
				result.myMatrix[i][j]= (*this)(i, j) + yourMatrix(i, j);
			}
		}
		return result;
	};
	Matrix operator-(const Matrix& yourMatrix)
	{
		if (col != yourMatrix.col || row != yourMatrix.row)
		{
			return yourMatrix;
		}
		Matrix result(row, yourMatrix.col, 0);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < yourMatrix.col; j++)
			{
				result.myMatrix[i][j] = (*this)(i, j) - yourMatrix(i, j);
			}
		}
		return result;
	};
	friend std::ostream& operator <<(std::ostream& os, const Matrix& other);


	void mult_kernel(float** con, float** a, float** b, int r, int col) {
		register float t0(0), t1(0), t2(0), t3(0), t4(0), t5(0), t6(0), t7(0), t8(0), t9(0), t10(0), t11(0), t12(0), t13(0), t14(0), t15(0);
		float* a0(a[0]), * a1(a[1]), * a2(a[2]), * a3(a[3]), * b0(b[col]), * b1(b[col + 1]), * b2(b[col + 2]), * b3(b[col + 3]), * end = b0 + row;
		do {
			t0 += *(a0) * *(b0);
			t1 += *(a0) * *(b1);
			t2 += *(a0) * *(b2);
			t3 += *(a0++) * *(b3);
			t4 += *(a1) * *(b0);
			t5 += *(a1) * *(b1);
			t6 += *(a1) * *(b2);
			t7 += *(a1++) * *(b3);
			t8 += *(a2) * *(b0);
			t9 += *(a2) * *(b1);
			t10 += *(a2) * *(b2);
			t11 += *(a2++) * *(b3);
			t12 += *(a3) * *(b0++);
			t13 += *(a3) * *(b1++);
			t14 += *(a3) * *(b2++);
			t15 += *(a3++) * *(b3++);
		} while (b0 != end);
		con[col][r] = t0;
		con[col + 1][r] = t1;
		con[col + 2][r] = t2;
		con[col + 3][r] = t3;
		con[col][r + 1] = t4;
		con[col + 1][r + 1] = t5;
		con[col + 2][r + 1] = t6;
		con[col + 3][r + 1] = t7;
		con[col][r + 2] = t8;
		con[col + 1][r + 2] = t9;
		con[col + 2][r + 2] = t10;
		con[col + 3][r + 2] = t11;
		con[col][r + 3] = t12;
		con[col + 1][r + 3] = t13;
		con[col + 2][r + 3] = t14;
		con[col + 3][r + 3] = t15;
	};

	Matrix mult_k( Matrix& yourMatrix) {}
};
#endif // !MARTIX_H
