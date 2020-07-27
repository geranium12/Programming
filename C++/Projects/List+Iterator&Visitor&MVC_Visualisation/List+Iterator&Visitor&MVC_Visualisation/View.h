#pragma once

extern const int STR_SIZE;

template <class T>
class View
{
private:
	List<T>* list;
public:
	View() {}

	void IsEmpty(HWND hWnd)
	{
		char str[STR_SIZE] = "The list is empty!";
		SetDlgItemText(hWnd, ID_EDIT_OUTPUT, str);
	}

	void Front(T value, HWND hWnd)
	{
		char str[STR_SIZE];
		sprintf_s(str, STR_SIZE, "%d - front element.", value);
		SetDlgItemText(hWnd, ID_EDIT_OUTPUT, str);
	}

	void Back(T value, HWND hWnd)
	{
		char str[STR_SIZE];
		sprintf_s(str, STR_SIZE, "%d - back element.", value);
		SetDlgItemText(hWnd, ID_EDIT_OUTPUT, str);
	}

	void PushFront(T value, HWND hWnd) {
		char str[STR_SIZE];
		sprintf_s(str, STR_SIZE, "%d has been pushed front.", value);
		SetDlgItemText(hWnd, ID_EDIT_OUTPUT, str);
	}

	void PushBack(T value, HWND hWnd)
	{
		char str[STR_SIZE];
		sprintf_s(str, STR_SIZE, "%d has been pushed back.", value);
		SetDlgItemText(hWnd, ID_EDIT_OUTPUT, str);
	}

	void PopFront(T value, HWND hWnd)
	{
		char str[STR_SIZE];
		sprintf_s(str, STR_SIZE, "%d has been poped front.", value);
		SetDlgItemText(hWnd, ID_EDIT_OUTPUT, str);
	}

	void PopBack(T value, HWND hWnd)
	{
		char str[STR_SIZE];
		sprintf_s(str, STR_SIZE, "%d has been poped back.", value);
		SetDlgItemText(hWnd, ID_EDIT_OUTPUT, str);
	}

	void Clear(HWND hWnd)
	{
		char str[STR_SIZE];
		sprintf_s(str, STR_SIZE, "The data has been cleared.");
		SetDlgItemText(hWnd, ID_EDIT_OUTPUT, str);
	}

	void OutputAll(HWND hWnd)
	{
		/*
		char str[STR_SIZE] = "";

		for (auto element = list->begin(); element != list->end(); ++element)
		{
			strcat_s(str, STR_SIZE, std::to_string(*element).c_str());
			strcat_s(str, STR_SIZE, "\r\n");
		}

		SetDlgItemText(hWnd, ID_EDIT_OUTPUT, str);
		*/

		char str[STR_SIZE] = "";

		IteratorP<int>* it = list->createIterator();

		while (!it->IsDone())
		{
			strcat_s(str, STR_SIZE, std::to_string(it->CurrentItem()).c_str());
			strcat_s(str, STR_SIZE, "\r\n");
			it->Next();
		}

		SetDlgItemText(hWnd, ID_EDIT_OUTPUT, str);
	}

	void SetContainer(List<T>* _list)
	{
		list = _list;
	}

	void Sum(T value, HWND hWnd)
	{
		char str[STR_SIZE];
		sprintf_s(str, STR_SIZE, "Sum = %d", value);
		SetDlgItemText(hWnd, ID_EDIT_OUTPUT, str);
	}

	void Min(T value, HWND hWnd)
	{
		char str[STR_SIZE];
		sprintf_s(str, STR_SIZE, "Min = %d", value);
		SetDlgItemText(hWnd, ID_EDIT_OUTPUT, str);
	}
};