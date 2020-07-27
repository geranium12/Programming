#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class String
{
private:
	char *p;
	int size;

public:
	String();
	String(int _size);
	String(char *_p, int _size);
	String(const String& str);
	~String();

	String operator +(const String& str);
	String& operator =(const String& str);
	String& operator +=(const String& str);
	
	friend bool operator ==(const String& str1, const String& str2);
	friend bool operator !=(const String& str1, const String& str2);
	friend bool operator <(const String& str1, const String& str2);
	friend bool operator >(const String& str1, const String& str2);
	friend bool operator <=(const String& str1, const String& str2);
	friend bool operator >=(const String& str1, const String& str2);
	char operator [](int i);
	// operator ()


	friend istream& operator >>(istream& in, String& str);
	friend ostream& operator <<(ostream& out, const String& str);

	friend int searchWordInt(const String str, const String word, const int pos, bool dir);
	friend void insertWordPos(String& str, const String insertWord, const int pos);
	friend void replaceWord(String& str, const String replaceWord, String insertWord);
};
