/*
	���������� ����. 1 ����. 7 ������.
	�������:
	B17. ����� ��������� ���� Input.txt, ���������  �� ����. ������������� 
	����� ������� �������� ��������� ��������� ������ ����������. ����� � 
	������ ������  �����, ������� ���������� � ��������� ���� �  �����, 
	������� ���������� �� ��������. ����� ����, ������� ���������� � 
	��������� ���� �������� ���������� �������, ������� ���������� �� 
	�������� ����  � ���������.   ��������� ��������  � ����� ���� 
	Output.txt. ����������� �����  � ����������  ������� ��  �������� 
	���� ����, ������� ����� � ���������� �������, ����� �� ���������. 
	��������� ���������� �������� � ���� Out_sort.txt. 
	����:
	�����:
*/
#include <iostream>
#include <fstream>

using namespace std;

int SIZE_STR = 100;

int main()
{
	setlocale(LC_ALL, ".1251");
	ifstream fin("Input.txt");
	if (!fin.is_open())
	{
		cout << "Error opening file!" << endl;
		system("pause");
		return 1;
	}
	ofstream fout("Output.txt");
	while (!fin.eof())
	{		
		char *str = new char[SIZE_STR];
		fin.getline(str, SIZE_STR);
		fout << str;
	}
	fin.close();
	//ofstream fout("Output.txt");
	fout.close();
	//ofstream fout("Out_sort.txt");
	//fout.close();
	return 0;
}