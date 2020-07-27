#pragma once

#include <iostream>
#include <string>

using namespace std;

#include "Library.h"

const int SIZE_WORDS = 100;

string *divideStringToWords(string str, string seps, int &sizeStrArr);

void outputStrArr(const string *strArr, const int sizeStrArr);

string *sortWords(string *strArr, const int sizeStrArr);

int compare(const void *str1, const void *str2);

int amountOfLetters(string *strArr);

int amountOfWords(const int sizeStrArr);

string longWord(string *strArr, const int sizeStrArr);

string shortWord(string *strArr, const int sizeStrArr);

string searchNumber(const string *strArr, const int sizeStrArr);

bool isNumber(const string word);

string searchPalindrome(const string *strArr, const int sizeStrArr);

bool isPalindrome(const string word);