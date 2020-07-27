#include "SingleList.h"

SingleList::SingleList()
{
	head = nullptr;
	tail = nullptr;
}

SingleList::SingleList(const SingleList& lst)
{
	head = new node;
	if (lst.head == lst.tail)
	{
		head->data = lst.head->data;
		head->next = nullptr;
		tail = head;
	}
	else
	{
		node *cur = lst.head;
		head->data = cur->data;
		node *prev = head;
		cur = cur->next;
		while (cur != nullptr)
		{
			node *temp = new node;
			temp->data = cur->data;
			prev->next = temp;
			prev = temp;
			cur = cur->next;
		}
		tail = prev;
		tail->next = nullptr;
	}
}

SingleList::~SingleList()
{
	while (head != nullptr)
	{
		node *temp = head;
		head = head->next;
		delete temp;
	}
}

bool SingleList::isEmpty()
{
	return (head == nullptr);
}

void SingleList::push_back(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = nullptr;
	if (isEmpty())
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void SingleList::push_front(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = head;
	head = temp;
	if (isEmpty())
	{
		tail = head;
	}
}

void SingleList::push(int pos, int value)
{
	node *pre = new node;
	node *cur = new node;
	node *temp = new node;
	cur = head;
	for (int i = 0; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;
	temp->next = cur;
}

int SingleList::pop_back()
{
	if (!isEmpty())
	{
		int value = tail->data;
		node *cur = new node;
		node *pre = new node;
		cur = head;
		while (cur->next != nullptr)
		{
			pre = cur;
			cur = cur->next;
		}
		cur = tail;
		tail = pre;
		delete cur;
		tail->next = nullptr;
		return value;
	}
	else
	{
		cout << "Error: stack underflow" << endl;
		abort();
	}
}

int SingleList::pop_front()
{
	if (!isEmpty())
	{
		node *temp = new node;
		int value = head->data;
		temp = head;
		head = head->next;
		delete temp;
		return value;
	}
	else
	{
		cout << "Error: stack underflow" << endl;
		abort();
	}
}

int SingleList::pop(int pos)
{
	node *cur = new node;
	node *pre = new node;
	cur = head;
	for (int i = 0; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	int value = cur->data;
	pre->next = cur->next;
	delete cur;
	return value;
}

int SingleList::peek(int pos)
{
	if (isEmpty())
	{
		cout << "Error: stack underflow" << endl;
		abort();
	}
	else
	{
		node *temp = new node;
		temp = head;
		while (pos--)
			temp = temp->next;
		int value = temp->data;
		return value;
	}
}

size_t SingleList::size()
{
	size_t count = 0;
	if (!isEmpty())
	{
		node *temp = new node;
		temp = head;
		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}
	}
	return count;
}

void SingleList::print()
{
	node *temp = new node;
	temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

node* SingleList::search()
{
	node *temp = head;
	while (temp != nullptr)
	{
		if (!(temp->data % 2))
			return temp;
		temp = temp->next;
	}
	return nullptr;
}

void SingleList::remove(node* adr)
{
	if (adr == head)
	{
		pop_front();
	}
	else
	{
		if (adr == tail)
		{
			pop_back();
		}
		else
		{
			node *temp = head;
			while (temp->next != adr)
			{
				temp = temp->next;
			}
			node *cur = temp->next;
			temp->next = cur->next;
			delete cur;
		}
	}
}

void SingleList::delchet()
{
	node *temp = search();
	while (temp != nullptr)
	{
		remove(temp);
		temp = search();
	}
}

int SingleList::smin()
{
	node *temp = head;
	int mmin = temp->data;
	temp = temp->next;
	while (temp != nullptr)
	{
		if (temp->data < mmin)
		{
			mmin = temp->data;
		}
		temp = temp->next;
	}
	return mmin;
}

void SingleList::invert()
{
	node *temp = head;
	for (int i = 0; i < size() / 2; i++)
	{
		temp->data *= -1;
		temp = temp->next;
	}
}