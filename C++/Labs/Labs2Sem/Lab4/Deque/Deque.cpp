#include "Deque.h"

Deque::Deque()
{
	head = nullptr;
	tail = nullptr;
}

Deque::Deque(const Deque& d)
{
	if (d.head == nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = new node;
		node *curD = d.head;
		head->data = curD->data;
		head->prev = nullptr;
		node *prev = head;
		curD = curD->next;
		while (curD != nullptr)
		{
			node *temp = new node;
			temp->data = curD->data;
			temp->prev = prev;
			prev->next = temp;
			prev = temp;
			curD = curD->next;
		}
		prev->next = nullptr;
		tail = prev;
	}
}

Deque::~Deque()
{
	while (head != nullptr)
	{
		node *temp = head;
		head = head->next;
		delete temp;
	}
}

void Deque::insÍead(int n)
{
	node *temp = new node;
	temp->prev = temp->next = nullptr;
	temp->data = n;
	if (head == nullptr)
	{
		head = tail = temp;
	}
	else
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

void Deque::insTail(int n)
{
	node *temp = new node;
	temp->prev = temp->next = nullptr;
	temp->data = n;
	if (head == nullptr)
	{
		head = tail = temp;
	}
	else
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}

void Deque::print()
{
	node *temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int Deque::delHead()
{
	node *temp = head;
	int p = temp->data;
	head = head->next;
	if (head == nullptr)
	{
		head == tail;
	}
	else
	{
		head->prev = nullptr;
	}
	delete temp;
	return p;
}

int Deque::delTail()
{
	node *temp = tail;
	int p = temp->data;
	tail = tail->prev;
	if (tail == nullptr)
	{
		head = tail;
	}
	else
	{
		tail->next = nullptr;
	}
	delete temp;
	return p;
}

bool Deque::isEmpty()
{
	return (head == nullptr);
}