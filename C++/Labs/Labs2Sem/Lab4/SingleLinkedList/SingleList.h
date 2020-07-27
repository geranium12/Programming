#pragma once
#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};

class SingleList
{
private:
	node *head;
	node *tail;
public:
	SingleList();
	SingleList(const SingleList& lst);
	~SingleList();
	bool isEmpty();
	void push_back(int value);
	void push_front(int value);
	void push(int pos, int value);
	int pop_back();
	int pop_front();
	int pop(int pos);
	node* search();
	void remove(node* adr);
	int peek(int pos);
	size_t size();
	void print();
	void delchet();
	int smin();
	void invert();
};