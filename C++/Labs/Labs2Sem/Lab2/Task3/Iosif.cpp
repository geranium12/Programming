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
	человек. В цикле ходим по списку, высчитываем следующую 
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
#include <list>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");

	int n, m;
	cout << "Enter people amount" << endl;
	cin >> n;
	cout << "Number of person which must be killed" << endl;
	cin >> m;

	list <int> l;
	for (int i = 0; i < n; i++)
		l.push_back(i + 1);
	
	int pos = 0;
	int i = 0;
	while (n > 1)
	{
		//list<int>::iterator it = l.begin();
		//for (it = l.begin(); it != l.end(); it++)
		//	cout << *it << " ";
		i++;
		cout << i << '\t';
		pos = pos + m;
		pos = pos % n;
		cout << " pos = " << pos << '\n';
		if (pos == 0)
		{
			l.pop_back();
		}
		else
		{
			if (pos == 1)
			{
				l.pop_front();
			}
			else
			{
				list<int>::iterator it = l.begin();
				for (int j = 0; j < pos - 1; j++)
					it++;
				l.erase(it);
			}
		}
		n--;
		if (pos)
			pos--;
	}
	cout << "Answer = " << l.front() << endl;

	system("pause");
	return 0;
}
