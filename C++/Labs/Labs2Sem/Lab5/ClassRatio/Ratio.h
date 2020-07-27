#pragma once
#include "MyException.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Ratio
{
	long n, d;
	void Reduce();
public:

	Ratio();
	Ratio(long n, long d);
	Ratio(const Ratio& r);
	~Ratio() {}

	Ratio& operator = (const Ratio& r);
		
	Ratio& operator += (const Ratio& r);
	Ratio& operator -= (const Ratio& r);
	Ratio& operator *= (const Ratio& r);
	Ratio& operator /= (const Ratio& r);
	
	operator double(void) const; 
	
	friend Ratio operator -(const Ratio& r);
	friend Ratio operator +(const Ratio& r);
	
	friend bool operator < (const Ratio& r1, const Ratio& r2);
	friend bool operator > (const Ratio& r1, const Ratio& r2);
	friend bool operator == (const Ratio& r1, const Ratio& r2);
	friend bool operator != (const Ratio& r1, const Ratio& r2);
	friend bool operator <= (const Ratio& r1, const Ratio& r2);
	friend bool operator >= (const Ratio& r1, const Ratio& r2);
	
	Ratio operator + (const Ratio& r);
	Ratio operator - (const Ratio& r);
	Ratio operator * (const Ratio& r);
	Ratio operator / (const Ratio& r);
	
	friend istream& operator>>(istream& in, Ratio& r);
	friend ostream& operator<<(ostream& out, const Ratio& r);

	Ratio operator +(const int &x);
	Ratio operator -(const int &x);
	Ratio operator *(const int &x);
	Ratio operator /(const int &x);
	Ratio& operator ++();
	Ratio operator ++(int f);
	Ratio& operator --();
	Ratio operator --(int f);
	Ratio& operator =(const int &x);
};