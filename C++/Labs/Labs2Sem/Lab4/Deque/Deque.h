#pragma once
#include <iomanip>
#include <iostream>

using namespace std;

struct node
{
	int  data;
	struct  node*  next;
	struct  node*  prev;
};

class Deque
{
private:
	node *head, *tail;
public:
	Deque();	
	Deque(const Deque& d);
	~Deque();
	void insÍead(int n);	
	void insTail(int n);	
	int delHead();	    
	int delTail();	     
	bool isEmpty();		
	void print();
};
