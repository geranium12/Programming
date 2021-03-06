/*
	Герасимчик Анна. 1 курс. 7 группа
	Условие:
0.1	Задана строка, слова которой  разделены некоторым множеством разделителей.  
Удалить все слова  палиндромы (т.е. одинаково читается как слева направо, так 
и наоборот) и записать эти слова  в новую строку. Найти наибольшее по длине 
слово палиндром и наибольшее по значению число-слово палиндром, номера этих 
слов в исходной строке и поменять их местами.
	Должны быть написаны  функции для решения следующих подзадач:
	Поиск слова в строке,  начиная  с заданной позиции;
	Проверки, является ли слово палиндромом;
	Удаление слова из строки;
	Удаление слова из строки, начиная  с заданной позиции;
	Вставка слова в строку после заданного слова.
	Обмен двух слов в строке, если известно  их расположение и длины;
	Замены слова в строке на новое слово
	Сортировка слов в строке
	Сортировка слов в строке используя стандартную функцию qsort.
	Поиск слов чисел
	Результаты поиска  записать в новую строку.
	Идея:
	Реализовать все функции и использовать для выполнения поставленной 
	задачи. К каждой функции есть комментарий.
	Тесты:
	input		output
	input.txt	output.txt
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <Windows.h>
#include "Library.h"

using namespace std;

const int STR_SIZE = 80;
const char *seps = " ,.:-;?!";

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	if (!fin.is_open())
	{
		cout << "Error opening file" << endl;
		system("pause");
		return 0;
	}
	char *str = new char[STR_SIZE];
	fin.getline(str, STR_SIZE);


	// Find the word with the biggest length and the max word-number among these words-palindromes
	// and find their numbers in the source string
	// Swap these two words

	// Delete all words-palindromes and write these words in the new string
	char *newStr = new char[STR_SIZE];
	int countWords, countNewStr;
	char **words = divideStr(str, newStr, countWords, countNewStr);

	char *strPalindrome = new char[STR_SIZE];
	strcpy(strPalindrome, "");
	for (int i = 0; i < countWords; i++)
	{
		char *pword = words[i];
		int lenPword = strlen(pword);
		if (isPalindrome(pword))
		{
			strcat(strPalindrome, words[i]);
			strcat(strPalindrome, " ");
			strcpy(words[i], "");
		}
	}

	mergeWords(str, words, newStr, countWords, countNewStr);

	fout << "String-no-palindrome" << endl;
	fout << str << endl;
	fout << "String-palindrome" << endl;
	fout << strPalindrome << endl;

	for (int i = 0; i < countWords; i++)
		delete[] words[i];

	// Find the word with the biggest length and the max word-number among these words-palindromes
	// and find their numbers in the source string and swap them
	char **wordsPalindromes = divideStr(strPalindrome, newStr, countWords, countNewStr);
	char *wordMaxLen = wordsPalindromes[0];
	int placeMaxLen = 0;
	int lenPword = strlen(wordMaxLen);
	for (int i = 1; i < countWords; i++)
	{
		int lenCurWord = strlen(wordsPalindromes[i]);
		if (lenPword < lenCurWord)
		{
			wordMaxLen = wordsPalindromes[i];
			lenPword = strlen(wordMaxLen);
			placeMaxLen = i;
		}
	}

	fout << "The word with the biggest length" << endl;
	fout << wordMaxLen << " place = " << placeMaxLen << endl;

	char *wordMaxNumPal = NULL;
	int placeMaxNumPal = -1;
	int number = -1;
	for (int i = 0; i < countWords; i++)
	{
		char *pword = wordsPalindromes[i];
		char flag = isNumber(pword);
		if (flag)
		{
			int num = strtod(pword, NULL);
			if (num > number)
			{
				wordMaxNumPal = pword;
				placeMaxNumPal = i;
				number = num;
			}
		}
	}
	if (number == -1)
	{
		fout << "The string does not contain a word-number-palindrome" << endl;
	}
	else
	{
		fout << "The max word-number" << endl;
		fout << wordMaxNumPal << " place = " << placeMaxNumPal << endl;
		
		swap(wordsPalindromes[placeMaxLen], wordsPalindromes[placeMaxNumPal]);
		mergeWords(strPalindrome, wordsPalindromes, newStr, countWords, countNewStr);
		fout << strPalindrome << endl;
	}
	return 0;
}