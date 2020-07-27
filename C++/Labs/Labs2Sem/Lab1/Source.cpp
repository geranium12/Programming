/*
	Герасимчик Анна. 1 курс 2 семестр
	Задача: Написать программу с заданными функциями и меню с ними.
		Разбить строку на слова.
		Посортировать строку по словам по алфавиту.
		Посчитать количество букв.
		Посчитать количество слов.
		Найти самое длинное слово.
		Найти самое короткое слово.
		Найти слово-число.
		Найти слово-палиндром.
	Решение: Используя стандартные функции класса string напишем заданные функции.
	Пример:
input	2
		3
		4
		5
		6
		7
		8
		9
		0
output	Hello
		world!
		Hello
		world!
		Количество букв 0
		Количество слов 2
		Самое длинное слово world!
		Самое короткое слово Hello
		Слово-число This string does not contain the word-number.
		Слово-палиндром This string does not contain the word-number.
*/
#include "Library.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int number = 1;
	cout << "default string = Hello world!" << endl;
	cout << "default seps =  .,;:\t\n" << endl; 
	cout << "Введите номер пункта" << endl;
	cout << "Меню:" << endl;
	cout << "1. Ввести строку и разделители" << endl;
	cout << "2. Разбить строку на слова" << endl;
	cout << "3. Посортировать строку по словам по алфавиту" << endl;
	cout << "4. Посчитать количество букв" << endl;
	cout << "5. Посчитать количество слов" << endl;
	cout << "6. Найти самое длинное слово" << endl;
	cout << "7. Найти самое короткое слово" << endl;
	cout << "8. Найти слово - число" << endl;
	cout << "9. Найти слово - палиндром" << endl;
	cout << "0. Выйти из программы" << endl;

	string str = "Hello world!";
	string seps = " .,;:\t\n";
	int sizeStrArr;
	string *strArr = divideStringToWords(str, seps, sizeStrArr);

	while (number)
	{
		cin >> number;
		switch (number)
		{
		case 1:	cout << "Введите строку" << endl;
				getline(cin, str);
				getline(cin, str);
				cout << "Введите разделители" << endl;
				getline(cin, seps);
				break;
		case 2:	strArr = divideStringToWords(str, seps, sizeStrArr);
				outputStrArr(strArr, sizeStrArr);
				break;
		case 3:	sortWords(strArr, sizeStrArr);
				outputStrArr(strArr, sizeStrArr);
				break;
		case 4:	cout << "Количество букв " << amountOfLetters(strArr) << endl;
				break;
		case 5: cout << "Количество слов " << amountOfWords(sizeStrArr) << endl;
				break;
		case 6:	cout << "Самое длинное слово " << longWord(strArr, sizeStrArr) << endl;
				break;
		case 7:	cout << "Самое короткое слово " << shortWord(strArr, sizeStrArr) << endl;
				break;
		case 8: cout << "Слово-число " << searchNumber(strArr, sizeStrArr) << endl;
				break;
		case 9: cout << "Слово-палиндром " << searchPalindrome(strArr, sizeStrArr) << endl;
				break;
		}
	}
	return 0;
}