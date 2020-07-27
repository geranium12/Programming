#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "Library.h"

using namespace std;
const int STR_SIZE = 80;

char *searchWord(char *str, const char *word, const int pos)
{
	int lenStr = strlen(str);
	int lenWord = strlen(word);
	int j = 0;

	for (int i = 0; i < pos; i++)
		str++;
	while (*str != '\0')
	{
		if (*str == word[j])
			j++;
		else
		{
			j = 0;
			if (*str == word[j])
				j++;
		}
		if (j == lenWord)
		{
			for (int i = j; i > (j - lenWord + 1); i--)
				str--;
			return str;
		}
		str++;
	}

	return str;
}

int searchWordInt(const char *str, const char *word, const int pos)
{
	int lenStr = strlen(str);
	int lenWord = strlen(word);
	int j = 0;

	for (int i = pos; i < lenStr; i++)
	{
		if (str[i] == word[j])
			j++;
		else
		{
			j = 0;
			if (str[i] == word[j])
				j++;
		}
		if (j == lenWord)
		{
			return (i - j + 1);
		}
	}

	return lenStr;
}

bool isPalindrome(const char *word)
{
	if (word == NULL)
		return false;
	if (*word == '\0')
		return false;
	int lenWord = strlen(word);
	int left = 0;
	int right = lenWord - 1;
	while (left < right)
	{
		if (word[left] != word[right])
			return false;
		left++;
		right--;
	}
	return true;
}

void deleteWord(char *str, const char *word)
{
	int pos = searchWordInt(str, word, 0);
	int lenStr = strlen(str);
	if (pos == lenStr)
		return;

	int lenWord = strlen(word);
	for (int i = 0; i < lenWord; i++)
		for (int j = pos; j < lenStr; j++)
			str[j] = str[j + 1];

}

void deleteWordPos(char *str, const char *word, const int pos)
{
	int searchPos = 0;
	searchPos = searchWordInt(str, word, searchPos);
	int lenStr = strlen(str);
	if (searchPos == lenStr)
		return;

	while (searchPos < pos)
	{
		searchPos = searchWordInt(str, word, searchPos);
		searchPos++;
	}

	int lenWord = strlen(word);
	for (int i = 0; i < lenWord; i++)
		for (int j = pos; j < lenStr; j++)
			str[j] = str[j + 1];
}

void insertWord(char *str, const char *currentWord, const char *insertWord)
{
	int searchPos = searchWordInt(str, currentWord, 0);
	int lenCurWord = strlen(currentWord);
	searchPos += lenCurWord;
	int lenStr = strlen(str);
	int lenInsWord = strlen(insertWord);

	for (int i = 0; i < lenInsWord; i++)
		for (int j = lenStr + i + 1; j > searchPos + i; j--)
			str[j] = str[j - 1];
	for (int i = searchPos; i < lenInsWord + searchPos; i++)
		str[i] = insertWord[i - searchPos];
}

void insertWordPos(char *str, const char *insertWord, const int pos)
{
	int lenStr = strlen(str);
	int lenInsWord = strlen(insertWord);

	for (int i = 0; i < lenInsWord; i++)
		for (int j = lenStr + i + 1; j > pos + i; j--)
			str[j] = str[j - 1];
	for (int i = pos; i < lenInsWord + pos; i++)
		str[i] = insertWord[i - pos];
}

void swapWords(char *str, const char *word1, const char *word2, const char pos1, const char pos2)
{
	//int lenWord1 = strlen(word1);
	//char *savedWord = new char[lenWord1];
	//strcpy(savedWord, word1);
	deleteWordPos(str, word1, pos1);
	insertWordPos(str, word2, pos1);
	deleteWordPos(str, word2, pos2);
	insertWordPos(str, word1, pos2);
}

void replaceWord(char *str, const char *replaceWord, char *insertWord)
{
	int searchPos = searchWordInt(str, replaceWord, 0);
	deleteWord(str, replaceWord);
	insertWordPos(str, insertWord, searchPos);
}

char **divideStr(char *str, char *newStr, int &countWords, int &countNewStr)
{
	char **words = new char*[STR_SIZE];
	strcpy(newStr, "");
	countWords = 0;
	countNewStr = 0;
	char *pword = new char[STR_SIZE];
	strcpy(pword, "");
	int cur = 0;
	int lenStr = strlen(str);
	int k = 0;

	while (cur <= lenStr)
	{
		if (isalnum(str[cur]))
		{
			pword[k] = str[cur];
			k++;
		}
		else
		{
			if (*pword != '\0')
			{
				newStr[countNewStr] = '1';
				countNewStr++;
				pword[k] = '\0';
				k++;
				words[countWords] = new char[STR_SIZE];
				for (int j = 0; j < k; j++)
					words[countWords][j] = pword[j];
				strcpy(pword, "");
				countWords++;
				k = 0;
			}
			newStr[countNewStr] = str[cur];
			countNewStr++;
		}
		cur++;
	}
	return words;
}

void mergeWords(char *str, char **words, char *newStr, const int &countWords, const int &countNewStr)
{
	strcpy(str, "");
	int cur = 0;
	int countStr = 0;
	int countWord = 0;
	while (cur < countNewStr)
	{
		if (newStr[cur] != '1')
		{
			str[countStr] = newStr[cur];
			countStr++;
		}
		else
		{
			char *pword = words[countWord];
			int lenPword = strlen(pword);
			for (int i = 0; i < lenPword; i++)
			{
				str[countStr] = pword[i];
				countStr++;
			}
			countWord++;
		}
		cur++;
	}
}

void sortWords(char *str)
{
	char **words = new char*[STR_SIZE];
	char *newStr = new char[STR_SIZE];
	int countWords, countNewStr;

	words = divideStr(str, newStr, countWords, countNewStr);

	for (int i = 0; i < countWords; i++)
		for (int j = 0; j < countWords - i - 1; j++)
		{
			if (strcmp(words[j], words[j + 1]) > 0)
			{
				int lenWord1 = strlen(words[j]);
				char *savedWord = new char[lenWord1];
				strcpy(savedWord, words[j]);
				replaceWord(words[j], words[j], words[j + 1]);
				replaceWord(words[j + 1], words[j + 1], savedWord);
			}
		}

	mergeWords(str, words, newStr, countWords, countNewStr);
}

int compare(const void *a, const void *b)
{
	char *str1 = *(char **)a;
	char *str2 = *(char **)b;
	return strcmp(str1, str2);
}

void qsortWords(char *str)
{
	char **words = new char*[STR_SIZE];
	char *newStr = new char[STR_SIZE];
	int countWords, countNewStr;

	words = divideStr(str, newStr, countWords, countNewStr);
	qsort(words, countWords, sizeof(char *), compare);
	mergeWords(str, words, newStr, countWords, countNewStr);
}

char *searchNumber(char *str, const char *seps, char *nextStr)
{
	char *pword = strtok_s(str, seps, &nextStr);
	while (pword != NULL)
	{
		int lenWord = strlen(pword);
		int i = 0;
		while ((isdigit(pword[i])) && (i < lenWord))
			i++;
		if (i == lenWord)
			return pword;
		else
			pword = strtok_s(nextStr, seps, &nextStr);
	}
	return NULL;
}

bool isNumber(char *word)
{
	int lenWord = strlen(word);
	int i = 0;
	while ((isdigit(word[i])) && (i < lenWord))
		i++;
	if (i == lenWord)
		return 1;
	else
		return 0;
}