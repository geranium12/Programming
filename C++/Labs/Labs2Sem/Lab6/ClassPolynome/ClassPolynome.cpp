#include "ClassPolynome.h"
#include "MyException.h"
#include <algorithm>

Polynome::Polynome(int _n)
{
	try
	{
		if (n < 0)
			throw MyException("Negative degree of the Polynome!", "", 0, "Polynome::Polynome(int _n)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	n = _n;
	coeff = new double[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		coeff[i] = 0;
	}
}

Polynome::Polynome(const Polynome& p)
{
	n = p.n;
	coeff = new double[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		coeff[i] = p.coeff[i];
	}
}

Polynome::~Polynome()
{
	delete[] coeff;
}

Polynome::Polynome(int _n, const double *d)
{
	n = _n;
	coeff = new double[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		coeff[i] = d[i];
	}
}
Polynome& Polynome::operator = (const Polynome& p)
{
	delete[] coeff;
	n = p.n;
	coeff = new double[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		coeff[i] = p.coeff[i];
	}
	return *this;
}

double Polynome::Value(const double x)
{
	double ans = 0;
	for (int i = 0; i <= n; i++)
	{
		double z = 1;
		for (int j = 0; j < n - i; j++)
		{
			z *= x;
		}
		ans += (z * coeff[i]);
	}
	return ans;
}

double& Polynome::operator [](int i) const
{
	try
	{
		if (n < 0)
			throw MyException("Wrong index of the Polynome!", "", 0, "double& Polynome::operator [](int i) const");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
		return coeff[0];
	}
	return coeff[i];
}

Polynome& Polynome::operator += (const Polynome& p)
{
	if (n < p.n)
	{
		double *temp = new double[n + 1];
		for (int i = 0; i < n + 1; i++)
			temp[i] = coeff[i];
		delete[] coeff;
		coeff = new double[p.n + 1];
		for (int i = 0; i < p.n - n; i++)
		{
			coeff[i] = p.coeff[i];
		}
		for (int i = p.n - n; i < p.n + 1; i++)
		{
			coeff[i] = temp[i - p.n + n] + p.coeff[i];
		}
		n = p.n;
	}
	else
	{
		for (int i = 0; i < p.n + 1 ; i++)
		{
			coeff[n - p.n + i] += p.coeff[i];
		}
	}
	return *this;
}

Polynome& Polynome::operator -= (const Polynome& p)
{
	*this += -p;
	return *this;
	/*
	if (n < p.n)
	{
		double *temp = new double[n + 1];
		for (int i = 0; i < n + 1; i++)
			temp[i] = coeff[i];
		delete[] coeff;
		coeff = new double[p.n + 1];
		for (int i = 0; i < p.n - n; i++)
		{
			coeff[i] = -p.coeff[i];
		}
		for (int i = p.n - n; i < p.n + 1; i++)
		{
			coeff[i] = temp[i - p.n + n] - p.coeff[i];
		}
		n = p.n;
	}
	else
	{
		for (int i = 0; i < p.n + 1; i++)
		{
			coeff[n - p.n + i] -= p.coeff[i];
		}
	}
	return *this;
	*/
}

Polynome& Polynome::operator *= (const Polynome& p)
{
	int curN = n + p.n;
	double *curCoeffs = new double[curN + 1];
	for (int i = 0; i < curN + 1; i++)
		curCoeffs[i] = 0;

	int k = 0;
	while (k < curN + 1)
	{
		double temp = 0;
		int i = 0;
		while (i < n + 1)
		{
			int j = 0;
			while (j < p.n + 1)
			{
				if (i + j == k)
					temp += (coeff[i] * p.coeff[j]);
				else
					if (i + j > k)
						j = p.n + 1;
				j++;
			}
			i++;
		}
		curCoeffs[k] = temp;
		k++;
	}
	*this = Polynome(curN, curCoeffs);
	return *this;
}

Polynome& Polynome::operator /= (const Polynome& p);	// throw(Zero_divide)
{
	if (n < p.n)
	{

	}
}

Polynome Polynome::operator -() const
{
	double *temp = new double[n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = -coeff[i];
	}
	return Polynome(n, temp);
}

Polynome Polynome::operator +() const
{
	return Polynome(n, coeff);
}

Polynome operator + (const Polynome& p1, const Polynome& p2)
{
	if (p1.n < p2.n)
	{
		double *temp = new double[p2.n + 1];
		for (int i = 0; i < p2.n - p1.n; i++)
		{
			temp[i] = p2.coeff[i];
		}
		for (int i = p2.n - p1.n; i < p1.n + 1; i++)
		{
			temp[i] = p1.coeff[i - p2.n + p1.n] + p2.coeff[i];
		}
		return Polynome(p2.n, temp);
	}
	else
	{
		double *temp = new double[p2.n + 1];
		for (int i = 0; i < p2.n + 1; i++)
		{
			temp[i] = 0;
		}
		for (int i = 0; i < p1.n + 1; i++)
		{
			temp[i] = p1.coeff[i];
		}
		for (int i = 0; i < p2.n + 1; i++)
		{
			temp[p1.n - p2.n + i] += p2.coeff[i];
		}
		return Polynome(p1.n, temp);
	}
}

Polynome operator - (const Polynome& p1, const Polynome& p2)
{
	return p1 + (-p2);
	/*
	if (p1.n < p2.n)
	{
		double *temp = new double[p2.n + 1];
		for (int i = 0; i < p2.n - p1.n; i++)
		{
			temp[i] = -p2.coeff[i];
		}
		for (int i = p2.n - p1.n; i < p2.n + 1; i++)
		{
			temp[i] = p1.coeff[i - p2.n + p1.n] - p2.coeff[i];
		}
		return Polynome(p2.n, temp);
	}
	else
	{
		double *temp = new double[p1.n + 1];
		for (int i = 0; i < p1.n + 1; i++)
		{
			temp[i] = 0;
		}
		for (int i = 0; i < p1.n + 1; i++)
		{
			temp[i] = p1.coeff[i];
		}
		for (int i = 0; i < p2.n + 1; i++)
		{
			temp[p1.n - p2.n + i] -= p2.coeff[i];
		}
		return Polynome(p1.n, temp);
	}
	*/
}

Polynome operator * (const Polynome& p1, const Polynome& p2)
{
	int curN = p1.n + p2.n;
	double *curCoeffs = new double[curN + 1];
	for (int i = 0; i < curN + 1; i++)
		curCoeffs[i] = 0;

	int k = 0;
	while (k < curN + 1)
	{
		double temp = 0;
		int i = 0;
		while (i < p1.n + 1)
		{
			int j = 0;
			while (j < p2.n + 1)
			{
				if (i + j == k)
					temp += (p1.coeff[i] * p2.coeff[j]);
				else
					if (i + j > k)
						j = p2.n + 1;
				j++;
			}
			i++;
		}
		curCoeffs[k] = temp;
		k++;
	}
	return Polynome(curN, curCoeffs);
}

//friend Polynome operator / (const Polynome& p1, const Polynome& p2);// throw(Zero_divide)

istream& operator >> (istream& in, Polynome &p)
{
	in >> p.n;
	p.coeff = new double[p.n + 1];
	for (int i = 0; i < p.n + 1; i++)
	{
		in >> p.coeff[i];
	}
	return in;
}
ostream& operator << (ostream& out, const Polynome &p)
{
	for (int i = 0; i < p.n; i++)
	{
		out << setprecision(3) << p.coeff[i] << " * x^" << p.n - i << " + ";
	}
	out << p.coeff[p.n];
	return out;
}
