#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(int p1, int p2) : x(p1), y(p2) {}

Point::~Point() {}

Point::Point(const Point&p)
{
	x = p.x;
	y = p.y;
}


int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}


Point & Point::operator =(const Point &p)
{
	x = p.x;
	y = p.y;
	return *this;
}

Point & Point::operator =(int p)
{
	x = p;
	y = p;
	return *this;
}

Point Point::operator + (const Point &p)
{
	return Point(x + p.x, y + p.y);
}

Point Point::operator - (const Point &p)
{
	return Point(x - p.x, y - p.y);
}

Point Point::operator * (const Point &p)
{
	return Point(x * p.x, y * p.y);
}

Point Point::operator / (const Point &p)
{
	try
	{
		if ((!p.x) || (!p.y))
			throw MyException("Division by zero!", "", 0, "friend Point operator / (Point &p1, Point &p2)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	return Point(x / p.x, y / p.y);
}

Point operator + (const int z, const Point &p2)
{
	return Point(p2.x + z, p2.y + z);
}

Point operator + (const Point &p1, const int z)
{
	return Point(p1.x + z, p1.y + z);
}

Point operator - (const int z, const Point &p2)
{
	return Point(z - p2.x, z - p2.y);
}

Point operator - (const Point &p1, const int z)
{
	return Point(p1.x - z, p1.y - z);
}

Point operator * (const int z, const Point &p2)
{
	return Point(z * p2.x, z * p2.y);
}

Point operator * (const Point &p1, const int z)
{
	return Point(p1.x * z, p1.y * z);
}

Point operator / (const int z, const Point &p2)
{
	try
	{
		if (!z)
			throw MyException("Division by zero!", "", 0, "friend Point operator / (int z, Point &p2)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
		return p2;
	}
	return Point(z / p2.x, z / p2.y);
}

Point operator / (const Point &p1, const int z)
{
	try
	{
		if (!z)
			throw MyException("Division by zero!", "", 0, "friend Point operator / (Point &p1, int z)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
		return p1;
	}
	return Point(p1.x / z, p1.y / z);
}

Point& Point::operator += (const Point &p)
{
	x += p.x;
	y += p.y;
	return *this;
}

Point& Point::operator -= (const Point& p)
{
	x -= p.x;
	y -= p.y;
	return *this;
}

Point& Point::operator *= (const Point& p)
{
	x *= p.x;
	y *= p.y;
	return *this;
}

Point& Point::operator /= (const Point& p)
{
	try
	{
		if ((!p.x) || (!p.y))
			throw MyException("Division by zero!", "", 0, "Point& operator /= (const Point& p)");
		x /= p.x;
		y /= p.y;
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	return *this;
}

Point& Point::operator += (const int p)
{
	x += p;
	y += p;
	return *this;
}

Point& Point::operator -= (const int p)
{
	x -= p;
	y -= p;
	return *this;
}

Point& Point::operator *= (const int p)
{
	x *= p;
	y *= p;
	return *this;
}

Point& Point::operator /= (const int p)
{
	try
	{
		if (!p)
			throw MyException("Division by zero!", "", 0, "Point& operator /= (int p)");
		x /= p;
		y /= p;
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	return *this;
}

bool operator < (const Point& p1, const Point& p2)
{
	return ((p1.x < p2.x) && (p1.y < p2.y));
}

bool operator > (const Point& p1, const Point& p2)
{
	return ((p1.x > p2.x) && (p1.y > p2.y));
}

bool operator == (const Point& p1, const Point& p2)
{
	return ((p1.x == p2.x) && (p1.y == p2.y));
}

bool operator != (const Point& p1, const Point& p2)
{
	return ((p1.x != p2.x) && (p1.y != p2.y));
}

bool operator <= (const Point& p1, const Point& p2)
{
	return ((p1.x <= p2.x) && (p1.y <= p2.y));
}

bool operator >= (const Point& p1, const Point& p2)
{
	return ((p1.x >= p2.x) && (p1.y >= p2.y));
}

bool operator < (const Point& p1, const int p)
{
	return ((p1.x < p) && (p1.y < p));
}

bool operator > (const Point& p1, const int p)
{
	return ((p1.x > p) && (p1.y > p));
}

bool operator == (const Point& p1,const int p)
{
	return ((p1.x == p) && (p1.y == p));
}

bool operator != (const Point& p1, const int p)
{
	return ((p1.x != p) && (p1.y != p));
}

bool operator <= (const Point& p1, const int p)
{
	return ((p1.x <= p) && (p1.y <= p));
}

bool operator >= (const Point& p1, const int p)
{
	return ((p1.x >= p) && (p1.y >= p));
}

bool operator < (const int p, const Point& p2)
{
	return ((p < p2.x) && (p < p2.y));
}

bool operator > (const int p, const Point& p2)
{
	return ((p > p2.x) && (p > p2.y));
}

bool operator == (const int p, const Point& p2)
{
	return ((p == p2.x) && (p == p2.y));
}

bool operator != (const int p, const Point& p2)
{
	return ((p != p2.x) && (p != p2.y));
}

bool operator <= (const int p, const Point& p2)
{
	return ((p <= p2.x) && (p <= p2.y));
}

bool operator >= (const int p, const Point& p2)
{
	return ((p >= p2.x) && (p >= p2.y));
}

istream& operator>>(istream& in, Point& p)
{
	in >> p.x >> p.y;
	return in;
}

ostream& operator<<(ostream& out, const Point& p)
{
	out << p.x << " " << p.y;
	return out;
}

Point operator - (const Point &p)
{
	return Point(-p.x, -p.y);
}

Point operator + (const Point &p)
{
	return p;
}


Point Point::operator ++(int k)
{
	Point p = *this;
	++*this;
	return p;
}

Point & Point::operator ++()
{
	x++;
	y++;
	return *this;
}

Point Point::operator --(int k)
{
	Point p = *this;
	--*this;
	return p;
}

Point & Point::operator --()
{
	x--;
	y--;
	return *this;
}

void Point::print(const Point &p)
{
	cout << p.x << " " << p.y;
}