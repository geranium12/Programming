#pragma once
#include <Windows.h>
#include "Resource.h"
#include "View.h"
#include "ListWithIterator.h"

#include <algorithm>

struct SumStruct
{
	SumStruct() : sum{ 0 } { }
	void operator()(int n) { sum += n; }
	int sum;
};

template <class T>
class Controller
{
private:
	List<int>* list;
	View<int>* view;
	
public:
	Controller(List<T>* _list, View<T>* _view) : list(_list), view(_view) {}

	void Front(HWND hWnd)
	{
		if (list->IsEmpty())
		{
			view->IsEmpty(hWnd);
		}
		else
		{
			int front = list->Front();
			view->Front(front, hWnd);
		}
	}

	void Back(HWND hWnd)
	{
		if (list->IsEmpty())
		{
			view->IsEmpty(hWnd);
		}
		else
		{
			int back = list->Back();
			view->Front(back, hWnd);
		}
	}

	void PushFront(T value, HWND hWnd) {
		list->PushFront(value);
		view->PushFront(value, hWnd);
	}

	void PushBack(T value, HWND hWnd)
	{
		list->PushBack(value);
		view->PushBack(value, hWnd);
	}

	void PopFront(HWND hWnd)
	{
		if (list->IsEmpty())
		{
			view->IsEmpty(hWnd);
		}
		else
		{
			int front = list->Front();
			list->PopFront();
			view->PopFront(front, hWnd);
		}
	}

	void PopBack(HWND hWnd)
	{
		if (list->IsEmpty())
		{
			view->IsEmpty(hWnd);
		}
		else
		{
			int back = list->Back();
			list->PopBack();
			view->PopBack(back, hWnd);
		}
	}

	void Clear(HWND hWnd)
	{
		list->Clear();
		view->Clear(hWnd);
	}

	void OutputAll(List<T>* list, HWND hWnd)
	{
		if (list->IsEmpty())
		{
			view->IsEmpty(hWnd);
		}
		else
		{
			view->SetContainer(list);
			view->OutputAll(hWnd);
		}
	}

	void Sum(HWND hWnd)
	{	
		if (list->IsEmpty())
		{
			view->IsEmpty(hWnd);
		}
		else
		{
			//SumStruct s = std::for_each(list->begin(), list->end(), SumStruct());
			//view->Sum(s.sum, hWnd);

			SumVisitor<int> visitor;
			list->accept(visitor);
			int sum = visitor.getValue();
			view->Sum(sum, hWnd);
		}
	}

	void Min(HWND hWnd)
	{
		if (list->IsEmpty())
		{
			view->IsEmpty(hWnd);
		}
		else
		{
			MinVisitor<int> visitor;
			list->accept(visitor);
			int min = visitor.getMin();
			view->Min(min, hWnd);
		}
	}
};
