/*
	���������� ����. 1 ����. 7 ������.
	�������: 26 ������
*/

#include <iostream>

using namespace std;

void main()
{
	int x, y;
	setlocale(LC_ALL, ".1251");
	cout << "������� x � y" << endl;
	cin >> x >> y;
	int sinxy = int(sin(x + y) * 100);
	int ch1, znam1;
	int div1;
	int ans;
	// 26 ������ �� ����������
	__asm {
		// 2 * x
		mov eax, 2
		imul x
		mov ch1, eax
		// 1 + x * x * y * y
		mov eax, x
		mul x
		mul y
		mul y
		add eax, 1
		mov znam1, eax
		// (2 * x) / (1 + x * x * y * y)
		mov eax, ch1
		cdq
		idiv znam1
		mov div1, eax
		//x - (2 * x) / (1 + x * x * y * y)
		mov eax, x
		sub eax, div1
		mov div1, eax
		//fabs(x - (2 * x) / (1 + x * x * y * y))
		test eax, eax
		jns if2
		neg eax
		if2: mov div1, eax
		// 2 + fabs(x - (2 * x) / (1 + x * x * y * y))
		add eax, 2
		mov znam1, eax
		// sinxy * sinxy + 1
		mov eax, sinxy
		imul eax
		add eax, 1
		mov ch1, eax
		// (sinxy * sinxy + 1) / (2 + fabs(x - (2 * x) / (1 + x * x * y * y))) + x
		idiv znam1
		add eax, x
		mov ans, eax
	}
	/*
		26 ������ �� �++
	double ch = sinxy * sinxy + 1;
	double znam = 2 + fabs(x - (2 * x / (1 + x * x * y * y)));
	double res = ch / znam + x;
	cout << ch << " " << znam1 << " " << res << endl;
	*/
	cout << ans << endl;
	system("pause");
}
