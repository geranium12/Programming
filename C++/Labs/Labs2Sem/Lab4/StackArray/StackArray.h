#pragma once
#include <iostream>
#include <exception>
#include <iomanip>

using namespace std;

class StackArray
{
private:
	int size;
	int top;
	int *ptr;
public:
	StackArray();
	StackArray(const int& _size);
	StackArray(const StackArray& s);
	~StackArray();
	bool isEmpty();
	bool isFool();
	int peek();
	void pop();
	void push(int x);
	void clear();
	void print();
};