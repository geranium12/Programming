/*
	���������� ����. 1 ����. 7 ������.
	�������:
	�������� ����� � ���������� ������� ���������. ����������� ��� �������� ������������� 
	(��� 32 ����) � ������� ���������� ����� � ���������� ������� ���������.
	����:
	��������� ���������� �������� �, ������� �� ��������� ��� ����� (number). ���� ����� 
	1, �� ��������� ��� ������ ������ ����� (ans) ������������� ������ 1, ��������� 
	�������� ���. ������ ��� �������� ans �� 1 ��� ����� � number �� 1 ��� ������. ����� 
	�������, ������� ��� number ������� �� 2 (count). ����� ������� �� ����������� �������� 
	�����, �� ���� ����������� ��� 32 ����, ������� ���� ������ � �������� ������������� 
	number. ������, �������� ans ��� �� (32 - count).
	�����:
	input	output
1	1				-2147483648
2	2				1073741824
3	3				-1073741824
4	100				637534208
5	4				536870912
*/
#include <iostream>

using namespace std;

int main()
{
	int number;
	cin >> number;

	int number1 = number;
	int one = 1;
	int bit;
	int ans = 0;
	int count = 0;

	// C++
	while (number)
	{
		bit = number & one;
		if (bit == 1)
			ans = ans | one;
		ans = ans << 1;
		number = number >> 1;
		count++;
	}
	ans = ans >> 1;
	ans = ans << (32 - count);
	cout << "C++ : " << ans << endl;	

	// Assembler
	number = number1;
	__asm
	{
		mov eax, number
		xor ebx, ebx
		xor ecx, ecx
		while1:	cmp eax, 0
				je exit1
				mov edx, eax
				and edx, 1
				cmp edx, 1
				jne m1
				or ebx, 1
				m1:	shl ebx, 1
					shr eax, 1
					inc ecx
					jmp while1
		exit1:	shr ebx, 1
				mov eax, 32
				sub eax, ecx
				mov ecx, eax
				for1:	shl ebx, 1
						loop for1
				mov ans, ebx
	}
	cout << "ASM : " << ans << endl;
	system("pause");
	return 0;
}