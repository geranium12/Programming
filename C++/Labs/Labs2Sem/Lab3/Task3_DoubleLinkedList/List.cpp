#include "List.h"

List::List()
{
	head = nullptr;
	tail = nullptr;
}

List::~List()
{
	node *temp = new node;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

int List::front()
{
	return head->data;
}

int List::back()
{
	return tail->data;
}

int List::peek(int n)
{
	node *temp = head;
	for (int i = 0; i < n && temp != nullptr; i++)
	{
		temp = temp->next;
	}
	if (temp != nullptr)
	{
		return temp->data;
	}
	else
	{
		return -1;
	}

}

bool List::isEmpty()
{
	if (head == nullptr)
		return true;
	return false;
}

size_t List::size()
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

void List::clear()
{
	node *temp = new node;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

void List::insert(int d, int pos)
{
	if (pos == 0)
	{
		push_front(d);
	}
	else
	{
		if (pos == size())
		{
			push_back(d);
		}
		else
		{
			node *temp = new node;
			temp->data = d;
			node *pre = head;
			for (int i = 0; i < pos - 1; i++)
			{
				pre = pre->next;
			}
			node *nex = pre->next;
			pre->next = temp;
			temp->prev = pre;
			nex->prev = temp;
			temp->next = nex;
		}
	}
}

void List::erase(int q, int pos)
{
	node *temp = head;
	for (int i = 0; i < pos && i < size() - 1; i++)
	{
		temp = temp->next;
	}
	node *first = temp->prev;
	while (q && temp != nullptr)
	{
		node *cur = temp;
		temp = temp->next;
		delete cur;
		q--;
	}
	if (temp != nullptr)
	{
		node *last = temp;
		first->next = last;
		last->prev = first;
	}
	else
	{
		tail = first;
		tail->next = nullptr;
	}
}

void List::push_back(int d)
{
	node *temp = new node;
	temp->prev = temp->next = nullptr;
	temp->data = d;
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

void List::pop_back()
{
	node *temp = tail;
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
}

void List::push_front(int d)
{
	node *temp = new node;
	temp->prev = temp->next = nullptr;
	temp->data = d;
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

void List::pop_front()
{
	node *temp = head;
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
}

void List::print()
{
	node *temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void List::reverse()
{
	node *temp = head;
	node *prev = nullptr, *next = nullptr;
	while (temp != nullptr)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	head = prev;
	temp = head;
	while (temp != nullptr)
	{
		tail = temp;
		temp = temp->next;
	}
}

void List::swap(node *a, node *b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void List::bubbleSort()
{
	int flag, i;
	node *ptr = new node;
	node *lptr = nullptr;
	if (isEmpty())
	{
		return;
	}
	do
	{
		flag = 0;
		ptr = head;
		while (ptr->next != lptr)
		{
			if (ptr->data > ptr->next->data)
			{
				swap(ptr, ptr->next);
				flag = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
	} while (flag);
}

List & List::operator = (List &r)
{
	if (this == &r)
	{
		return *this;
	}
	clear();
	node *temp = r.head;
	while (temp != nullptr)
	{
		push_back(temp->data);
		temp = temp->next;
	}
	return *this;
}