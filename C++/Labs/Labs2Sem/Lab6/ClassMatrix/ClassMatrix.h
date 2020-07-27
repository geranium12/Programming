#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

class Matrix
{
	int** p;
	int n;
	int m;
	int test;
public:
	Matrix();
	Matrix(int _n, int _m);
	Matrix(int _n, int _m, int** _p);
	Matrix(const Matrix& mat);
	~Matrix();

	Matrix operator +(const Matrix& mat);
	Matrix operator -(const Matrix& mat);
	Matrix operator *(const Matrix& mat);
	
	Matrix& operator +=(const Matrix& mat);
	Matrix& operator -=(const Matrix& mat);
	Matrix& operator *=(const Matrix& mat);

	int* operator [](int i);
	//int operator [](int i);

	Matrix operator -();
	Matrix operator +();

	friend bool operator ==(const Matrix& mat1, const Matrix& mat2);
	friend bool operator !=(const Matrix& mat1, const Matrix& mat2);

	friend istream& operator >>(istream& in, Matrix& x);
	friend ostream& operator <<(ostream& out, const Matrix& x);

	Matrix transpose();
};
