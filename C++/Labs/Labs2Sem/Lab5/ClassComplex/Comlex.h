#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class complex
{
private:
	double re;
	double im;
public:
	// complex
	complex();
	complex(const double re, const double im);
	complex(const complex& c);
	~complex() {}

	friend complex operator +(const complex &c1, const complex &c2);
	friend complex operator -(const complex &c1, const complex &c2);
	friend complex operator *(const complex &c1, const complex &c2);
	friend complex operator /(const complex &c1, const complex &c2);

	complex& operator +=(const complex &c);
	complex& operator -=(const complex &c);
	complex& operator *=(const complex &c);
	complex& operator /=(const complex &c);

	friend complex operator -(const complex& c);
	friend complex operator +(const complex& c);

	friend bool operator < (const complex& c1, const complex& c2);
	friend bool operator > (const complex& c1, const complex& c2);
	friend bool operator == (const complex& c1, const complex& c2);
	friend bool operator != (const complex& c1, const complex& c2);
	friend bool operator <= (const complex& c1, const complex& c2);
	friend bool operator >= (const complex& c1, const complex& c2);

	friend istream& operator >>(istream& in, complex& c);
	friend ostream& operator <<(ostream& out, const complex &c);

	complex& operator ++();
	complex operator ++(const int f);
	complex& operator --();
	complex operator --(const int f);

	friend const complex max(const complex &c1, const complex &c2);
};