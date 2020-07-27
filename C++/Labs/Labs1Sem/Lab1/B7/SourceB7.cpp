/*
	���������� ����. 7 ������.
	�������:
B7.0 ���������� N ����������� ����� (����������� ���������� �����, 
����������� � �������� ������� ������ ��������). ( ����. 25,625).
�����:
	input	output
	1	-	1
	5	-	1 1
			5 25
			6 36
			25 625
			76 5776
	7	-	1 1
			5 25
			6 36
			25 625
			76 5776
			376 141376
			625 390625

*/

using namespace std;

#include <iostream>

//�������, ������� ���������� ����������� ����� ��� ���
int Automorph(long long x) {
	long long y = x * x;
	int k = 0;
	int d1 = 0, d2 = 0;

	while (y > 0 && x > 0) {
		if (y % 10 == x % 10) k++;
		else break;
		x /= 10;
		d1++;
		y /= 10;
		d2++;
	}

	if (k == d1 || k == d2) return(true);
	else return(false);
}
void main() {
	int n;
	setlocale(LC_ALL, ".1251");
	cout << "������� ����������" << endl;
	cin >> n;
	long long i = 1;
	int k = 0;
	while (k < n) {
		if (Automorph(i)) {
			cout << i << " " << i * i << endl;
			k++;
		}
		i++;
	}
	system("pause");
}