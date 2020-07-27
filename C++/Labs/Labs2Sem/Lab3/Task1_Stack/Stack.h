#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct node
{
	int data;
	node *next;
};

class Stack
{
private:
	node *back;
public:
	// standart functions
	Stack();
	~Stack();
	bool isEmpty();
	size_t size();
	int top();
	void push(int);
	void pop();

	// my functions
	void print(ostream &);
};