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