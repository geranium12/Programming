#include <iostream>

using namespace std;

int  _cdecl sub1(int a, int b)
{
	return a - b;
}

int main()
{
	int a, b, c;
	cout << "Enter 2 number";
	cin >> a >> b;
	_asm
	{  push b
		push a
		call sub1
		pop edx
		pop edx
		mov c, eax
		push eax
		call print
		pop edx
	}
	c = sub1(a, b);
	cout << "n=" << c);
	return 0;
}
