#include "Rectangle.h"

Rectangle::Rectangle()
{
	p1 = 0;
	p2 = 0;
}

Rectangle::Rectangle(Point a, Point b)
{
	p1 = a;
	p2 = b;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
{
	p1 = Point(x1, y1);
	p2 = Point(x2, y2);
}

Rectangle::Rectangle (const Rectangle& r)
{
	p1 = r.p1;
	p2 = r.p2;
}

// operator intersection
Rectangle Rectangle::operator &(const Rectangle &r)
{
	Rectangle temp;
	if ((p2.getX() <= r.p1.getX()) || (p2.getY() >= r.p1.getY()))
		return temp;
	temp.p1 = Point(max(p1.getX(), r.p1.getX()), min(p1.getY(), r.p1.getY()));
	temp.p2 = Point(min(p2.getX(), r.p2.getX()), max(p2.getY(), r.p2.getY()));
	return temp;
}

// operator union
Rectangle Rectangle::operator |(const Rectangle &r)
{
	Rectangle temp;
	temp.p1 = Point(min(p1.getX(), r.p1.getX()), max(p1.getY(), r.p1.getY()));
	temp.p2 = Point(max(p2.getX(), r.p2.getX()), min(p2.getY(), r.p2.getY()));
	return temp;
}

Rectangle& Rectangle::operator =(Rectangle& r)
{
	p1 = r.p1;
	p2 = r.p2;
	return *this;
}

Rectangle operator - (Rectangle &r)
{
	return Rectangle(-r.p1, -r.p2);
}

Rectangle operator + (Rectangle &r)
{
	return r;
}

Rectangle& Rectangle::operator ++()
{
	p1++;
	p2++;
	return *this;
}

Rectangle Rectangle::operator ++(int f)
{
	Rectangle r = *this;
	++*this;
	return r;
}

Rectangle& Rectangle::operator --()
{
	p1--;
	p2--;
	return *this;
}

Rectangle Rectangle::operator --(int f)
{
	Rectangle r = *this;
	--*this;
	return r;
}

istream& operator >>(istream& in, Rectangle& r)
{
	in >> r.p1 >> r.p2;
	return in;
}

ostream& operator <<(ostream& out, const Rectangle& r)
{
	out << r.p1 << " " << r.p2;
	return out;
}

Rectangle Rectangle::operator ~()
{
	return Rectangle(-p1, -p2);
}

Rectangle& Rectangle::operator *(int n)
{
	if (!n)
	{
		p1 = Point(0, 0);
		p2 = Point(0, 0);
	}
	else
	{
		p1 *= n;
	}
	return *this;
}

Rectangle& Rectangle::operator /(int n)
{
	try
	{
		if (!n)
			throw MyException("Division by zero!", "", 0, "Rectangle& Rectangle::operator /(int n)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
		return *this;
	}
	p1 /= n;
	return *this;
}

bool operator ==(Rectangle &r1, Rectangle &r2)
{
	return (r1.square() == r2.square());
}

bool operator !=(Rectangle &r1, Rectangle &r2)
{
	return (r1.square() != r2.square());
}

bool operator >=(Rectangle &r1, Rectangle &r2)
{
	return (r1.square() >= r2.square());
}

bool operator <=(Rectangle &r1, Rectangle &r2)
{
	return (r1.square() <= r2.square());
}

bool operator >(Rectangle &r1, Rectangle &r2)
{
	return (r1.square() > r2.square());
}

bool operator <(Rectangle &r1, Rectangle &r2)
{
	return (r1.square() < r2.square());
}

int Rectangle::square() const
{
	return abs(p1.getX() - p2.getX()) * (abs(p1.getY() - p2.getY()));
}