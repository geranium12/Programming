#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

char *searchWord(char *str, const char *word, const int pos);

int searchWordInt(const char *str, const char *word, const int pos);

bool isPalindrome(const char *word);

void deleteWord(char *str, const char *word);

void deleteWordPos(char *str, const char *word, const int pos);

void insertWord(char *str, const char *currentWord, const char *insertWord);

void insertWordPos(char *str, const char *insertWord, const int pos);

void swapWords(char *str, const char *word1, const char *word2, const char pos1, const char pos2);

void replaceWord(char *str, const char *replaceWord, char *insertWord);

char **divideStr(char *str, char *newStr, int &countWords, int &countNewStr);

void mergeWords(char *str, char **words, char *newStr, const int &countWords, const int &countNewStr);

void sortWords(char *str);

int compare(const void *a, const void *b);

void qsortWords(char *str);

char *searchNumber(char *str, const char *seps, char *nextStr);

bool isNumber(char *word);