#include "Library.h"

string *divideStringToWords(string str, string seps, int &sizeStrArr)
{
	string *strArr = new string[100];
	int pos = 0;
	int i = 0;
	while (pos != -1)
	{
		pos = str.find_first_of(seps);
		if ((pos == -1) && (str != ""))
		{
			//cout << str << endl;
			strArr[i] = str;
			i++;
		}
		else if ((pos != 0) && (str != ""))
		{
			string word(str, 0, pos);
			if (pos)
			{
				strArr[i] = word;
				i++;
			}
			str.erase(0, pos + 1);
		}
	}
	sizeStrArr = i;
	return strArr;
}

void outputStrArr(const string *strArr, const int sizeStrArr)
{
	for (int j = 0; j < sizeStrArr; j++)
		cout << strArr[j] << endl;
}

string *sortWords(string *strArr, const int sizeStrArr)
{
	qsort(strArr, sizeStrArr, sizeof(strArr[0]), compare);
	return strArr;
}

int compare(const void *str1, const void *str2)
{
	string s1 = *(string *)str1;
	string s2 = *(string *)str2;
	if (s1 > s2)
		return 1;
	if (s1 < s2)
		return -1;
	return 0;
}

int amountOfLetters(string *strArr)
{
	return sizeof(strArr) / sizeof(strArr[0]);
}

int amountOfWords(const int sizeStrArr)
{
	return sizeStrArr;
}

string longWord(string *strArr, const int sizeStrArr)
{
	string word = strArr[0];
	for (int j = 1; j < sizeStrArr; j++)
	{
		if (word.length() < strArr[j].length())
		{
			word = strArr[j];
		}
	}
	return word;
}

string shortWord(string *strArr, const int sizeStrArr)
{
	string word = strArr[0];
	for (int j = 1; j < sizeStrArr; j++)
	{
		if (word.length() > strArr[j].length())
		{
			word = strArr[j];
		}
	}
	return word;
}

string searchNumber(const string *strArr, const int sizeStrArr)
{
	for (int i = 0; i < sizeStrArr; i++)
	{
		string word = strArr[i];
		if (isNumber(word))
		{
			return word;
		}
	}
	string word = "This string does not contain the word-number.";
	return word;
}

bool isNumber(const string word)
{
	string digits = "0123456789";
	int kol = 0;
	for (int i = 0; i < word.length(); i++)
	{
		if (isdigit(word[i]))
		{
			kol++;
		}
	}
	if (kol == word.length())
	{
		return true;
	}
	else
	{
		return false;
	}
}

string searchPalindrome(const string *strArr, const int sizeStrArr)
{
	for (int i = 0; i < sizeStrArr; i++)
	{
		string word = strArr[i];
		if (isPalindrome(word))
		{
			return word;
		}
	}
	string word = "This string does not contain the word-number.";
	return word;
}

bool isPalindrome(const string word)
{
	string wordRev = word;
	reverse(wordRev.begin(), wordRev.end());
	if (wordRev.compare(word))
	{
		return false;
	}
	else
	{
		return true;
	}
}