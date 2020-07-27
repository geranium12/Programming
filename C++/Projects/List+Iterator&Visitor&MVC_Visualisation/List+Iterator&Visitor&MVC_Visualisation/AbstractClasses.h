#pragma once

class AbstractView
{
protected:
	virtual void Front() = 0;
	virtual void Back() = 0;
	virtual void PushFront() = 0;
	virtual void PushBack() = 0;
	virtual void PopFront() = 0;
	virtual void PopBack() = 0;
	virtual void Clear() = 0;
	virtual void All() = 0;
	virtual void Sum() = 0;
	virtual void Min() = 0;
};

template <class T>
class AbstractController
{
protected:
	virtual T Front() = 0;
	virtual void Back() = 0;
	virtual void PushFront() = 0;
	virtual void PushBack() = 0;
	virtual void PopFront() = 0;
	virtual void PopBack() = 0;
	virtual void Clear() = 0;
	virtual void All() = 0;
	virtual void Sum() = 0;
	virtual void Min() = 0;
};

