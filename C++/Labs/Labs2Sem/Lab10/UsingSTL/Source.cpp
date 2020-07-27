/*
	Герасимчик Анна. 1 курс 7 группа
	Условие:
	4.  Разработать адаптер контейнера deque на основе vector. 
	Разработать функции добавления, печати, вычисления суммы элементов очереди.	
	Написать тестовую программу для типов int, double, char.
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template<typename T>
class Deque_v {
	std::vector<T> dv;
public:
	void push_back(T value)
	{
		dv.push_back(value);
	}
	void pop_front()
	{
		dv.erase(dv.begin());
	}
	void push_front(T value)
	{
		dv.insert(dv.begin(), value);
	}
	void pop_back()
	{
		dv.pop_back();
	}
	T front()
	{
		return dv.front();
	}
	T back()
	{
		return dv.back();
	}
	bool empty()
	{
		return dv.empty();
	}
	T sum()
	{
		T sum = 0;
		for (int i = 0; i < dv.size(); i++)
		{
			sum += dv[i];
		}
		return sum;
	}
	void print()
	{
		for (int i = 0; i < dv.size(); i++)
			cout << setw(6) << T(dv[i]) << " ";
		cout << endl;
	}
};

int main()
{
	// int
	cout << "INT" << endl;
	cout << "push_back" << endl;
	Deque_v <int> di;
	for (int i = 0; i < 10; i++)
		di.push_back(i + 1);
	di.print();

	cout << "pop_front" << endl;
	di.pop_front();
	di.print();

	cout << "push_front" << endl;
	di.push_front(12);
	di.print();

	cout << "pop_back" << endl;
	di.pop_back();
	di.print();

	cout << "front" << endl;
	cout << di.front() << endl;

	cout << "back" << endl;
	cout << di.back() << endl;

	cout << "Is empty? - ";
	if (di.empty())
		cout << "yes";
	else
		cout << "no" << endl;

	cout << "sum" << endl;
	cout << di.sum() << endl;


	// double
	cout << "DOUBLE" << endl;
	cout << "push_back" << endl;
	Deque_v <double> dd;
	for (int i = 0; i < 10; i++)
		dd.push_back(i + 0.25 * i);
	dd.print();

	cout << "pop_front" << endl;
	dd.pop_front();
	dd.print();

	cout << "push_front" << endl;
	dd.push_front(12.23);
	dd.print();

	cout << "pop_back" << endl;
	dd.pop_back();
	dd.print();

	cout << "front" << endl;
	cout << dd.front() << endl;

	cout << "back" << endl;
	cout << dd.back() << endl;

	cout << "Is empty? - ";
	if (dd.empty())
		cout << "yes";
	else
		cout << "no" << endl;

	cout << "sum" << endl;
	cout << dd.sum() << endl;


	// char
	cout << "CHAR" << endl;
	cout << "push_back" << endl;
	Deque_v <char> dc;
	for (int i = 0; i < 10; i++)
		dc.push_back(char(97 + i * 2));
	dc.print();

	cout << "pop_front" << endl;
	dc.pop_front();
	dc.print();

	cout << "push_front" << endl;
	dc.push_front('V');
	dc.print();

	cout << "pop_back" << endl;
	dc.pop_back();
	dc.print();

	cout << "front" << endl;
	cout << dc.front() << endl;

	cout << "back" << endl;
	cout << dc.back() << endl;

	cout << "Is empty? - ";
	if (dc.empty())
		cout << "yes";
	else
		cout << "no" << endl;

	cout << "sum" << endl;
	cout << dc.sum() << endl;
	system("pause");
	return 0;
}