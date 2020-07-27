#include "QueueArray.h"

QueueArray::QueueArray()
{
	n = 11;
	ptr = new int[n - 1];
	head = tail = 0;
}

QueueArray::QueueArray(int _size)
{
	n = _size + 1;
	ptr = new int[n - 1];
	head = tail = 0;
}

QueueArray::QueueArray(const QueueArray & q)
{
	n = q.n;
	ptr = new int[n - 1];
	// просто скопировать от 0 до n - 1 может
	if (tail < head)
	{
		for (int i = head; i < n - 1; i++)
		{
			ptr[i] = q.ptr[i];
		}
		for (int i = 0; i < tail; i++)
		{
			ptr[i] = q.ptr[i];
		}
	}
	else
	{
		for (int i = head; i < tail; i++)
			ptr[i] = q.ptr[i];
	}

}

QueueArray::~QueueArray()
{
	delete[] ptr;
}

bool QueueArray::isEmpty()
{
	return head == tail;
}

size_t QueueArray::size()
{
	if (head > tail)
	{
		return n - head + tail;
	}
	else
	{
		return tail - head;
	}
}

void QueueArray::push_back(int x)
{
	if (n != (size() + 1))
	{
		ptr[tail] = x;
		tail = (tail + 1) % (n);
	}
	else throw bad_alloc();
}

void QueueArray::pop_front()
{
	if (isEmpty())
		throw bad_alloc();
	head = (head + 1) % (n);
}

int QueueArray::front()
{
	if (isEmpty())
		throw bad_alloc();
	return ptr[head];
}

int QueueArray::back()
{
	if (isEmpty())
		throw bad_alloc();
	return ptr[tail - 1];
}


// она точно работает?
bool QueueArray::isFool()
{
	//int temp = head;
	//if (!temp)
	//{ 
	//	temp = n + 1;
	//}
	return (size() + 1 == n);
}

void QueueArray::clear()
{
	for (int i = 0; i < n - 1; i++)
	{
		ptr[i] = 0;
	}
}

void QueueArray::print()
{
	if (tail <= head)
	{
		for (int i = head; i < n - 1; i++)
		{
			cout << setw(4) << ptr[i];
		}
		for (int i = 0; i < tail; i++)
		{
			cout << setw(4) << ptr[i];
		}
	}
	else
	{
		for (int i = head; i < tail; i++)
			cout << setw(4) << ptr[i];
	}
	cout << endl;
}