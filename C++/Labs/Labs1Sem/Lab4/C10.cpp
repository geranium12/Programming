/*
	���������� ����. 1 ����. 7 ������.
	�������:
	C10. � ������ �������������� ���������� ������� ������� n ����� min �������. 
	�������� ����������  �������  ������� n+1 �����  ���������� � �������� 
	�����-���� ������ � �������, �� ����������� ������� ���������� ������� � 
	��������� ���������.
	����:
	������� ����������� ������� min �������, ��� ���� �������� ����� ������ minI
	� ������� minJ, � ������� ��������� min. ����� ��������� � ������� n + 1 ������ 
	minJ, � � ������ n + 1 ������ minI.
	�����:
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

	// ����
	int ord;
	cout << "������� ������� �������" << endl;
	cin >> ord;

	cout << "������� �������" << endl;
	double **mat = new double *[ord + 1];
	for (int i = 0; i < ord + 1; i++)
		mat[i] = new double[ord + 1];

	// ���� ������� � ���������� � ������������ ��������
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
	
	// ���������� minI ������ � minJ ������� � �������
	for (int i = 0; i < ord + 1; i++)
	{
		mat[i][ord] = mat[i][minJ];
		mat[ord][i] = mat[minI][i];
	}

	// �����
	cout << "���������� �������" << endl;
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