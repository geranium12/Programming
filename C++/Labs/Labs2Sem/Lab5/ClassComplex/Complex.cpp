#include "Comlex.h"

complex::complex()
{
	re = im = 0;
}

complex::complex(const double re, const double im)
{
	this->re = re;
	this->im = im;
}

complex::complex(const complex& c)
{
	re = c.re;
	im = c.im;
}

complex operator +(const complex &c1, const complex &c2)
{
	complex c;
	c.re = c1.re + c2.re;
	c.im = c1.im + c2.im;
	return c;
}

complex operator -(const complex &c1, const complex &c2)
{
	complex c;
	c.re = c1.re - c2.re;
	c.im = c1.im - c2.im;
	return c;
}

complex operator *(const complex &c1, const complex &c2)
{
	complex c;
	c.re = c1.re * c2.re - c1.im * c2.im;
	c.im = c1.re * c2.im + c1.im * c2.re;
	return c;
}

complex operator /(const complex &c1, const complex &c2)
{
	complex c;
	c.re = (c1.re * c2.re + c1.im * c2.im) / (c2.re * c2.re + c2.im * c2.im);
	c.im = (c1.im * c2.re - c1.re * c2.im) / (c2.re * c2.re + c2.im * c2.im);
	return c;
}

complex& complex::operator +=(const complex &c)
{
	re += c.re;
	im += c.im;
	return *this;
}

complex& complex::operator -=(const complex &c)
{
	re -= c.re;
	im -= c.im;
	return *this;
}

complex& complex::operator *=(const complex &c)
{
	int re1 = re;
	re = re * c.re - im * c.im;
	im = re1 * c.im + im * c.re;
	return *this;
}

complex& complex::operator /=(const complex &c)
{
	int im1 = im;
	re = (re * c.re + im * c.im) / (c.re * c.re + c.im * c.im);
	im = (im1 * c.re - re * c.im) / (c.re * c.re + c.im * c.im);
	return *this;
}

complex operator -(const complex& c)
{
	return complex(-c.re, -c.im);
}

complex operator +(const complex& c)
{
	return c;
}

bool operator < (const complex& c1, const complex& c2)
{
	return ((c1.re * c1.re + c1.im * c1.im) < (c2.re * c2.re + c2.im * c2.im));
}

bool operator > (const complex& c1, const complex& c2)
{
	return ((c1.re * c1.re + c1.im * c1.im) > (c2.re * c2.re + c2.im * c2.im));
}

bool operator == (const complex& c1, const complex& c2)
{
	return ((c1.re == c2.re) && (c1.im == c2.im));
}

bool operator != (const complex& c1, const complex& c2)
{
	return ((c1.re != c2.re) && (c1.im != c2.im));
}

bool operator <= (const complex& c1, const complex& c2)
{
	return ((c1.re * c1.re + c1.im * c1.im) <= (c2.re * c2.re + c2.im * c2.im));
}

bool operator >= (const complex& c1, const complex& c2)
{
	return ((c1.re * c1.re + c1.im * c1.im) >= (c2.re * c2.re + c2.im * c2.im));
}

istream& operator >>(istream& in, complex& c)
{
	in >> c.re >> c.im;
	return in;
}

ostream& operator <<(ostream& out, const complex &c)
{
	out << c.re << " " << c.im << endl;
	return out;
}

complex& complex::operator ++()
{
	this->re++;
	return *this;
}
complex complex::operator ++(const int f)
{
	complex c = *this;
	++*this;
	return c;
}

complex& complex::operator --()
{
	this->re--;
	return *this;
}

complex complex::operator --(const int f)
{
	complex c = *this;
	++*this;
	return c;
}

const complex max(const complex &c1, const complex &c2)
{
	if (c1 > c2)
		return c1;
	else
		return c2;
}