/*
	���������� ����. 1 ����. 7 ������
	�������:
	������� 2 - ����� ������.
	����������� ��������� ������ ��� ��������� ������� ������, ��������� ���������� � ������������. 
	�������� ���������  ��� ��������  ���������� �������� � �������� �������.  
*/
#include "Ratio.h"

using namespace std;

int main()
{
	Ratio r1(1, 2), r2(2, 3), r3(1, 3), r4(5, 4);
	Ratio ans;
	if ((r1 > r3) && (r2 != r3))
	{
		Ratio r = (r1 + r2) * r3; // 7 / 18
		r /= (r4 - 3); // -2 / 9
		ans = ++r; // 7 / 9
	}
	cout << ans;
	system("pause");
	return 0;
}