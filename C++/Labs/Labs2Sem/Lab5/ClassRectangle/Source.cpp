/*
	���������� ����. 1 ����. 7 ������
	�������:
	������� 3 - ����� ������������� �������.
	������ �������� +,- �������� : &, | .
	�������� ~ -��������� ������������ ������ ���������. 
	�������� ++ ��������� � ����������� ������� ��� �������������, 
	����� ����� ������� �������� =1,  (�� �������� ����. �--� ).
	�������� *N ��������� �������. ������� � N ���. �������� /N - ��������� �������. ������� � N ���.
*/
#include "Rectangle.h"

using namespace std;

int main()
{
	Rectangle r1(3, 4, 5, 2), r2(2, 3, 6, 1);
	cout << "Union | " << (r1 | r2) << endl;
	cout << "Intersection & " << (r1 & r2) << endl;
	cout << "r1.square > r2.square ? " << (r1 < r2) << endl;
	cout << "r1++ " << r1++ << endl;
	cout << "--r2" << --r2 << endl;
	system("pause");
	return 0;
}