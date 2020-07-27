#include "ClassMatrix.h"

using namespace std;

int main()
{
	int n = 5;
	int m = 5;
	int **mat1 = new int*[n];
	for (int i = 0; i < n; i++)
		mat1[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			mat1[i][j] = rand() % 2;
		}

	Matrix matr1(n, m, mat1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mat1[i][j] = rand() % 5;
	
	Matrix matr2(n, m, mat1);

	cout << "MATR1 = " << endl << matr1 << endl;
	cout << "MATR2 = " << endl << matr2 << endl;
	cout << "matr1 + matr2 = " << endl << matr1 + matr2 << endl;
	cout << "matr1 - matr2 = " << endl << matr1 - matr2 << endl;
	cout << "matr1 * matr2 = " << endl << matr1 * matr2 << endl;
	cout << "TRANSPOSE" << endl << matr1.transpose() << endl;
	system("pause");
	return 0;
}