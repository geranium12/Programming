/*
	���������� ����. 1 ���� 2 �������
	������: �������� ��������� � ��������� ��������� � ���� � ����.
		������� ������ �� �����.
		������������� ������ �� ������ �� ��������.
		��������� ���������� ����.
		��������� ���������� ����.
		����� ����� ������� �����.
		����� ����� �������� �����.
		����� �����-�����.
		����� �����-���������.
	�������: ��������� ����������� ������� ������ string ������� �������� �������.
	������:
input	2
		3
		4
		5
		6
		7
		8
		9
		0
output	Hello
		world!
		Hello
		world!
		���������� ���� 0
		���������� ���� 2
		����� ������� ����� world!
		����� �������� ����� Hello
		�����-����� This string does not contain the word-number.
		�����-��������� This string does not contain the word-number.
*/
#include "Library.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int number = 1;
	cout << "default string = Hello world!" << endl;
	cout << "default seps =  .,;:\t\n" << endl; 
	cout << "������� ����� ������" << endl;
	cout << "����:" << endl;
	cout << "1. ������ ������ � �����������" << endl;
	cout << "2. ������� ������ �� �����" << endl;
	cout << "3. ������������� ������ �� ������ �� ��������" << endl;
	cout << "4. ��������� ���������� ����" << endl;
	cout << "5. ��������� ���������� ����" << endl;
	cout << "6. ����� ����� ������� �����" << endl;
	cout << "7. ����� ����� �������� �����" << endl;
	cout << "8. ����� ����� - �����" << endl;
	cout << "9. ����� ����� - ���������" << endl;
	cout << "0. ����� �� ���������" << endl;

	string str = "Hello world!";
	string seps = " .,;:\t\n";
	int sizeStrArr;
	string *strArr = divideStringToWords(str, seps, sizeStrArr);

	while (number)
	{
		cin >> number;
		switch (number)
		{
		case 1:	cout << "������� ������" << endl;
				getline(cin, str);
				getline(cin, str);
				cout << "������� �����������" << endl;
				getline(cin, seps);
				break;
		case 2:	strArr = divideStringToWords(str, seps, sizeStrArr);
				outputStrArr(strArr, sizeStrArr);
				break;
		case 3:	sortWords(strArr, sizeStrArr);
				outputStrArr(strArr, sizeStrArr);
				break;
		case 4:	cout << "���������� ���� " << amountOfLetters(strArr) << endl;
				break;
		case 5: cout << "���������� ���� " << amountOfWords(sizeStrArr) << endl;
				break;
		case 6:	cout << "����� ������� ����� " << longWord(strArr, sizeStrArr) << endl;
				break;
		case 7:	cout << "����� �������� ����� " << shortWord(strArr, sizeStrArr) << endl;
				break;
		case 8: cout << "�����-����� " << searchNumber(strArr, sizeStrArr) << endl;
				break;
		case 9: cout << "�����-��������� " << searchPalindrome(strArr, sizeStrArr) << endl;
				break;
		}
	}
	return 0;
}