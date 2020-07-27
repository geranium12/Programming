#include "ClassVector.h"
#include "MyException.h"


Vector::Vector()
{
	_size = 0;
	max_capasity = 1;
	a = new int[1];
}


Vector::Vector(const int n)
{
	max_capasity = n;
	_size = n;
	try
	{
		if (n < 1)
			throw MyException("Bad vector size!", "", 0, "Vector::Vector(const int n)");
		a = new int[max_capasity];
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
}


Vector::Vector(const Vector& b)
{
	_size = b._size;
	max_capasity = b.max_capasity;
	if (max_capasity)
	{
		a = new int[max_capasity];
		for (int i = 0; i < _size; i++)
		{
			a[i] = b.a[i];
		}
	}
}


Vector::~Vector()
{
	if (max_capasity)
	{
		delete[] a;
	}
}


void Vector::push_back(const int& b)
{
	if (_size >= max_capasity)
	{
		int* temp = new int[max_capasity];
		for (int i = 0; i < _size; i++)
		{
			temp[i] = a[i];
		}
		delete[] a;
		max_capasity *= 2;
		a = new int[max_capasity];
		for (int i = 0; i < _size; i++)
			a[i] = temp[i];
		delete[] temp;
	}
	a[_size++] = b;
}


void Vector::push_front(const int& b)
{
	if (_size >= max_capasity)
	{
		int* temp = new int[max_capasity];
		for (int i = 0; i < _size; i++)
		{
			temp[i] = a[i];
		}
		delete[] a;
		max_capasity *= 2;
		a = new int[max_capasity];
		for (int i = 0; i < _size; i++)
			a[i] = temp[i];
		delete[] temp;
	}
	for (int i = _size; i >= 0; i--)
	{
		a[i] = a[i - 1];
	}
	_size++;
	a[0] = b;
}


void Vector::pop_back()
{
	try
	{
		if (_size <= 0)
			throw MyException("Empty vector pop!", "", 0, "void Vector::pop_back()");
		a = new int[max_capasity];
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	_size--;
}


void Vector::pop_front()
{
	try
	{
		if (_size <= 0)
			throw MyException("Empty vector pop!", "", 0, "void Vector::pop_front()");
		a = new int[max_capasity];
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	_size--;
	for (int i = 0; i < _size; i++)
	{
		a[i] = a[i + 1];
	}
}


size_t Vector::size() const 
{ 
	return _size; 
}


void Vector::resize(const int n)
{
	try
	{
		if (n > max_capasity)
			throw MyException("Bad vector resize!", "", 0, "void Vector::resize(const int n)");
		max_capasity = _size = n;
		int* temp = new int[n];
		for (int i = 0; i < _size; i++)
		{
			temp[i] = a[i];
		}
		delete[] a;
		a = new int[max_capasity];
		for (int i = 0; i < _size; i++)
			a[i] = temp[i];
		delete[] temp;
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
}


const int Vector::operator[](const int ind) const
{
	try
	{
		if (ind < 0 || ind >= _size)
			throw MyException("Bad index!", "", 0, "const int Vector::operator[](const int ind) const");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	return a[ind];
}


int& Vector::operator[](const int ind)
{
	try
	{
		if (ind < 0 || ind >= _size)
			throw MyException("Bad index!", "", 0, "const int Vector::operator[](const int ind) const");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	return a[ind];
}

std::ostream& operator<<(std::ostream& out, const Vector& b)
{
	for (int i = 0; i < b._size; i++)
	{
		out << b.a[i] << " ";
	}
	return out;
}