/*
	���������� ����. 1 ����. 7 ������
	�������:
	������ ��������� (��������� �����, �������� (5+45)*(55-5))  
	���������� ����� (������ ����), ����� ��������, ������� ������. 
	�������� ��� � ���� �������� �������� ������ (����������� �����) 
	� ��������� ��� ��������.
	����:
	���������� ��������� ������ ���� ��� �������� �� ��������� ������
	� ����������� � ��� ����������� �������� ������������ ���������.
	�������� �������� � ������ � ����� � ��������.
	�����:
	input		output
	input.txt	output.txt
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Library.h"

using namespace std;

extern const char STR_SIZE;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	if (!fin.is_open())
	{
		cout << "Error opening file" << endl;
		system("pause");
	}
	else
	{
		while (!fin.eof())
		{
			char *str = new char[STR_SIZE];
			fin.getline(str, STR_SIZE);
			fout << str << " = ";
			str = toPostfix(str);
			int ans = calculate(str);
			fout << ans;
		}
	}
	return 0;
}