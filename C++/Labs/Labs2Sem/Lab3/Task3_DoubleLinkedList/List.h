#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct node
{
	int data;
	node *prev, *next;
};

class List
{
private:
	node *head;
	node *tail;
public:
	List();
	~List();
	List & operator = (List &r);
	int front();
	int back();
	int peek(int);
	bool isEmpty();
	size_t size();
	void clear();
	void insert(int, int);
	void erase(int, int);
	void push_back(int);
	void pop_back();
	void push_front(int);
	void pop_front();
	void print();
	void reverse();
	void bubbleSort();
	void swap(node *, node *);
};