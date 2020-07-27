/*
����������� ���������� � ������, ���������� � ���, �������� � �����. ����� �������� ������� ��������� ��������� ������������ ��������� ��� ����������� �������� ��������� ��������:
1.	������������� ������ �� �������� ���������. ������� ��������������� ������ �� �������;
2.	����� � ������� ������ � �������� �� ��� �������. ������� �������� �������� � �������, ��������� ������ ����� ������� �� �������.
3.	������������� ������ �� �������, � ������ ����� ������ �� �������� ���������. ������� ��������������� ������ �� �������.
4.	������� �� ������� ����� � ������� ���� ��������� � ������ ������.
��� ���������� �������� ����������� ����, ������� ��������� �� ������� ����� ��������� ������� �������. 
����� �� ��������� ����������� �� ���������� ������������. ��� ���������� ������� � ������ ��������� ������ � ������� ������������ ����������� ������� ���������� � ������.
*/
#include "StudContainer.h"
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
	//setlocale(LC_ALL, ".1251");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	ifstream fin("input.txt");
	int n;
	fin >> n;
	StudContainer st(n);
	while (!fin.eof())
	{
		Student s;
		string str;
		fin.ignore();
		getline(fin, str);
		strcpy(s.name, str.c_str());
		int group;
		fin >> group;
		s.num = group;
		double grade;
		fin >> grade;
		s.grade = grade;
		st.insert(s);
	}
	
	cout << "Reading have finished." << endl;

	cout << "1.	������������� ������ �� �������� ���������. ������� ��������������� ������ �� �������;" << endl;
	cout << "2.	����� � ������� ������ � �������� �� ��� �������. ������� �������� �������� � �������, ��������� ������ ����� ������� �� �������." << endl;
	cout << "3.	������������� ������ �� �������, � ������ ����� ������ �� �������� ���������. ������� ��������������� ������ �� �������." << endl;
	cout << "4.	������� �� ������� ����� � ������� ���� ��������� � ������ ������." << endl;
	cout << "0. �����" << endl;

	int ans = 1;
	while (ans)
	{
		cin >> ans;
		switch (ans)
		{
		case 1:
		{
			st.sortByName();
			st.print(cout);
			break;
		}
		case 2:
		{
			cout << "������� ������� � ��� ��������" << endl;
			char * str = new char[200];
			cin.ignore();
			cin.getline(str, 200);
			if (st.findByName(str) == nullptr)
			{
				cout << "������� �� ������" << endl;
			}
			else
			{
				Student *s = st.findByName(str);
				s->print();
			}
			break;
		}
		case 3:
		{
			st.sortByGroupAndName();
			st.print(cout);
			break;
		}
		case 4:
		{
			st.report(cout);
			break;
		}
		}
	}
	system("pause");
	return 0;
}