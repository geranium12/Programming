#include "Queue.h"

Queue::Queue()
{
	head = nullptr;
	tail = nullptr;
}

Queue::~Queue()
{
	node *temp = head;
	while (temp != nullptr)
	{
		node *temp2 = temp;
		temp = temp->next;
		delete temp2;
	}
}

bool Queue::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}

size_t Queue::size()
{
	size_t i = 0;
	node *temp = head;
	while (temp != nullptr)
	{
		temp = temp->next;
		i++;
	}
	return i;
}

int Queue::front()
{
	return head->data;
}

int Queue::back()
{
	return tail->data;
}

void Queue::push_back(int d)
{
	node *temp = new node;
	temp->data = d;
	temp->next = nullptr;
	if (isEmpty())
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void Queue::pop_front()
{
	node *temp = head;
	head = head->next;
	delete temp;
}

void Queue::print()
{
	node *temp = head;
	while (temp != nullptr)
	{
		cout << "|" << setw(4) << temp->data;
		temp = temp->next;
	}
}

void Queue::clear()
{
	node *temp = new node;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}