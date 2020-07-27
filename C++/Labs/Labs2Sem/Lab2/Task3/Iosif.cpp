/*
	���������� ����. 1 ����. 7 ������.
	�������:
		������ ������. ������ ���������� ����� N �������, �� ������� 
	������� ������, �  ���������  ������������  ��  ������� ������� 
	������� �� 2 �� N. ���������,  ������� � ����-��, ����� ���� �� 
	M. �������, �� ������� ����������� ����, ������� �� �����. ���� 
	������������ �� ���������� �������� � ��� �� ��� ���, ���� �� 
	��������� ���� �������.  ���������� ����� ����������� ��������,
	���� �������� M � ��, ��� ���� ��������� � ������� ��������. 
	��������� �������� � ���������  ����.
	����:
	������� ������ �� N ��������� (�� 1 �� N), ��� i ������� - i 
	�������. � ����� ����� �� ������, ����������� ��������� 
	������� � ������� ������� �� ���� ������� �� ��� ���, ���� � 
	������ �� ��������� 1 �������.
	�����:
	input	output
1	10 3	4
2	5 3		4
3	6 2		5
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <list>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");

	int n, m;
	cout << "Enter people amount" << endl;
	cin >> n;
	cout << "Number of person which must be killed" << endl;
	cin >> m;

	list <int> l;
	for (int i = 0; i < n; i++)
		l.push_back(i + 1);
	
	int pos = 0;
	int i = 0;
	while (n > 1)
	{
		//list<int>::iterator it = l.begin();
		//for (it = l.begin(); it != l.end(); it++)
		//	cout << *it << " ";
		i++;
		cout << i << '\t';
		pos = pos + m;
		pos = pos % n;
		cout << " pos = " << pos << '\n';
		if (pos == 0)
		{
			l.pop_back();
		}
		else
		{
			if (pos == 1)
			{
				l.pop_front();
			}
			else
			{
				list<int>::iterator it = l.begin();
				for (int j = 0; j < pos - 1; j++)
					it++;
				l.erase(it);
			}
		}
		n--;
		if (pos)
			pos--;
	}
	cout << "Answer = " << l.front() << endl;

	system("pause");
	return 0;
}
