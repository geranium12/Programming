#pragma once

template <class T>
class List;

template <class T>
class Iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	const List<T>& list;
	int index;

	Iterator(const List<T>& list2) : list(list2)
	{
		index = 0;
	}

	Iterator(const List<T>& list2, bool f) : list(list2)
	{
		index = list.size;
	}

public:
	
	friend class List<T>;

	bool IsDone() const
	{
		return ((index >= list.size) || (index < 0));
	}

	Iterator<T>& operator++()
	{
		index++;
		return *this;
	}

	Iterator<T> operator++(int)
	{
		Iterator<T> temp = *this;
		index++;
		return temp;
	}

	Iterator<T>& operator--()
	{
		index--;
		return *this;
	}

	Iterator<T> operator--(int)
	{
		Iterator<T> temp = *this;
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

	bool operator == (const Iterator<T>& it) const
	{
		if (list != it.list)
			return false;
		if (index != it.index)
			return false;
		return true;
	}

	bool operator != (const Iterator<T>& it) const
	{
		return !(*this == it);
	}
};

template <class T>
class ConstIterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:

	const List<T>& list;
	int index;

	ConstIterator(const List<T>& list2) : list(list2)
	{
		index = 0;
	}

	ConstIterator(const List<T>& list2, bool f) : list(list2)
	{
		index = list.size;
	}

public:

	bool IsDone() const
	{
		return ((index >= list.size) || (index < 0));
	}

	ConstIterator<T>& operator++()
	{
		index++;
		return *this;
	}

	ConstIterator<T> operator++(int)
	{
		ConstIterator<T> temp = *this;
		index++;
		return temp;
	}

	ConstIterator<T>& operator--()
	{
		index--;
		return *this;
	}

	ConstIterator<T> operator--(int)
	{
		ConstIterator<T> temp = *this;
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

	bool operator == (const ConstIterator<T>& it) const
	{
		if (list != it.list)
			return false;
		if (index != it.index)
			return false;
		return true;
	}

	bool operator != (const ConstIterator<T>& it) const
	{
		return !(*this == it);
	}
};

template <class T>
class IteratorP
{
private:
	const List<T>* list;
	int index;

public:
	IteratorP<T>(const List<T>* list2) : list(list2)
	{
		index = 0;
	}

	void First() const
	{
		index = 0;
	}

	bool IsDone() const
	{
		return ((index >= list->Size()) || (index < 0));
	}

	void Next()
	{
		index++;
	}

	void Prev()
	{
		index--;
	}

	T CurrentItem() const
	{
		if (IsDone())
			throw MyException("Out of bounds of the list!", "", 0, "T CurrentItem() const");
		return list->arr[index];
	}
};
