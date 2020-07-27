#pragma once
#include "MyException.h"
#include <iostream>
#include <fstream>
#include <iomanip>

class Point
{
	//protected:
	int x, y;
public:
	Point();
	Point(int p1, int p2);
	~Point();
	Point(const Point&p);
	
	int getX() const;
	int getY() const;

	Point & operator =(const Point &p);
	Point & operator =(int p);
	 
	Point operator + (const Point &p);
	Point operator - (const Point &p);
	Point operator * (const Point &p);
	Point operator / (const Point &p);

	friend Point operator + (const int z, const Point &p2);
	friend Point operator + (const Point &p1, const int z);
	friend Point operator - (const int z, const Point &p2);
	friend Point operator - (const Point &p1, const int z);
	friend Point operator * (const int z, const Point &p2);
	friend Point operator * (const Point &p1, const int z);
	friend Point operator / (const int z, const Point &p2);
	friend Point operator / (const Point &p1, const int z);

	Point& operator += (const Point &p);
	Point& operator -= (const Point& p);
	Point& operator *= (const Point& p);
	Point& operator /= (const Point& p);
	Point& operator += (const int p);
	Point& operator -= (const int p);
	Point& operator *= (const int p);
	Point& operator /= (const int p);

	friend bool operator < (const Point& p1, const Point& p2);
	friend bool operator > (const Point& p1, const Point& p2);
	friend bool operator == (const Point& p1, const Point& p2);
	friend bool operator != (const Point& p1, const Point& p2);
	friend bool operator <= (const Point& p1, const Point& p2);
	friend bool operator >= (const Point& p1, const Point& p2);

	friend bool operator < (const Point& p1, const int p);
	friend bool operator > (const Point& p1, const int p);
	friend bool operator == (const Point& p1, const int p);
	friend bool operator != (const Point& p1, const int p);
	friend bool operator <= (const Point& p1, const int p);
	friend bool operator >= (const Point& p1, const int p);

	friend bool operator < (const int p, const Point& p2);
	friend bool operator > (const int p, const Point& p2);
	friend bool operator == (const int p, const Point& p2);
	friend bool operator != (const int p, const Point& p2);
	friend bool operator <= (const int p, const Point& p2);
	friend bool operator >= (const int p, const Point& p2);

	friend istream& operator>>(istream& in, Point& p);
	friend ostream& operator<<(ostream& out, const Point& p);

	friend Point operator - (const Point &p);
	friend Point operator + (const Point &p);

	Point operator ++(int k);
	Point &operator ++();
	Point operator --(int k);
	Point &operator --();

	void print(const Point &p);
};