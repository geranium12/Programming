#include "Stack.h"

Stack::Stack()
{
	back = nullptr;
}

Stack::~Stack()
{
	node *temp = new node;
	while (back != nullptr)
	{
		temp = back;
		back = back->next;
		delete temp;
	}
}

bool Stack::isEmpty()
{
	if (back == nullptr)
	{
		return true;
	}
	return false;
}

size_t Stack::size()
{
	size_t i = 0;
	node *temp = back;
	while (temp != nullptr)
	{
		temp = temp->next;
		i++;
	}
	return i;
}

int Stack::top()
{
	return back->data;
}

void Stack::push(int d)
{
	node *temp = new node;
	temp->data = d;
	temp->next = back;
	back = temp;
}

void Stack::pop()
{
	node *temp = back;
	back = back->next;
	delete temp;
}

void Stack::print(ostream &fout)
{
	node *temp = back;
	while (temp != nullptr)
	{
		cout << "|" << setw(4) << temp->data;
		temp = temp->next;
	}
}