/*
	Герасимчик Анна. 1 курс. 7 группа.
	Условие:
	C10. В данной действительной квадратной матрице порядка n найти min элемент. 
	Получить квадратную  матрицу  порядка n+1 путем  добавления к исходной 
	какой-либо строки и столбца, на пересечении которых расположен элемент с 
	найденным значением.
	Идея:
	Находим минимальный элемент min матрицы, при этом сохраняя номер строки minI
	и столбца minJ, в которых находится min. Далее вставляем в столбец n + 1 стобец 
	minJ, а в строку n + 1 строку minI.
	Тесты:
	input	output
1	1				1 1
	1				1 1
2	2				1 2 1
	1 2				3 4 3
	3 4				1 2 1
3	3				9 8 7 7
	9 8 7			6 5 4 4
	6 5 4			3 2 1 1
	3 2 1			3 2 1 1
4	4				15 20 18 5 18
	15 20 18 5		17 18 2 8 2
	17 18 2 8		2 4 20 8 20
	2 4 20 8		3 19 27 4 27
	3 19 27 4		17 18 2 8 2
5	5				1 2 3 4 5 1
	1 2 3 4 5		5 4 3 2 1 5
	5 4 3 2 1		1 2 3 4 5 1
	1 2 3 4 5		5 4 3 2 1 5
	5 4 3 2 1		1 2 3 4 5 1
	1 2 3 4 5		1 2 3 4 5 1
*/
#include <iostream>

using namespace std;

int MAX_INT = 2147483647;

int main()
{
	setlocale(LC_ALL, ".1251");

	// Ввод
	int ord;
	cout << "Введите порядок матрицы" << endl;
	cin >> ord;

	cout << "Введите матрицу" << endl;
	double **mat = new double *[ord + 1];
	for (int i = 0; i < ord + 1; i++)
		mat[i] = new double[ord + 1];

	// Ввод матрицы и нахождение её минимального элемента
	double min = MAX_INT;
	int minI, minJ;
	for (int i = 0; i < ord; i++)
		for (int j = 0; j < ord; j++)
		{
			cin >> mat[i][j];
			if (mat[i][j] < min)
			{
				min = mat[i][j];
				minI = i;
				minJ = j;
			}
		}
	
	// Добавление minI строки и minJ столбца в матрицу
	for (int i = 0; i < ord + 1; i++)
	{
		mat[i][ord] = mat[i][minJ];
		mat[ord][i] = mat[minI][i];
	}

	// Вывод
	cout << "Полученная матрица" << endl;
	for (int i = 0; i < ord + 1; i++)
	{
		for (int j = 0; j < ord + 1; j++)
			cout << mat[i][j] << " ";
	cout << endl;
	}
	
	for (int i = 0; i < ord + 1; i++)
		delete mat[i];
	delete[]mat;

	system("pause");
	return 0;
}