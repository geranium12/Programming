/*
	Герасимчик Анна. 1 курс. 7 группа.
	Условие:
	С12. Задано число А. Каждое вхождение наибольшей цифры, использованной в записи числа А, 
	продублировать. Например, 4241	->	442441
	Идея:
	В массиве digits храним цифры числа. Находим максимальную цифру (max). Далее идем по массиву 
	и строим новое число:
	1	прибавляем к числу (ans) цифру,
	2	умножаем ans на 10,
	3	если цифра равна максимальной, то делаем действия 1 и 2 еще один раз
	В конце делим число на 10, т.к. при построении числа мы лишний раз умножили на 10 в цикле.
	Тесты:
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
	cout << "Введите число" << endl << "NOTE: Если максимальную цифру продублировать, то оно должно помещаться в int" << endl;
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