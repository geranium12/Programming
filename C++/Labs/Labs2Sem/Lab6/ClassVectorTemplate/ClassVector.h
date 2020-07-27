#pragma once
#include<iostream>

template <class T>
class Vector
{
	unsigned int _size, max_capasity;
	T* a;
public:
	Vector();
	//Vector(const int);
	//Vector(const Vector <T> &);
	~Vector();
	/*

	void push_back(const T&);
	void push_front(const T&);

	void pop_back();
	void pop_front();

	size_t size() const;

	void resize(const int);

	const T operator[](int) const;
	T& operator[](int);

	//template <class T>
	friend std::ostream& operator<<(std::ostream&, const Vector<T>&);

	const T* begin() const { return a; }
	T* begin() { return a; }

	const T* end() const { return &a[_size]; }
	T* end() { return &a[_size]; }
	*/
};