/*
	Герасимчик Анна. 1 курс. 7 группа.
	Условие:
		Задача Иосифа. Вокруг считающего стоит N человек, из которых 
	выделен первый, а  остальные  занумерованы  по  часовой стрелке 
	числами от 2 до N. Считающий,  начиная с кого-то, ведет счет до 
	M. Человек, на котором остановился счет, выходит из круга. Счет 
	продолжается со следующего человека и так до тех пор, пока не 
	останется один человек.  Определить номер оставшегося человека,
	если известно M и то, что счет начинался с первого человека. 
	Результат записать в текстовый  файл.
	Идея:
	Заведем список на N элементов (от 1 до N), где i элемент - i 
	человек. Зациклим его, т.е. head->prev = tail; tail->next = head.
	В цикле ходим по закольцованному списку, высчитываем следующую 
	позицию и удаляем элемент на этой позиции до тех пор, пока в 
	списке не останется 1 элемент.
	Тесты:
	input	output
1	10 3	4
2	5 3		4
3	6 2		5
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node						
{
	int  item;					
	node*  next;				
	node*  prev;				
};

node *head, *tail;

void InitList()						
{
	head = 0;
	tail = 0;
}

void push_back(int n)				
{
	node* tmp = new node;
	tmp->item = n;
	tmp->next = head;
	tmp->prev = tail;
	if (tail)
		tail->next = tmp;
	else
		head = tmp;
	tail = tmp;
}

int pop_front()					
{
	if (head)
	{
		int res = head->item;
		node *tmp = head;
		if (head->next)
			head->next->prev = 0;
		else
			tail = 0;
		head = head->next;
		delete tmp;
		return res;
	}
	return 0;
}

int pop_back()					
{
	if (tail)
	{
		int res = tail->item;
		node *tmp = tail;
		if (tail->prev)
			tail->prev->next = head;
		else
			head = 0;
		tail = tail->prev;
		delete tmp;
		return res;
	}
	return 0;
}

int remove(int pos, int n)			
{
	node* tmp = head;
	node *pre = head;
	for (int i = 0; i < pos; i++)
	{
		pre = tmp;
		tmp = tmp->next;
	}
	pre->next->prev = pre->prev;
	if (pre->prev != 0)
		pre->prev->next = pre->next;
	int res = pre->item;
	delete pre;
	tmp = 0;
	return res;
}

void print(int n)			
{
	node* temp = head;
	while (n)
	{
		cout << temp->item << " ";
		temp = temp->next;
		n--;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, ".1251");

	int n, m;
	cout << "Enter people amount" << endl;
	cin >> n;
	cout << "Number of person which must be killed" << endl;
	cin >> m;

	for (int i = 0; i < n; i++)
		push_back(i + 1);
	head->prev = tail;
	tail->next = head;
	
	print(n);
	int pos = 0;
	int i = 0;
	while (n > 1)
	{
		i++;
		cout << i << '\t';
		pos = pos + m;
		pos = pos % n;
		cout << " pos = " << pos << '\t';
		if (pos == 0)
		{
			pop_back();
		}
		else
		{
			if (pos == 1)
			{
				pop_front();
			}
			else
			{
				remove(pos, n);
			}
		}
		n--;
		if (pos)
			pos--;
		print(n);
	}
	cout << "Answer = ";
	print(n);

	system("pause");
	return 0;
}
