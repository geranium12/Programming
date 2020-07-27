/*
	���������� ����. 1 ����. 7 ������
	�������:
	������ ��� ������ ��������� �������� ��� ������ ��������.
	������ ������ �������� �������� � �����������:
	- �������;
	- ���;
	- ����������� (���������, �������, ������).
	������ ������ �������� ���������� ������ ������, ����� ��
	������� ����� ���� �� ��� ���.
	��������� ������ ������������:
	+ ��������� ���� ����� � ������������ �� ��� ��������� ������;
	+ ������ �� ��������� ������� �� ������ ������� �����:
		�). ������� ������ ������ 40 ���, ������� ������ ������
		�����������, �������� �� �� ������ ������;
		�). ������� ������ ������ 30 ���, ������� ������ �������
		�����������, �������� ��� �� ������ ������;
		�). ������� ������ ������ 25 ���, ������� ������ ���������
		�����������, �������� �� �� ������ ������;
		�). ����� ���� ����� � ������� �� ������� � �������.

*/
#include <iostream>
#include <Windows.h>
#include <string>
#include "List.h"

using namespace std;

struct Respondents
{
	List age;
	List gender;
	List education;
	List smoke;
};

Respondents r;

void LINE()
{
	cout << "__________________________________________________________________" << endl;
}

void InputAnkets()
{
	LINE();
	cout << "���� �����..." << endl;
	cout << "������� ���������� ������������ " << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "���������� N" << i + 1 << endl;
		cout << "������� - ";
		int x;
		cin >> x;
		r.age.push_back(x);
		cout << "��� (0 - �������, 1 - �������) - ";
		cin >> x;
		r.gender.push_back(x);
		cout << "���������� ����������� (0 - ���������, 1 - �������, 2 - ������) - ";
		cin >> x;
		r.education.push_back(x);
		cout << "������ ������: �� ������? (0 - ���, 1 - ��) - ";
		cin >> x;
		r.smoke.push_back(x);
	}
	cout << "���� ����� ��������." << endl;
	LINE();
}

void OutputAnkets(Respondents &r)
{
	LINE();
	cout << "����� �����..." << endl;
	int count = r.age.size();
	for (int i = 0; i < count; i++)
	{
		cout << "���������� N" << i + 1 << endl;
		cout << "������� - " << r.age.peek(i) << endl;
		cout << "��� (0 - �������, 1 - �������) - " << r.gender.peek(i) << endl;
		cout << "���������� ����������� (0 - ���������, 1 - �������, 2 - ������) - " << r.education.peek(i) << endl;
		cout << "�� ������? (0 - ���, 1 - ��) - " << r.smoke.peek(i) << endl;
	}
	cout << "����� ����� ��������." << endl;
	LINE();
}

// ������� ������ ������ 40 ���, ������� ������ ������ �����������, �������� �� �� ������ ������;
int ManGreater40UniYes(Respondents &r)
{
	int count = 0;
	int s = r.age.size();
	for (int i = 0; i < s; i++)
	{
		if (!(r.gender.peek(i)) && (r.age.peek(i) > 40) && (r.education.peek(i) == 2) && (r.smoke.peek(i)))
		{
			count++;
		}
	}
	return count;
}

// ������� ������ ������ 30 ���, ������� ������ ������� �����������, �������� ��� �� ������ ������;
int WomanLess30MidNo(Respondents &r)
{
	int count = 0;
	int s = r.age.size();
	for (int i = 0; i < s; i++)
	{
		if ((r.gender.peek(i)) && (r.age.peek(i) < 30) && (r.education.peek(i) == 1) && (!r.smoke.peek(i)))
		{
			count++;
		}
	}
	return count;
}

// ������� ������ ������ 25 ���, ������� ������ ��������� �����������, �������� �� �� ������ ������;
int ManLess25PrimaryYes(Respondents &r)
{
	int count = 0;
	int s = r.age.size();
	for (int i = 0; i < s; i++)
	{
		if (!(r.gender.peek(i)) && (r.age.peek(i) < 25) && (r.education.peek(i) == 0) && (r.smoke.peek(i)))
		{
			count++;
		}
	}
	return count;
}
int main()
{
	//setlocale(LC_ALL, ".1251");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	InputAnkets();
	cout << "A) " << ManGreater40UniYes(r) << " ������ ������ 40 ���, ������� ������ ������ �����������, �������� �� �� ������ ������." << endl;
	cout << "B) " << WomanLess30MidNo(r) << " ������ ������ 30 ���, ������� ������ ������� �����������, �������� ��� �� ������ ������." << endl;
	cout << "C) " << ManLess25PrimaryYes(r) << " ������ ������ 25 ���, ������� ������ ��������� �����������, �������� �� �� ������ ������." << endl;
	OutputAnkets(r);
	system("pause");
	return 0;
}