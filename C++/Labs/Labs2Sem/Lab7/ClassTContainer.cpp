#include "ClassTCONTAINER.h"
#include "MyException.h"

template <class T>
CONTAINER<T>::CONTAINER()
{
	count = 0;
	M = nullptr;
}

template <class T>
CONTAINER<T>::CONTAINER(int n)
{
	try
	{
		if (n < 1)
			throw MyException("Wrong size of array!", "", 0, "CONTAINER::CONTAINER(int n)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	count = n;
	M = new T[n];
	for (int i = 0; i < n; i++)
	{
		M[i] = 0;
	}
}

template <class T>
CONTAINER<T>::CONTAINER(T* p, int n)
{
	try
	{
		if (n < 1)
			throw MyException("Wrong size of array!", "", 0, "CONTAINER::CONTAINER(int n)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	count = n;
	M = new T[n];
	for (int i = 0; i < n; i++)
	{
		M[i] = p[i];
	}
}

template <class T>
CONTAINER<T>::CONTAINER(CONTAINER <T> & m)
{
	count = m.count;
	M = new T[count];
	for (int i = 0; i < count; i++)
	{
		M[i] = m.M[i];
	}
}

template <class T>
CONTAINER<T>::~CONTAINER()
{
	delete[] M;
}

template <class T>
istream& operator >>(istream& in, CONTAINER <T> & m)
{
	in >> m.count;
	if (m.M != nullptr)
	{
		delete[] m.M;
	}
	m.M = new T[m.count];
	for (int i = 0; i < m.count; i++)
		in >> m.M[i];
	return in;
}

template <class T>
ostream& operator <<(ostream& out, const CONTAINER <T> & m)
{
	for (int i = 0; i < m.count; i++)
		out << m.m[i] << " ";
	out << endl;
	return out;
}

template <class T>
CONTAINER<T> & CONTAINER<T>::operator=(const CONTAINER<T> & m)
{
	delete[] M;
	count = m.count;
	M = new T[count];
	for (int i = 0; i < count; i++)
		M[i] = m.M[i];
}

template <class t>
CONTAINER <t> CONTAINER<t>::operator[](const int index)
{
	try
	{
		if (index < 0)
			throw MyException("wrong index!", "", 0, "CONTAINER <t> CONTAINER::operator[](const int index)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "function: " << ex.get_func() << std::endl;
	}
	return M[index];
}