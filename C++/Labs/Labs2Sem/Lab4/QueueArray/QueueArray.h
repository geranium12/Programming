#pragma once
#include <exception>
#include <iostream>
#include <iomanip>

using namespace std;

class QueueArray
{
private:
	int n;
	int tail;
	int *ptr;
	int head;
public:
	// standart functions
	QueueArray();
	QueueArray(int _size);
	QueueArray(const QueueArray & q);
	~QueueArray();
	bool isEmpty();
	size_t size();
	int front();
	int back();
	void push_back(int);
	void pop_front();
	void clear();
	bool isFool();

	// my functions
	void print();
};

