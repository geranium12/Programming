/*
	Герасимчик Анна. 1 курс. 7 группа
	Условие:
	2.14. Разработать программу для работы с отображениями (multimap). 
	Информационное поле каждого элемента представляет собой структуру, содержащую имя(строку), 
																					возраст (вещественные числа).
	Использовать собственный критерий сортировки(*).
	Программа должна выводить на экран компьютера меню вида:
1. Добавить элемент
2. Удалить элемент
3. Поиск элементов меньших равных заданному ключу
4. Обменивает  значения двух объектов (отображений)
5. Замена элемента
6. Сравнение отображений
7. Выход из программы
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

class Person
{
public:
	string name;
	double age;
	
	friend istream& operator >>(istream& in, Person& p);
	friend ostream& operator <<(ostream& out, const Person& p);
};

istream& operator >>(istream& in, Person& p)
{
	in >> p.name >> p.age;
	return in;
}

ostream& operator <<(ostream& out, const Person& p)
{
	out << p.name << '\t' << p.age;
	return out;
}

void printMenu()
{
	cout << "MENU : " << endl;
	cout << "1. Add element." << endl;
	cout << "2. Delete element." << endl;
	cout << "3. Find elements < or = your ID." << endl;
	cout << "4. Swap 2 elements." << endl;
	cout << "5. Replace element." << endl;
	cout << "6. Compare 2 elements." << endl;
	cout << "7. Print multimap." << endl;
	cout << "0. Exit." << endl;
}

void readData(multimap <int, Person> &m, ifstream& in)
{
	m.clear();
	//int i = 0;
	while (!in.eof())
	{
		int x;
		in >> x;
		Person p;
		in >> p;
		m.insert(make_pair(x, p));
		//i++;
	}
}

void printMultimap(multimap <int, Person> &m)
{
	cout << "Multimap of people :" << endl;
	for (multimap <int, Person>::iterator it = m.begin(); it != m.end(); it++)
	{
		//pair <int, Person> p2 = *it;
		cout << setw(4) << (*it).first << '\t' << (*it).second.name << '\t' << (*it).second.age << endl;
	}
}

void addElement(multimap <int, Person> &m)
{
	cout << "Fill these fields to insertion." << endl;
	cout << "Enter ID : \t";
	int x;
	cin >> x;
	Person p;
	cout << "Enter name : \t";
	cin >> p.name;
	cout << "Enter age : \t";
	cin >> p.age;
	//cout << "Enter a position that you want to insert the new element?" << endl;
	//int x;
	//cin >> x;
	m.insert(make_pair(x, p));
	cout << "Addition has finished succesful." << endl;
}

void delElement(multimap <int, Person> &m)
{
	cout << "Enter the ID of people you want to delete. \t" << endl;
	int x;
	cin >> x;
	m.erase(x);
	cout << "Deletion has finished succesful." << endl;
}

void findElements(multimap <int, Person> &m)
{
	cout << "Enter the ID to compare." << endl;
	int id;
	cin >> id;
	for (multimap <int, Person>::iterator it = m.begin(); it != m.end(); it++)
	{
		if ((*it).first <= id)
			cout << (*it).first << '\t' << (*it).second.name << '\t' << (*it).second.age << endl;
	}
	cout << "The search has finished succesful." << endl;
}

void swapElements(multimap <int, Person> &m)
{
	cout << "What are the two elements you want to swap? Enter their IDs." << endl;
	int x1, x2;
	bool flag = true;
	while (flag)
	{
		cin >> x1 >> x2;
		if ((x1 > 0) && (x2 > 0))
		{
			flag = false;
		}
		else
		{
			cout << "Wrong Indexes. Try again." << endl;
		}
	}

	multimap <int, Person>::iterator it1 = m.find(x1);
	multimap <int, Person>::iterator it2 = m.find(x2);

	if ((it1 == m.end()) || (it2 == m.end()))
	{
		cout << "Wrong IDs. The operation has finished." << endl;
		return;
	}

	pair <int, Person> p1 = *it1;
	pair <int, Person> p2 = *it2;
	swap(p1.first, p2.first);
	m.erase(p1.first);
	m.erase(p2.first);
	m.insert(p1);
	m.insert(p2);
	cout << "The operation has finished successful." << endl;
}

void replElement(multimap <int, Person> &m)
{
	cout << "Replacing process has started." << endl;
	delElement(m);
	addElement(m);
	cout << "Replacing process has finished." << endl;
}

void cmpElements(multimap <int, Person> &m)
{
	cout << "Enter IDs of elements you want to compare." << endl;
	int x1, x2;
	bool flag = true;
	while (flag)
	{
		cin >> x1 >> x2;
		if ((x1 > 0) && (x2 > 0))
		{
			flag = false;
		}
		else
		{
			cout << "Wrong IDs. Try again." << endl;
		}
	}

	multimap <int, Person>::iterator it1 = m.find(x1);
	multimap <int, Person>::iterator it2 = m.find(x2);

	if ((it1 == m.end()) || (it2 == m.end()))
	{
		cout << "Wrong IDs. The operation has finished." << endl;
		return;
	}

	if ((*it1).second.name > (*it2).second.name)
		cout << "The name of the 1st person is bigger than the name of the 2nd person." << endl;
	else
		if ((*it1).second.name < (*it2).second.name)
			cout << "The name of the 1st person is less than the name of the 2nd person." << endl;
		else 
			cout << "The name of the 1st person is equal to the name of the 2nd person." << endl;

	if ((*it1).second.age > (*it2).second.age)
		cout << "The age of the 1st person is bigger than the age of the 2nd person." << endl;
	else
		if ((*it1).second.age < (*it2).second.age)
			cout << "The age of the 1st person is less than the age of the 2nd person." << endl;
		else
			cout << "The age of the 1st person is equal to the age of the 2nd person." << endl;
	cout << "The comparing of elements has finished succesful." << endl;
}

bool compare()
{
	return true;
}

int main()
{
	// compare
	multimap <int, Person> m;
	//vector <Person> people;
	ifstream fin("data.txt");
	readData(m, fin);

	int flag = 1;
	while (flag)
	{
		printMenu();
		cin >> flag;
		switch (flag)
		{
			case 1:
				addElement(m);
				break;
			case 2:
				delElement(m);
				break;
			case 3:
				findElements(m);
				break;
			case 4:
				swapElements(m);
				break;
			case 5:
				replElement(m);
				break;
			case 6:
				cmpElements(m);
				break;	
			case 7:
				printMultimap(m);
				break;
			default:
				flag = 0;
		}
	}
	return 0;
}