#include "ClassMatrix.h"
#include "MyException.h"

Matrix::Matrix()
{
	p = nullptr;
	n = m = 0;
}

Matrix::Matrix(int _n, int _m)
{
	n = _n;
	m = _m;
	p = new int*[n];
	for (int i = 0; i < n; i++)
		p[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			p[i][j] = 0;
		}
}

Matrix::Matrix(int _n, int _m, int** _p)
{
	n = _n;
	m = _m;
	p = new int*[n];
	for (int i = 0; i < n; i++)
		p[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			p[i][j] = _p[i][j];
		}
}

Matrix::Matrix(const Matrix& mat)
{
	n = mat.n;
	m = mat.n;
	p = new int*[n];
	for (int i = 0; i < n; i++)
		p[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			p[i][j] = mat.p[i][j];
		}
}

Matrix::~Matrix()
{
	// delete[] p;  ?
	for (int i = 0; i < n; i++)
		delete[] p[i];
	delete p;
}

Matrix Matrix::operator +(const Matrix& mat)
{
	int nmax = max(n, mat.n);
	int mmax = max(m, mat.m);

	int **_p = new int*[nmax];
	for (int i = 0; i < nmax; i++)
		_p[i] = new int[mmax];
	
	for (int i = 0; i < nmax; i++)
		for (int j = 0; j < mmax; j++)
		{
			_p[i][j] = 0;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			_p[i][j] = p[i][j];
		}

	for (int i = 0; i < mat.n; i++)
		for (int j = 0; j < mat.m; j++)
		{
			_p[i][j] += mat.p[i][j];
		}

	return Matrix(nmax, mmax, _p);
}

Matrix Matrix::operator -(const Matrix& mat)
{
	int nmax = max(n, mat.n);
	int mmax = max(m, mat.m);

	int **_p = new int*[nmax];
	for (int i = 0; i < nmax; i++)
		_p[i] = new int[mmax];

	for (int i = 0; i < nmax; i++)
		for (int j = 0; j < mmax; j++)
		{
			_p[i][j] = 0;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			_p[i][j] = p[i][j];
		}

	for (int i = 0; i < mat.n; i++)
		for (int j = 0; j < mat.m; j++)
		{
			_p[i][j] -= mat.p[i][j];
		}

	return Matrix(nmax, mmax, _p);
}

Matrix Matrix::operator *(const Matrix& mat)
{
	try
	{
		if (m != mat.n)
			throw MyException("Sizes of these matrices aren't the same", "", 0, "Polynome::Polynome(int _n)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	int **_p = new int*[n];
	for (int i = 0; i < n; i++)
		_p[i] = new int[mat.m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < mat.m; j++)
		{
			_p[i][j] = 0;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int ans = 0;
			for (int k = 0; k < m; k++)
			{
				ans += (p[i][k] * mat.p[k][j]);
			}
			_p[i][j] = ans;
		}
	return Matrix(n, mat.m, _p);
}

Matrix& Matrix::operator +=(const Matrix& mat)
{
	int nmax = max(n, mat.n);
	int mmax = max(m, mat.m);

	int **_p = new int*[nmax];
	for (int i = 0; i < nmax; i++)
		_p[i] = new int[mmax];

	for (int i = 0; i < nmax; i++)
		for (int j = 0; j < mmax; j++)
		{
			_p[i][j] = 0;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			_p[i][j] = p[i][j];
		}

	for (int i = 0; i < mat.n; i++)
		for (int j = 0; j < mat.m; j++)
		{
			_p[i][j] += mat.p[i][j];
		}
	*this = Matrix(nmax, mmax, _p);
	return *this;
}

Matrix& Matrix::operator -=(const Matrix& mat)
{
	int nmax = max(n, mat.n);
	int mmax = max(m, mat.m);

	int **_p = new int*[nmax];
	for (int i = 0; i < nmax; i++)
		_p[i] = new int[mmax];

	for (int i = 0; i < nmax; i++)
		for (int j = 0; j < mmax; j++)
		{
			_p[i][j] = 0;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			_p[i][j] = p[i][j];
		}

	for (int i = 0; i < mat.n; i++)
		for (int j = 0; j < mat.m; j++)
		{
			_p[i][j] -= mat.p[i][j];
		}

	*this = Matrix(nmax, mmax, _p);
	return *this;
}
Matrix& Matrix::operator *=(const Matrix& mat)
{
	try
	{
		if (m != mat.n)
			throw MyException("Sizes of these matrices aren't the same", "", 0, "Polynome::Polynome(int _n)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	int **_p = new int*[n];
	for (int i = 0; i < n; i++)
		_p[i] = new int[mat.m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < mat.m; j++)
		{
			_p[i][j] = 0;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int ans = 0;
			for (int k = 0; k < m; k++)
			{
				ans += (p[i][k] * mat.p[k][j]);
			}
			_p[i][j] = ans;
		}
	*this = Matrix(n, mat.m, _p);
	return *this;
}

int* Matrix::operator [](int i) // exception
{
	//test = i;
	return p[i];
}
/*
int Matrix::operator [](int i) // exception
{
	return p[test][i];

}
*/

Matrix Matrix::operator -()
{
	Matrix temp = *this;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			temp.p[i][j] *= -1;
		}
	return temp;
}

Matrix Matrix::operator +()
{
	return *this;
}

bool operator ==(const Matrix& mat1, const Matrix& mat2)
{
	if ((mat1.n != mat2.n) || (mat1.m != mat2.m))
		return false;
	for (int i = 0; i < mat1.n; i++)
		for (int j = 0; j < mat1.m; j++)
		{
			if (mat1.p[i][j] != mat2.p[i][j])
				return false;
		}
	return true;
}

bool operator !=(const Matrix& mat1, const Matrix& mat2)
{
	return !(mat1 == mat2);
}

istream& operator >>(istream& in, Matrix& x)
{
	for (int i = 0; i < x.n; i++)
		for (int j = 0; j < x.m; j++)
		{
			in >> x.p[i][j];
		}
	return in;
}

ostream& operator <<(ostream& out, const Matrix& x)
{
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.m; j++)
		{
			out << x.p[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

Matrix Matrix::transpose()
{
	Matrix temp(m, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			temp.p[j][i] = p[i][j];
		}
	return temp;
}
