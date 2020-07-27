/*
Размерность контейнера и данные, хранящиеся в нем, вводятся с файла. После создания массива программа позволяет пользователю выполнить над контейнером структур следующие действия:
1.	Отсортировать массив по фамилиям студентов. Вывести отсортированный массив на консоль;
2.	Найти в массиве запись о студенте по его фамилии. Фамилия студента вводится с консоли, результат поиска также вывести на консоль.
3.	Отсортировать массив по группам, а внутри одной группы по фамилиям студентов. Вывести отсортированный массив на консоль.
4.	Вывести на консоль отчет о среднем бале студентов в каждой группе.
Для выполнения запросов разработать меню, которое выводится на консоль после обработки каждого запроса. 
Выход из программы выполняется по требованию пользователя. Для сортировки массива и поиска требуемой записи в массиве использовать стандартные функции сортировки и поиска.
*/
#include "StudContainer.h"
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
	//setlocale(LC_ALL, ".1251");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	ifstream fin("input.txt");
	int n;
	fin >> n;
	StudContainer st(n);
	while (!fin.eof())
	{
		Student s;
		string str;
		fin.ignore();
		getline(fin, str);
		strcpy(s.name, str.c_str());
		int group;
		fin >> group;
		s.num = group;
		double grade;
		fin >> grade;
		s.grade = grade;
		st.insert(s);
	}
	
	cout << "Reading have finished." << endl;

	cout << "1.	Отсортировать массив по фамилиям студентов. Вывести отсортированный массив на консоль;" << endl;
	cout << "2.	Найти в массиве запись о студенте по его фамилии. Фамилия студента вводится с консоли, результат поиска также вывести на консоль." << endl;
	cout << "3.	Отсортировать массив по группам, а внутри одной группы по фамилиям студентов. Вывести отсортированный массив на консоль." << endl;
	cout << "4.	Вывести на консоль отчет о среднем бале студентов в каждой группе." << endl;
	cout << "0. Выход" << endl;

	int ans = 1;
	while (ans)
	{
		cin >> ans;
		switch (ans)
		{
		case 1:
		{
			st.sortByName();
			st.print(cout);
			break;
		}
		case 2:
		{
			cout << "Введите фамилию и имя студента" << endl;
			char * str = new char[200];
			cin.ignore();
			cin.getline(str, 200);
			if (st.findByName(str) == nullptr)
			{
				cout << "Студент не найден" << endl;
			}
			else
			{
				Student *s = st.findByName(str);
				s->print();
			}
			break;
		}
		case 3:
		{
			st.sortByGroupAndName();
			st.print(cout);
			break;
		}
		case 4:
		{
			st.report(cout);
			break;
		}
		}
	}
	system("pause");
	return 0;
}