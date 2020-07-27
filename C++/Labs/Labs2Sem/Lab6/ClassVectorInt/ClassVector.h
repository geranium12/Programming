#pragma once
#include<iostream>

class Vector
{
	unsigned int _size, max_capasity;
	int* a;
public:
	Vector();
	Vector(const int);
	Vector(const Vector&);
	~Vector();


	void push_back(const int&);
	void push_front(const int&);

	void pop_back();
	void pop_front();

	size_t size() const;

	void resize(const int);

	const int operator[](int) const;
	int& operator[](int);

	friend std::ostream& operator<<(std::ostream&, const Vector&);

	const int* begin() const { return a; }
	int* begin() { return a; }

	const int* end() const { return &a[_size]; }
	int* end() { return &a[_size]; }
};