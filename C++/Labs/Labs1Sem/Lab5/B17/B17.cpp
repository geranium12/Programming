/*
	Герасимчик Анна. 1 курс. 7 группа.
	Условие:
	B17. Задан текстовый файл Input.txt, состоящий  из слов. Разделителями 
	между словами является некоторое множество знаков препинания. Найти в 
	каждой строке  слова, которые начинаются с прописных букв и  слова, 
	которые начинаются со строчных. Буквы слов, которые начинаются с 
	прописных букв записать прописными буквами, которые начинаются со 
	строчных букв  – строчными.   Результат записать  в новый файл 
	Output.txt. Упорядочить слова  в полученных  строках по  убыванию 
	длин слов, сначала слова с прописными буквами, затем со строчными. 
	Результат сортировки записать в файл Out_sort.txt. 
	Идея:
	Тесты:
*/
#include <iostream>
#include <fstream>

using namespace std;

int SIZE_STR = 100;

int main()
{
	setlocale(LC_ALL, ".1251");
	ifstream fin("Input.txt");
	if (!fin.is_open())
	{
		cout << "Error opening file!" << endl;
		system("pause");
		return 1;
	}
	ofstream fout("Output.txt");
	while (!fin.eof())
	{		
		char *str = new char[SIZE_STR];
		fin.getline(str, SIZE_STR);
		fout << str;
	}
	fin.close();
	//ofstream fout("Output.txt");
	fout.close();
	//ofstream fout("Out_sort.txt");
	//fout.close();
	return 0;
}