#include <iostream>
#include "Library.h"

using namespace std;

StackNode *newNode(void *data)
{
	StackNode *temp = new StackNode;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

char isEmpty(StackNode *top)
{
	return (!top);
}

void push(StackNode **top, void *data)
{
	StackNode *temp = newNode(data);
	temp->next = *top;
	*top = temp;
}

void *pop(StackNode **top)
{
	if (isEmpty(*top))
	{
		cout << "Error: Stack underflow" << endl;
		abort();
		return false;
	}
	void *item = (*top)->data;
	StackNode *temp = *top;
	*top = (*top)->next;
	delete temp;
	return item;
}

void *peek(StackNode *top)
{
	if (isEmpty(top))
	{
		cout << "Error: StackNode underflow" << endl;
		abort();
		return false;
	}
	else
	{
		return top->data;
	}
}

size_t size(StackNode *top)
{
	size_t count = 0;
	if (!isEmpty(top))
	{
		StackNode *temp = top;
		while (temp)
		{
			count++;
			temp = temp->next;
		}
	}
	return count;
}