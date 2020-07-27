/*
	Герасимчик Анна. 7 группа.
	Условие:
В8.0	Найти N пар взаимно-простых натуральных чисел.
Тесты:
	input	output
	1	-	1 1
	5	-	1 1
			2 1
			3 1
			3 2
			4 1
			4 3
	20	-	1 1
			2 1
			3 1
			3 2
			4 1
			4 3
			5 1
			5 2
			5 3
			5 4
			6 1
			6 5
			7 1
			7 2
			7 3
			7 4
			7 5
			7 6
			8 1
			8 3
			8 5
			8 7
*/

using namespace std;

#include <iostream>


// Находим НОД двух чисел
int Nod(int x, int y) {
	while (x > 0 && y > 0) {
		if (x > y) 
			x -= y;
		else 
			y -= x;
	}

	if (x > y) 
		return x;
	else 
		return y;
}
void main() {
	int n;
	setlocale(LC_ALL, ".1251");
	cout << "Введите количество" << endl;
	cin >> n;

	int k = 0;
	int i = 1, j = 1;
	while (k < n) {
		for (int j = 1; j <= i; j++)
			if (Nod(i, j) == 1) {
				cout << i << " " << j << endl;
				k++;
			}
		i++;
	}

	system("pause");
}