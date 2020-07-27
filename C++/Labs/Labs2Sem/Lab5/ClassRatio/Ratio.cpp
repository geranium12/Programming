#include "Ratio.h"

double error = 0.000001;

int gcd(long a, long b)
{
	while (a * b != 0)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return max(a, b);
}

void Ratio::Reduce()
{
	int nod = gcd(abs(n), abs(d));
	if (!nod)
		nod = 1;
	if (d < 0)
	{
		n *= -1;
		d *= -1;
	}
	n /= nod;
	d /= nod;
}

Ratio::Ratio()
{
	n = 0;
	d = 1;
}

Ratio::Ratio(long n, long d) 
{
	this->n = n;
	if (d)
	{
		this->d = d;
	}
	else
	{
		this->d = 1;
	}
}

Ratio::Ratio(const Ratio& r)
{
	n = r.n;
	d = r.d;
}

Ratio& Ratio::operator = (const Ratio& r)
{
	n = r.n;
	d = r.d;
	return *this;
}
	
Ratio& Ratio::operator += (const Ratio& r)
{
	n = n * r.d + r.n * d;
	d *= r.d;
	Reduce();
	return *this;
}

Ratio& Ratio::operator -= (const Ratio& r)
{
	n = n * r.d - r.n * d;
	d *= r.d;
	Reduce();
	return *this;
}

Ratio& Ratio::operator *= (const Ratio& r)
{
	n *= r.n;
	d *= r.d;
	Reduce();
	return *this;
}

Ratio& Ratio::operator /= (const Ratio& r)
{
	try
	{
		if (!r.n)
			throw MyException("Division by zero!", "", 0, "Ratio& Ratio::operator /= (const Ratio& r)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
		return *this;
	}
	n *= r.d;
	d *= r.n;
	Reduce();
	return *this;
}

Ratio::operator double() const
{
	return (n * 1. / d);
}
	
Ratio operator -(const Ratio& r)
{
	return Ratio(-1 * r.n, r.d);
}

Ratio operator +(const Ratio& r)
{
	return r;
}

bool operator < (const Ratio& r1, const Ratio& r2)
{
	double a = r1.n * 1. / r1.d;
	double b = r2.n * 1. / r2.d;
	return (a < b);
}

bool operator > (const Ratio& r1, const Ratio& r2)
{
	double a = r1.n * 1. / r1.d;
	double b = r2.n * 1. / r2.d;
	return (a > b);
}

bool operator == (const Ratio& r1, const Ratio& r2)
{
	double a = r1.n * 1. / r1.d;
	double b = r2.n * 1. / r2.d;
	return (a == b);
}

bool operator != (const Ratio& r1, const Ratio& r2)
{
	double a = r1.n * 1. / r1.d;
	double b = r2.n * 1. / r2.d;
	return (a != b);
}

bool operator <= (const Ratio& r1, const Ratio& r2)
{
	double a = r1.n * 1. / r1.d;
	double b = r2.n * 1. / r2.d;
	return ((a < b) || (fabs(a - b) < error));
}

bool operator >= (const Ratio& r1, const Ratio& r2)
{
	double a = r1.n * 1. / r1.d;
	double b = r2.n * 1. / r2.d;
	return ((a > b) || (fabs(a - b) < error));
}

Ratio Ratio::operator + (const Ratio& r)
{
	Ratio temp;
	temp.n = n * r.d + r.n * d;
	temp.d = d * r.d;
	temp.Reduce();
	return temp;
}

Ratio Ratio::operator - (const Ratio& r)
{
	Ratio temp;
	temp.n = n * r.d - r.n * d;
	temp.d = d * r.d;
	temp.Reduce();
	return temp;
}

Ratio Ratio::operator * (const Ratio& r)
{
	Ratio temp;
	temp.n = n * r.n;
	temp.d = d * r.d;
	temp.Reduce();
	return temp;
}

Ratio Ratio::operator / (const Ratio& r)
{
	try
	{
		if (!r.n)
			throw MyException("Division by zero!", "", 0, "Ratio Ratio::operator / (const Ratio& r)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
		return *this;
	}
	Ratio temp;
	temp.n = n * r.d;
	temp.d = d * r.n;
	temp.Reduce();
	return temp;
}

istream& operator>>(istream& in, Ratio& r)
{
	in >> r.n >> r.d;
	return in;
}

ostream& operator<<(ostream& out, const Ratio& r)
{
	out << r.n << " " << r.d << endl;
	return out;
}

Ratio Ratio::operator +(const int &x)
{
	Ratio r(n + (x * d), d);
	r.Reduce();
	return r;
}

Ratio Ratio::operator -(const int &x)
{
	Ratio r(n - (x * d), d);
	r.Reduce();
	return r;
}

Ratio Ratio::operator *(const int &x)
{
	Ratio r(n * x, d);
	r.Reduce();
	return r;
}

Ratio Ratio::operator /(const int &x)
{
	try
	{
		if (!x)
			throw MyException("Division by zero!", "", 0, "Ratio Ratio::operator /(const int &x)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
		return *this;
	}
	Ratio r(n, d * x);
	r.Reduce();
	return r;
}

Ratio& Ratio::operator ++()
{
	n += d;
	return *this;
}

Ratio Ratio::operator ++(int f)
{
	Ratio r(*this);
	++*this;
	return r;
}

Ratio& Ratio::operator --()
{
	n -= d;
	return *this;
}

Ratio Ratio::operator --(int f)
{
	Ratio r = *this;
	--*this;
	return r;
}

Ratio& Ratio::operator =(const int &x)
{
	n = x;
	d = 1;
	return *this;
}

