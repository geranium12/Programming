/*
	Герасимчик Анна. 1 курс. 7 группа.
	Условие:
	Вводится число в десятичной системе счисления. Перевернуть его двоичное представление 
	(все 32 бита) и вывести полученное число в десятичной системе счисления.
	Идея:
	Используя логическую операцию И, смотрим на последний бит числа (number). Если равен 
	1, то последний бит нашего нового числа (ans) устанавливаем равным 1, используя 
	операцию ИЛИ. Каждый раз сдвигаем ans на 1 бит влево и number на 1 бит вправо. Также 
	считаем, сколько раз number делится на 2 (count). Таким образом мы перевернули исходное 
	число, но надо перевернуть все 32 бита, которые были нулями в двоичном представлении 
	number. Значит, сдвигаем ans еще на (32 - count).
	Тесты:
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