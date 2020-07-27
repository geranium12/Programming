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

class Queue
{
private:
	node *head;
	node *tail;
public:
	// standart functions
	Queue();
	~Queue();
	bool isEmpty();
	size_t size();
	int front();
	int back();
	void push_back(int);
	void pop_front();
	void clear();

	// my functions
	void print();
};