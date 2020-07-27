#include "StackArray.h"

StackArray::StackArray()
{
	size = 10;
	top = 0;
	ptr = new int[10];
}

StackArray::StackArray(const int& _size)
{
	size = _size;
	top = 0;
	ptr = new int[size];
}

StackArray::StackArray(const StackArray& s)
{
	size = s.size;
	top = s.top;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
		ptr[i] = s.ptr[i];
}

StackArray::~StackArray()
{
	delete[] ptr;
}

bool StackArray::isEmpty()
{
	return (!top);
}

bool StackArray::isFool()
{
	return (top == size);
}

int StackArray::peek()
{
	if (isEmpty())
		throw 
		return ptr[top - 1];
}

void StackArray::pop()
{
	if (isEmpty())
	{
		throw bad_alloc();
	}
	else
	{
		top--;
	}
}

void StackArray::push(int x)
{
	if (top != size)
	{
		ptr[top] = x;
		top++;
	}
	else throw bad_alloc();
}

void StackArray::clear()
{
	for (int i = 0; i < size; i++)
		ptr[i] = 0;
}

void StackArray::print()
{
	for (int i = top - 1; i >= 0; i--)
		cout << setw(4) << ptr[i];
	cout << endl;
}