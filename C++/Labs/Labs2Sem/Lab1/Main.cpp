/*
	Герасимчик Анна. 1 курс.
	Задача:
	Проверить функции  класса String:
		Преобразование С-строк в String;
		Найти подстроку (начиная с начала и с конца);
		Копирование;
		Сравнение;
		Замещение фрагмента строки на другой фрагмент;
		Вставка в строку другую строку с заданной позиции;
		Поиск символа (начиная с начала и с конца );
		Применить для решения любой задачи.
	Решенеие:
	Решаем задачу с помощью стандартных функций класса string.
	Примеры:
input
	Привет мир! Как у тебя дела?
	12
	м
output
	Input a string
	Привет мир! Как у тебя дела?
	Input array of char to string c++ - Привет мир! Как у тебя дела?
	Input a substring
	мир
	The position of substring from the beginning - 7
	The position of substring from the end - 7
	Input a string to copy
	Compare two strings - false
	Input a start position for replacement / insertion
	12
	Replacement - Привет мир! мир у тебя дела?
	Insertion - Привет мир! мирмир у тебя дела?
	Input a char for search in the string
	м
	The character position from the beginning - 7
	The character position from the end - 15
*/
#include <iostream>
#include <string>
#include <cstring>
#include <Windows.h>

using namespace std;

const int STR_SIZE = 100;

int main()
{
	//setlocale(LC_ALL, ".1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Input a string" << endl;
	char *cstr = new char[STR_SIZE];
	cin.getline(cstr, STR_SIZE);

	// c-string to string
	string str1(cstr);
	cout << "Input array of char to string c++ - " << str1 << endl;

	// search substring
	string str2;
	cout << "Input a substring" << endl;
	getline(cin, str2);
	int begpos = str1.find(str2);
	int endpos = str1.rfind(str2);
	cout << "The position of substring from the beginning - " << begpos << endl;
	cout << "The position of substring from the end - " << endpos << endl;

	// copy string
	cout << "Input a string to copy" << endl;
	str1.copy(cstr, 1);

	// compare two strings
	bool cmp = str1.compare(str2);
	cout << "Compare two strings - ";
	if (cmp)
	{
		cout << "false";
	}
	else
	{
		cout << "true";
	}
	cout << endl;

	// replacement a string fragment to another
	int pos = -1;
	while (pos < 0 || pos >= str1.length())
	{
		cout << "Input a start position for replacement / insertion" << endl;
		cin >> pos;
		if (pos < 0 || pos >= str1.length())
		{
			cout << "This position doesn't exist" << endl;
		}
	}
	str1.replace(pos, str2.length(), str2);
	cout << "Replacement - " << str1 << endl;

	// insertion a string
	str1.insert(pos, str2);
	cout << "Insertion - " << str1 << endl;

	// search a char from begin and end
	char c;
	cout << "Input a char for search in the string" << endl;
	cin >> c;
	pos = str1.find_first_of(c);
	cout << "The character position from the beginning - " << pos << endl;
	pos = str1.find_last_of(c);
	cout << "The character position from the end - " << pos << endl;
	system("pause");
	return 0;
}