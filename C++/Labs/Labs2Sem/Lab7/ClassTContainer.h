#pragma once
#include <iostream>

using namespace std;

template <class T>
class CONTAINER
{
	int count;
	T* M;
public:
	CONTAINER();
	CONTAINER(int);
	CONTAINER(T* p, int n);
	CONTAINER(CONTAINER <T> & m);
	~CONTAINER();

	int getCount() { return count; }
	T getData(int index = 0) { return T.at(index); }

	template <class T> friend istream& operator >>(istream& in, CONTAINER <T> & m);
	template <class T> friend ostream& operator <<(ostream& out, const CONTAINER <T> & m);

	CONTAINER<T> & operator=(const CONTAINER<T> & m);
	CONTAINER <T> operator[](const int index);
};
