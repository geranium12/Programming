#include "ClassString.h"
#include "MyException.h"

String::String()
{
	p = nullptr;
	size = 0;
}

String::String(int _size)
{
	try
	{
		if (_size <= 0)
			throw MyException("Cannot create the array with this size!", "", 0, "String::String(int _size)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	size = _size;
	p = new char[size];
}

String::String(char *_p, int _size)
{
	try
	{
		if (_size <= 0)
			throw MyException("Cannot create the array with this size!", "", 0, "String::String(int _size)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	size = _size;
	p = new char[size];
	strcpy(p, _p);
}
String::String(const String& str)
{
	size = str.size;
	p = new char[size];
	strcpy(p, str.p);
}
String::~String()
{
	delete[] p;
}

String String::operator +(const String& str)
{
	String temp;
	if (strlen(p) + strlen(str.p) > size)
	{
		temp.size = strlen(p) + strlen(str.p);
	}
	else
	{
		temp.size = size;
	}
	temp.p = new char[temp.size];
	strcpy(temp.p, p);
	strcat(temp.p, str.p);
	return temp;
}

String& String::operator =(const String& str)
{
	size = str.size;
	delete[] p;
	p = new char[size];
	strcpy(p, str.p);
	return *this;
}

String& String::operator +=(const String& str)
{
	if (strlen(p) + strlen(str.p) > size)
	{
		char* temp = new char[size];
		strcpy(temp, p);
		size = strlen(p) + strlen(str.p);
		p = new char[size];
		strcpy(p, temp);
		strcat(p, str.p);
		delete[] temp;
	}
	else
	{
		strcat(p, str.p);
	}
	return *this;
}

	
bool operator ==(const String& str1, const String& str2)
{
	return !strcmp(str1.p, str2.p);
}

bool operator !=(const String& str1, const String& str2)
{
	return strcmp(str1.p, str2.p);
}

bool operator <(const String& str1, const String& str2)
{
	if (strcmp(str1.p, str2.p) == -1)
		return true;
	return false;
}

bool operator >(const String& str1, const String& str2)
{
	if (strcmp(str1.p, str2.p) == 1)
		return true;
	return false;
}

bool operator <=(const String& str1, const String& str2)
{
	if (strcmp(str1.p, str2.p) < 1)
		return true;
	else
		return false;
}

bool operator >=(const String& str1, const String& str2)
{
	if (strcmp(str1.p, str2.p) > -1)
		return true;
	else
		return false;
}

char String::operator [](int i)
{
	try
	{
		if (i < 0)
			throw MyException("Bad index of array!", "", 0, "char String::operator [](int i)");
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
	return p[i];
}

// operator ()

istream& operator >>(istream& in, String& str)
{
	in >> str.p;
	return in;
}

ostream& operator <<(ostream& out, const String& str)
{
	for (int i = 0; i < strlen(str.p); i++)
	{
		out << str.p[i];
	}
	return out;
}

int searchWordInt(const String str, const String word, const int pos, bool dir)
{
	if (!dir)
	{
		int lenStr = strlen(str.p);
		int lenWord = strlen(word.p);
		int j = 0;

		for (int i = pos; i < lenStr; i++)
		{
			if (str.p[i] == word.p[j])
				j++;
			else
			{
				j = 0;
				if (str.p[i] == word.p[j])
					j++;
			}
			if (j == lenWord)
			{
				return (i - j + 1);
			}
		}
	}
	else
	{
		int lenStr = strlen(str.p);
		int lenWord = strlen(word.p);
		int j = lenWord - 1;

		for (int i = lenStr - 1; i >= pos; i--)
		{
			if (str.p[i] == word.p[j])
				j--;
			else
			{
				j = lenWord - 1;
				if (str.p[i] == word.p[j])
					j--;
			}
			if (j == -1)
			{
				return i;
			}
		}
	}
	return strlen(str.p);
}

void insertWordPos(String& str, const String insertWord, const int pos)
{
	int lenStr = strlen(str.p);
	int lenInsWord = strlen(insertWord.p);

	for (int i = 0; i < lenInsWord; i++)
		for (int j = lenStr + i + 1; j > pos + i; j--)
			str.p[j] = str.p[j - 1];
	for (int i = pos; i < lenInsWord + pos; i++)
		str.p[i] = insertWord.p[i - pos];
}

void replaceWord(String& str, const String replaceWord, String insertWord)
{
	int searchPos = searchWordInt(str, replaceWord, 0, false);

	//deleteWord(str, replaceWord);
	int pos = searchWordInt(str, replaceWord, 0, false);
	int lenStr = strlen(str.p);
	if (pos == lenStr)
		return;

	int lenWord = strlen(replaceWord.p);
	for (int i = 0; i < lenWord; i++)
		for (int j = pos; j < lenStr; j++)
			str.p[j] = str.p[j + 1];

	insertWordPos(str, insertWord, searchPos);
}