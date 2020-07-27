/*
	Герасимчик Анна. 1 курс. 7 группа
	Условие:
	Задано выражение (инфиксная форма, например (5+45)*(55-5))  
	содержащее числа (любого типа), знаки операций, круглые скобки. 
	Записать его в виде обратной польской записи (постфиксная форма) 
	и вычислить его значение.
	Идея:
	Используем структуру данных стек для перевода из инфиксной записи
	в постфиксную и для дальнейшего подсчета постфиксного выражения.
	Алгоритм очевиден и описан в файле с условием.
	Тесты:
	input		output
	input.txt	output.txt
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Library.h"

using namespace std;

extern const char STR_SIZE;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	if (!fin.is_open())
	{
		cout << "Error opening file" << endl;
		system("pause");
	}
	else
	{
		while (!fin.eof())
		{
			char *str = new char[STR_SIZE];
			fin.getline(str, STR_SIZE);
			fout << str << " = ";
			str = toPostfix(str);
			int ans = calculate(str);
			fout << ans;
		}
	}
	return 0;
}