#pragma once

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
	SumVisitor()
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
	MinVisitor()
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
