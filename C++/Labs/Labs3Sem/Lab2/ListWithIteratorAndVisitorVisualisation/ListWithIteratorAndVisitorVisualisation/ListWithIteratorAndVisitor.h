#pragma once
#include "MyException.h"
#include <iostream>

template <class T>
class Visitor
{
public:
	virtual void visit(T temp) = 0;

	virtual ~Visitor() = default;
};

template <class T>
class Element
{
public:
	virtual void accept(Visitor<T>& v) = 0;

	virtual ~Element() = default;
};

template <class T>
class SumVisitor : public Visitor<T>
{
private:
	T value;
	bool checkValue;
public:
	SumVisitor<T>()
	{
		checkValue = false;
	}
	bool check(T& temp)
	{
		if (!checkValue)
		{
			value = temp;
			checkValue = true;
			return false;
		}
		return true;
	}
	void visit(T temp) override
	{
		if (check(temp))
			value += temp;
	}

	T getValue()
	{
		return value;
	}
};

template <class T>
class MinVisitor : public Visitor<T>
{
private:
	T min;
	bool flag;
public:
	MinVisitor<T>()
	{
		flag = false;
	}
	bool check(T& temp)
	{
		if (!flag)
		{
			min = temp;
			flag = true;
			return false;
		}
		return true;
	}
	void visit(T temp) override
	{
		if ((check(temp)) && (temp < min))
			min = temp;
	}

	T getMin()
	{
		return min;
	}
};

template <class T>
class List : public Element<T>
{

private:
	int size;
	int capacity;
	T* arr;

	void NeedToResize();
	void Resize(bool f);

	class Iterator
	{
	private:

		friend class List;

		const List<T> & list;
		int index;

		Iterator(const List<T> & list2) : list(list2)
		{
			index = 0;
		}

		Iterator(const List<T> & list2, bool f) : list(list2)
		{
			index = list.size;
		}

	public:

		bool IsDone() const
		{
			return ((index >= list.size) || (index < 0));
		}

		Iterator& operator++()
		{
			index++;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator temp = *this;
			index++;
			return temp;
		}

		Iterator& operator--()
		{
			index--;
			return *this;
		}

		Iterator operator--(int)
		{
			Iterator temp = *this;
			index--;
			return temp;
		}

		T operator*() const
		{
			if (IsDone())
				throw MyException("Out of bounds of the list!", "", 0, "T operator*() const");
			return list.arr[index];
		}

		/*
		T& operator->() const
		{
			if (IsDone())
				throw MyException("Out of bounds of the list!", "", 0, "T& operator->() const");
			return *list.arr[index];
		}
		*/

		/*
		bool operator()() const
		{
			return (index == list.size);
		}
		*/

		bool operator == (const Iterator &it) const
		{
			if (list != it.list)
				return false;
			if (index != it.index)
				return false;
			return true;
		}

		bool operator != (const Iterator &it) const
		{
			return !(*this == it);
		}
	};

	const class ConstIterator
	{
	private:

		friend class List;

		const List<T> & list;
		int index;

		ConstIterator(const List<T> & list2) : list(list2)
		{
			index = 0;
		}

		ConstIterator(const List<T> & list2, bool f) : list(list2)
		{
			index = list.size;
		}

	public:

		bool IsDone() const
		{
			return ((index >= list.size) || (index < 0));
		}

		ConstIterator& operator++()
		{
			index++;
			return *this;
		}

		ConstIterator operator++(int)
		{
			ConstIterator temp = *this;
			index++;
			return temp;
		}

		ConstIterator& operator--()
		{
			index--;
			return *this;
		}

		ConstIterator operator--(int)
		{
			ConstIterator temp = *this;
			index--;
			return temp;
		}

		T operator*() const
		{
			if (IsDone())
				throw MyException("Out of bounds of the list!", "", 0, "T operator*() const");
			return list.arr[index];
		}

		/*
		T& operator->() const
		{
		if (IsDone())
				throw MyException("Out of bounds of the list!", "", 0, "T& operator->() const");
			return *list.arr[index];
		}
		*/

		/*
		bool operator()() const
		{
			return (index == list.size);
		}
		*/

		bool operator == (const ConstIterator &it) const
		{
			if (list != it.list)
				return false;
			if (index != it.index)
				return false;
			return true;
		}

		bool operator != (const ConstIterator &it) const
		{
			return !(*this == it);
		}
	};

public:
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

	Iterator begin()
	{
		return Iterator(*this);
	}

	Iterator end()
	{
		return Iterator(*this, true);
	}

	ConstIterator begin() const
	{
		return ConstIterator(*this);
	}

	ConstIterator end() const
	{
		return ConstIterator(*this, true);
	}

	void accept(Visitor<T>& v) override
	{
		for (auto it = begin(); it != end(); it++)
		{
			v.visit(*it);
		}
	}
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
		// copy() ???
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
	//iterator
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
	if (IsEmpty())
		throw MyException("", "", 0, "T List<T>::Front()", "The list is empty!");
	return arr[0];
}

template <class T>
T List<T>::Back() const
{
	if (IsEmpty())
		throw MyException("", "", 0, "T List<T>::Back()", "The list is empty!");
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

	if (IsEmpty())
		throw MyException("", "", 0, "void List<T>::PopFront()", "Wrong size of array!");

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
	if (IsEmpty())
		throw MyException("", "", 0, "void List<T>::PopBack()", "Wrong size of array!");
	size--;
	NeedToResize();
}