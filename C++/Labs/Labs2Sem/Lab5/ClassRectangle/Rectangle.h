#pragma once
#include "Point.h"
#include <iostream>
#include <algorithm>

class Rectangle
{
private:
	Point p1, p2;
public:
	Rectangle();
	Rectangle(Point a, Point b);
	Rectangle(int x1, int y1, int x2, int y2);
	Rectangle(const Rectangle& r);
	~Rectangle() {}
	
	Rectangle operator &(const Rectangle &r);
	Rectangle operator |(const Rectangle &r);

	Rectangle& operator =(Rectangle& r);

	friend bool operator ==(Rectangle &r1, Rectangle &r2);
	friend bool operator !=(Rectangle &r1, Rectangle &r2);
	friend bool operator >=(Rectangle &r1, Rectangle &r2);
	friend bool operator <=(Rectangle &r1, Rectangle &r2);
	friend bool operator >(Rectangle &r1, Rectangle &r2);
	friend bool operator <(Rectangle &r1, Rectangle &r2);

	friend Rectangle operator - (Rectangle &r);
	friend Rectangle operator + (Rectangle &r);

	Rectangle& operator ++();
	Rectangle operator ++(int f);
	Rectangle& operator --();
	Rectangle operator --(int f);

	friend istream& operator >>(istream& in, Rectangle& r);
	friend ostream& operator <<(ostream& out, const Rectangle& r);

	Rectangle operator ~();

	Rectangle& operator *(int n);
	Rectangle& operator /(int n);

	int square() const;
};