/*
	���������� ����. 1 ����. 7 ������.
	�������:
	�12. ������ ����� �. ������ ��������� ���������� �����, �������������� � ������ ����� �, 
	��������������. ��������, 4241	->	442441
	����:
	� ������� digits ������ ����� �����. ������� ������������ ����� (max). ����� ���� �� ������� 
	� ������ ����� �����:
	1	���������� � ����� (ans) �����,
	2	�������� ans �� 10,
	3	���� ����� ����� ������������, �� ������ �������� 1 � 2 ��� ���� ���
	� ����� ����� ����� �� 10, �.�. ��� ���������� ����� �� ������ ��� �������� �� 10 � �����.
	�����:
	input		output
1	4241		442441
2	123456		1234566
3	1929934		1992999934
4	1			1
5	12			122
*/
#include <iostream>

using namespace std;

void output(int out)
{
	cout << out << endl;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	int number, trash, max = 0, d10 = 10, ans = 0;
	int digits[10] = { 0 };
	cout << "������� �����" << endl << "NOTE: ���� ������������ ����� ��������������, �� ��� ������ ���������� � int" << endl;
	cin >> number;
	__asm
	{
		mov eax, number
		xor esi, esi
		_while1 : cmp eax, 0
				  jle _exit1
				  xor edx, edx
				  div d10
				  mov digits[esi * 4], edx
				  inc esi
				  cmp max, edx
				  jg _while1
				  mov max, edx
				  jmp _while1
		_exit1:	xor eax, eax
		_while2:	dec esi
					cmp esi, 0
					jl _exit2
					add eax, digits[esi * 4]
					mul d10
					mov ebx, max
					cmp ebx, digits[esi * 4]
					jne _while2
					add eax, digits[esi * 4]
					mul d10
					
					jmp _while2
		_exit2:		div d10
					mov ans, eax
	}
	cout << ans << endl;
	system("pause");
	return 0;
}