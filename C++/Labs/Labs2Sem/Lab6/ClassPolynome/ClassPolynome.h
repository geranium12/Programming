#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Polynome
{
	int	n;
	double*	coeff;
	Polynome();
public:
	Polynome(int _n);		// throw(Negative_degree)
	Polynome(int _n, const double *d);
	Polynome(const Polynome& p);
	~Polynome();

	Polynome& operator = (const Polynome& p);

	double Value(const double x);
	double& operator [](int i) const;		// throw(Wrong_index)
	
	Polynome& operator += (const Polynome& p);
	Polynome& operator -= (const Polynome& p);
	Polynome& operator *= (const Polynome& p);
	Polynome& operator /= (const Polynome& p);	// throw(Zero_divide)
			
	Polynome operator -() const;
	Polynome operator +() const;
	
	friend Polynome operator + (const Polynome& p1, const Polynome& p2);
	friend Polynome operator - (const Polynome& p1, const Polynome& p2);
	friend Polynome operator * (const Polynome& p1, const Polynome& p2);
	friend Polynome operator / (const Polynome& p1, const Polynome& p2);// throw(Zero_divide)

	friend istream& operator >> (istream& in, Polynome &p);
	friend ostream& operator << (ostream& out, const Polynome &p);
};