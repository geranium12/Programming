#include "ClassVector.h"
#include "MyException.h"

template <class T>
Vector<T>::Vector()
{
	_size = 0;
	max_capasity = 1;
	a = new T[1];
}

/*
template <class T>
Vector<T>::Vector(const int n)
{
	max_capasity = n;
	_size = n;
	try
	{
		if (n < 1)
			throw MyException("Bad vector size!", "", 0, "Vector<T>::Vector(const int n)");
		a = new T[max_capasity];
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
}

template <class T>
Vector<T>::Vector(const Vector <T> & b)
{
	_size = b._size;
	max_capasity = b.max_capasity;
	if (max_capasity)
	{
		a = new T[max_capasity];
		for (int i = 0; i < _size; i++)
		{
			a[i] = b.a[i];
		}
	}
}
*/

template <class T>
Vector<T>::~Vector()
{
	if (max_capasity)
	{
		delete[] a;
	}
}

/*
template <class T>
void Vector<T>::push_back(const T& b)
{
	if (_size >= max_capasity)
	{
		T* temp = new T[max_capasity];
		for (int i = 0; i < _size; i++)
		{
			temp[i] = a[i];
		}
		delete[] a;
		max_capasity *= 2;
		a = new T[max_capasity];
		for (int i = 0; i < _size; i++)
			a[i] = temp[i];
		delete[] temp;
	}
	a[_size++] = b;
}

template <class T>
void Vector<T>::push_front(const T& b)
{
	if (_size >= max_capasity)
	{
		T* temp = new T[max_capasity];
		for (int i = 0; i < _size; i++)
		{
			temp[i] = a[i];
		}
		delete[] a;
		max_capasity *= 2;
		a = new T[max_capasity];
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

template <class T>
void Vector<T>::pop_back()
{
	try
	{
		if (_size <= 0)
			throw MyException("Empty vector pop!", "", 0, "void Vector<T>::pop_back()");
		a = new T[max_capasity];
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	_size--;
}

template <class T>
void Vector<T>::pop_front()
{
	try
	{
		if (_size <= 0)
			throw MyException("Empty vector pop!", "", 0, "void Vector<T>::pop_front()");
		a = new T[max_capasity];
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

template <class T>
size_t Vector<T>::size() const 
{ 
	return _size; 
}

template <class T>
void Vector<T>::resize(const int n)
{
	try
	{
		if (n > max_capasity)
			throw MyException("Bad vector resize!", "", 0, "void Vector<T>::resize(const int n)");
		max_capasity = _size = n;
		T* temp = new T[n];
		for (int i = 0; i < _size; i++)
		{
			temp[i] = a[i];
		}
		delete[] a;
		a = new T[max_capasity];
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

template <class T>
const T Vector<T>::operator[](const int ind) const
{
	try
	{
		if (ind < 0 || ind >= _size)
			throw MyException("Bad index!", "", 0, "const T Vector<T>::operator[](const int ind) const");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	return a[ind];
}

template <class T>
T& Vector<T>::operator[](const int ind)
{
	try
	{
		if (ind < 0 || ind >= _size)
			throw MyException("Bad index!", "", 0, "const T Vector<T>::operator[](const int ind) const");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	return a[ind];
}



template<class T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& b)
{
	for (int i = 0; i < b._size; i++)
	{
		out << b.a[i] << " ";
	}
	return out;
}
*/