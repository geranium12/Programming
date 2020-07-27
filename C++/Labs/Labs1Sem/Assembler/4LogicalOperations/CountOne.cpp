/*
	Герасимчик Анна Михайловна. 1 курс. 7 группа
	Условие:
	Сосчитать количество единиц в двоичной записи числа i, заданного в десятичной системе счисления.
	Идея:
	Будем сравнивать каждый бит числа с 1. Если бит равен 1, то увеличиваем счетчик на 1.
	Т. е. заведем переменную mask, равную 1. Логической операцией И будем сравнивать число 
	и маску. Если бит равен 1, то данная операция вернет значение 1, в противном случае 0.
	Если 1, то увеличиваем счетчик на 1. Сдвигаем 1 в маску влево на 1 бит, т. е. * 2. 
	Проделываем такой алгоритм действий с каждым битом.
	Тесты:
	input		output
1	1			1
2	348			5
3	45			4
4	54684321	11
5	64			1
*/
#include <iostream>

using namespace std;

// Код на С++ для проверки работы кода на ассемблере
/*int countOne(int number)
{
	int bit;
	int mask = 1;
	int count = 0;
	for (int i = 0; i < 32; i++)
	{     
		bit = mask & number;
		if (bit == mask) count++;
		mask = mask << 1;
	}
	return count;
}*/

int main()
{
	setlocale(LC_ALL, ".1251");

	int number;
	cout << "Введите число" << endl;
	cin >> number;
	int count; 
	//count = countOne(number);
	//cout << count << endl;
	int mask;
	__asm
	{
		mov ebx, number
		mov ecx, 31
		mov eax, 1
		xor edx, edx
		for1 : cmp ecx, 0
			   jl exit1
			   and ebx, eax
			   cmp ebx, eax
			   jne m1
			   inc edx
			   m1:	mov ebx, number
					shl eax, 1
					dec ecx
			   jmp for1
		exit1: mov count, edx
	}
	cout << count << endl;
	system("pause");
	return 0;
}