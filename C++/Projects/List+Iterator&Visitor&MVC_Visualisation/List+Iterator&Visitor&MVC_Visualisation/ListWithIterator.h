#pragma once
#include <iostream>
#include "MyException.h"
#include "Visitors.h"
#include "ListIterator.h"

template <class T>
class List : public Element<T>
{
private:

	int size;
	int capacity;
	T* arr;

	void NeedToResize();
	void Resize(bool f);

public:

	friend class Iterator<T>;
	friend class ConstIterator<T>;

	friend class IteratorP<T>;

	List();
	List<T>(const int _capacity);
	List<T>(const std::initializer_list<T> &list);
	List<T>(const List<T> &list); // = delete;
	List<T>(List<T> &&list);
	~List<T>();

	bool IsEmpty() const;
	int Size() const;
	void Clear();

	List<T>& operator = (const List<T> &list); //= delete;
	List<T>& operator = (List<T> &&list);

	template <class T>
	friend std::istream& operator >> (std::istream& in, List<T> &list);
	template <class T>
	friend std::ostream& operator << (std::ostream& out, const List<T> &list);

	List<T> operator + (const List<T>& list) const;
	List<T>& operator += (const List<T>& list);
	bool operator == (const List<T> &list) const;
	bool operator != (const List<T> &list) const;

	T Front() const;
	T Back() const;
	void PushFront(T temp);
	void PushBack(T temp);
	void PopFront();
	void PopBack();
	
	template <class T>
	friend void Swap(List<T> &list1, List<T> &list2);

	/*
	Iterator createIterator()
	{
		return Iterator(*this);
	}

	ConstIterator createConstIterator() const
	{
		return ConstIterator(*this);
	}
	*/

	Iterator<T> begin();
	Iterator<T> end();
	ConstIterator<T> begin() const;
	ConstIterator<T> end() const;

	IteratorP<T>* createIterator() const;

	void accept(Visitor<T>& v) override;
};

template <class T>
void Swap(List<T> &list1, List<T> &list2)
{
	const List <T> temp = list1;
	list1 = list2;
	list2 = temp;
}

template <class T>
std::istream& operator >> (std::istream& in, List<T> &list)
{
	list.size = 0;
	list.capacity = 10;
	delete[] list.arr;
	list.arr = new T[list.capacity];

	while (in.peek() != '\n')
	{
		T temp;
		if (in >> temp)
		{
			list.PushBack(temp);
		}
		list.NeedToResize();
	}
	return in;
}

template <class T>
std::ostream& operator << (std::ostream& out, const List<T> &list)
{
	for (int i = 0; i < list.size; i++)
	{
		out << list.arr[i] << " ";
	}
	return out;
}

template <class T>
void List<T>::NeedToResize()
{
	if (size > 0.75 * capacity)
	{
		Resize(true);
	}
	else if (size < 0.25 * capacity)
	{
		Resize(false);
	}
}

template <class T>
void List<T>::Resize(bool f)
{
	if (f)
	{
		T *temp = new T[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		capacity = capacity << 1;
		delete[] arr;
		arr = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
		delete[] temp;
	}
	else
	{
		T *temp = new T[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		capacity = capacity >> 1;
		delete[] arr;
		arr = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
		delete[] temp;
	}
}

template <class T>
List<T>::List()
{
	size = 0;
	capacity = 10;
	arr = new T[capacity];
}

template <class T>
List<T>::List(const int _capacity)
{
	size = 0;
	capacity = _capacity;
	arr = new T[capacity];
}

template <class T>
List<T>::List(const std::initializer_list<T> &list)
{
	size = 0;
	capacity = list.size() * 2;
	arr = new T[capacity];
	for (auto &element : list)
	{
		arr[size] = element;
		size++;
	}
	NeedToResize();
}

template <class T>
List<T>::List(const List<T> &list)
{
	capacity = list.capacity;
	arr = new T[capacity];
	size = 0;
	while (size < list.size)
	{
		arr[size++] = list.arr[size];
	}
}

template <class T>
List<T>::List(List<T> &&list) : size(list.size), capacity(list.capacity), arr(list.arr)
{
	list.size = 0;
	list.arr = nullptr;
}

template <class T>
List<T>::~List<T>()
{
	delete[] arr;
}

template <class T>
bool List<T>::IsEmpty() const
{
	return (size == 0);
}

template <class T>
int List<T>::Size() const
{
	return size;
}

template <class T>
void List<T>::Clear()
{
	size = 0;
	NeedToResize();
}

template <class T>
List<T>& List<T>::operator = (const List<T> &list)
{
	if (&list == this)
		return *this;
	delete[] arr;
	size = list.size;
	capacity = list.capacity;
	arr = new T[capacity];
	for (int i = 0; i < list.size; i++)
	{
		arr[i] = list.arr[i];
	}
	return *this;
}

template <class T>
List<T>& List<T>::operator = (List<T> &&list)
{
	if (&list == this)
		return *this;

	delete[] arr;

	size = list.size;
	capacity = list.capacity;
	arr = list.arr;

	list.size = 0;
	list.arr = nullptr;
	return *this;
}

template <class T>
List<T> List<T>::operator + (const List<T>& list) const
{
	List<T> temp = *this;
	while (temp.size + list.size >= temp.capacity)
	{
		temp.Resize(true);
	}
	for (int i = 0; i < list.size; i++)
	{
		temp.PushBack(list.arr[i]);
	}
	temp.NeedToResize();
	return temp;
}

template <class T>
List<T>& List<T>::operator += (const List<T>& list)
{
	while (size + list.size < capacity)
	{
		Resize(true);
	}
	for (int i = 0; i < list.size; i++)
	{
		PushBack(list.arr[i]);
	}
	NeedToResize();
	return *this;
}

template <class T>
bool List<T>::operator == (const List<T> &list) const
{
	if (size == list.size)
	{
		int i = 0;
		while ((arr[i] == list.arr[i]) && (i < size))
		{
			i++;
		}
		if (i == size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

template <class T>
bool List<T>::operator != (const List<T> &list) const
{
	return !(*this == list);
}

template <class T>
T List<T>::Front() const
{
	return arr[0];
}

template <class T>
T List<T>::Back() const
{
	return arr[size - 1];
}

template <class T>
void List<T>::PushFront(T temp)
{
	for (int i = size; i > 0; i--)
	{
		arr[i] = arr[i - 1];
	}
	size++;
	arr[0] = temp;
	NeedToResize();
}

template <class T>
void List<T>::PushBack(T temp)
{
	arr[size] = temp;
	size++;
	NeedToResize();
}

template <class T>
void List<T>::PopFront()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = arr[i + 1];
	}
	size--;
	NeedToResize();
}

template <class T>
void List<T>::PopBack()
{
	size--;
	NeedToResize();
}

template <class T>
typename Iterator<T> List<T>::begin()
{
	return Iterator<T>(*this);
}

template <class T>
typename Iterator<T> List<T>::end()
{
	return Iterator<T>(*this, true);
}

template <class T>
typename ConstIterator<T> List<T>::begin() const
{
	return ConstIterator<T>(*this);
}

template <class T>
typename ConstIterator<T> List<T>::end() const
{
	return ConstIterator<T>(*this, true);
}

template <class T>
void List<T>::accept(Visitor<T>& v)
{
	for (auto it = begin(); it != end(); it++)
	{
		v.visit(*it);
	}
}

template <class T>
IteratorP<T>* List<T>::createIterator() const
{
	return new IteratorP<T>(this);
}
