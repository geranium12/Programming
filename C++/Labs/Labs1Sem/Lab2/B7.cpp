/* 
	���������� ����. 1 ����. 7 ������
	�������:
	�7.	��������� �������� �������:  � =   ��� ����  � ���������� �� a �� b � ����� h. ���������� �������� � ���� �������.
*/

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// �������� x, �������� ������
double transform(double x)
{
	double pi = 3.14;
	while ((x >= 2 * pi) || (x < 0))
	{
		if (x < 0)
			x = x + 2 * pi;
		else
			x = x - 2 * pi;
	}
	return x;
}

// ����� �� ���� �������
double sinus(double x)
{
	double e = 0.00001;

	double ans = x;
	double delta = x;
	int n = 1;

	while (fabs(delta) >= e)
	{
		delta = (-delta * x * x) / (2 * n * (2 * n + 1));
		ans += delta;
		n = n + 1;
	}
	return ans;	
}

// ������� �� ���� �������
double cosinus(double x)
{
	double e = 0.00001;

	double ans = 1;
	double delta = 1;
	int n = 1;

	while (fabs(delta) >= e)
	{
		delta = (-delta * x * x) / (n * (n + 1));
		ans += delta;
		n = n + 2;
	}
	return ans;
}

int main()
{
	double a, b, h;
	setlocale(LC_ALL, ".1251");
	cout << "������� ������� a, b, ��� h" << endl;
	cin >> a >> b >> h;
	cout << setprecision(10);
	
	cout << "x : Taylor : C++" << endl;
	for (double i = a; i <= b; i += h) {
		double x = transform(i);
		//�������, ������� ����� ���������, ��������� ���� �������
		double ans = ((sinus(x) / cosinus(x)) / sqrt(1 - sinus(x)));
		cout << i << " : " << ans << " : " << tan(x) / sqrt(1 - sin(x)) << endl;
	}
	system("pause");
	return 0;
}