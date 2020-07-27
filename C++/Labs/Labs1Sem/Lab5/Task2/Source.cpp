/*
	Герасимчик Анна. 1 курс. 7 группа
	Условие:
	Задан  текстовый файл prog.cpp. Упорядочить (***написать 
	универсальную сортировку для любых типов данных***) слова в 
	строках этого файла по алфавиту, удалив все разделители между 
	словами, слова разделить одним  пробелом. Результаты записать 
	в новый файл SortSlova.txt.		Т.е. свою QSORT ***
	Идея:
	Создаем массив указателей на указатель char (массив строк char).
	Убираем разделители при вводе и загружаем слова в массив. 
	Сортируем данный массив своей quicksort. Выводим слова через 
	пробел.
	Тесты:
	input	output
	prog.cpp	SortSlova.txt
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int STR_SIZE = 300;
const char *seps = " ,.?!:;\t\n";

int partition(char **mas, int beg, int end)
{
	char *pivot = mas[end];
	int i = beg - 1;
	for (int j = beg; j < end; j++)
	{
		if (strcmp(mas[j], pivot) < 0)
		{
			i++;
			swap(mas[i], mas[j]);
		}
	}
	swap(mas[i + 1], mas[end]);
	return (i + 1);
}

void quickSort(char **mas, int beg, int end)
{
	if (beg < end)
	{
		int pivot = partition(mas, beg, end);

		quickSort(mas, beg, pivot - 1);
		quickSort(mas, pivot + 1, end);
	}
}

int main()
{
	setlocale(LC_ALL, ".1251");
	ifstream fin("prog.cpp");
	ofstream fout("SortSlova.txt");

	if (!fin.is_open())
	{
		cout << "Error opening file" << endl;
		system("pause");
	}
	else
	{
		fin.seekg(0, ios::end);
		int finSize = fin.tellg();
		fin.seekg(0, ios::beg);
		char **words = new char*[finSize];
		int countWords = 0;
		while (!fin.eof())
		{
			char *str = new char[STR_SIZE];
			fin.getline(str, STR_SIZE);

			// Method 1
			/*
			int lenStr = strlen(str);
			char *pword = new char[lenStr];
			strcpy(pword, "");
			int k = 0;
			for (int i = 0; i < lenStr + 1; i++)
			{
				char c = str[i];
				if ((ispunct(unsigned char(c))) || (iscntrl(unsigned char(c))) || (isspace(unsigned char(c))))
				{
					pword[k] = '\0';
					words[countWords] = new char[k];
					for (int j = 0; j <= k; j++)
						words[countWords][j] = pword[j];
					countWords++;
					strcpy(pword, "");
					k = 0;
				}
				else
				{
					pword[k] = c;
					k++;
				}
			}
			*/

			// Method 2
			char *pword = strtok(str, seps);
			while (pword != NULL)
			{
				int lenPword = strlen(pword);
				words[countWords] = new char[lenPword];
				for (int i = 0; i < lenPword + 1; i++)
					words[countWords][i] = pword[i];
				countWords++;
				pword = strtok(NULL, seps);
			}
			
		}

		quickSort(words, 0, countWords - 1);

		for (int i = 0; i < countWords; i++)
			fout << words[i] << ' ';

		fin.close();
		fout.close();
	}
	return 0;
}