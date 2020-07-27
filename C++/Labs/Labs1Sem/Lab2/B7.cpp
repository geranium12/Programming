/* 
	Герасимчик Анна. 1 курс. 7 группа
	Условие:
	В7.	Вычислить значение функции:  у =   при если  х изменяется от a до b с шагом h. Результаты получить в виде таблицы.
*/

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Изменяем x, учитывая период
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

// Синус по ряду Тейлора
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

// Косинус по ряду Тейлора
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
	cout << "Введите отрезок a, b, шаг h" << endl;
	cin >> a >> b >> h;
	cout << setprecision(10);
	
	cout << "x : Taylor : C++" << endl;
	for (double i = a; i <= b; i += h) {
		double x = transform(i);
		//Функция, которую нужно посчитать, используя ряды Тейлора
		double ans = ((sinus(x) / cosinus(x)) / sqrt(1 - sinus(x)));
		cout << i << " : " << ans << " : " << tan(x) / sqrt(1 - sin(x)) << endl;
	}
	system("pause");
	return 0;
}