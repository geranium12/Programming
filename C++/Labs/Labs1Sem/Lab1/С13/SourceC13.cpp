/*
	���������� ����. 7 ������.
	�������:
C13.0	���� ����������� ����� N. �������� N ����� ����������. ����� ���������� - ��� ����������� 
�����, ������� ����� ����� ����� ����, ����������� � �������, 
������ ���������� ��� ����.  
	�����:
		input	output
		1		1
		5		1 2 3 4 5
		10		1 2 3 4 5 6 7 8 9 153
		15		1 2 3 4 5 6 7 8 9 153 370 371 407 1634 8208
		20		1 2 3 4 5 6 7 8 9 153 370 371 407 1634 8208 9474 54748 92727 93084 548834
*/

#include <iostream>

using namespace std;

const int LENGTH = 50; //������������ ����� �����
int n; //���������� ����� ����������, ������� ����� �������
int chislo[LENGTH]; //������ � ������� �����

//����� ���������� ���� �����
int kolCifr(int x)
{
	int k = 0;
	while (x > 0) {
		x /= 10;
		k++;
	}
	return k;
}

//��������� ���� �����
void numbers(int x) 
{
	for (int i = 0; i < LENGTH; i++)
		chislo[i] = 0;
	int i = 0;
	while (x > 0) {
		chislo[i] = x % 10;
		x /= 10;
		i++;
	}
}

//������� ���������� ����� � �������
int degree(int x, int n) {
	int ans = 1;
	while (n > 0) {
		if (n % 2 != 0)
			ans *= x;
		n /= 2;
		x *= x;
	}
	return ans;
}

//��������: ����� ���������� ��� ���
bool armstrong(int x)
{
	numbers(x);
	int sum = 0;
	int k = kolCifr(x);
	for (int i = 0; i < k; i++)
		sum += degree(chislo[i], k);
	if (sum == x)
		return true;
	else 
		return false;

}

void main()
{
	setlocale(LC_ALL, ".1251");
	cout << "������� ����������� ����� N" << endl;
	cin >> n;
	int i = 1;
	int k = 0;
	while (k < n) {
		if (armstrong(i)) {
			cout << i << ' ';
			k++;
		}
		i++;
	}
	system("pause");
}