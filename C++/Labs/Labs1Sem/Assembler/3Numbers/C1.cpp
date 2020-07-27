/*
	Герасимчик Анна. 1 курс. 7 группа.
	Условие:
	С1. Заданы три целых числа, которые задают некоторую дату. 
	Определить номер дня недели по заданной дате.
	Идея:
	Реализуем формулу Зеллера, которая обычно применяется в компьютерных программах 
	для нахождения дня недели.  
	Тесты:
	input		output
1	24 10 2018	Среда 3
2	15 3 1926	Понедельник 1
3	25 3 2089	Пятница 5
4	5 5 2046	Суббота 6
5	1 2 1900	Четверг 4
*/
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	int day, month, year;
	cout << "Введите дату через пробел (день / месяц / год)" << endl;
	cin >> day >> month >> year;
	int h, q, m, K, J;
	__asm 
	{
		mov eax, day
		mov q, eax
		mov eax, month
		cmp eax, 3
		jge next1_
		add eax, 12
		mov ebx, year
		dec ebx
		mov year, ebx
		next1_:	mov m, eax
				mov eax, year
				mov ebx, 100
				xor edx, edx
				div ebx
				mov K, edx
				mov J, eax
				mov ebx, q
				add ebx, K
				mov eax, J
				mov ecx, 5
				mul ecx
				add ebx, eax
				mov eax, K
				mov ecx, 4
				xor edx, edx
				div ecx
				add ebx, eax
				mov eax, J
				mov ecx, 4
				xor edx, edx
				div ecx
				add ebx, eax
				mov eax, m
				inc eax
				mov ecx, 13
				mul ecx
				mov ecx, 5
				xor edx, edx
				div ecx
				add ebx, eax
				mov eax, ebx
				mov ecx, 7
				xor edx, edx
				div ecx
				cmp edx, 2
				jge next2_
				add edx, 6
				jmp next3_
				next2_:	dec edx
				next3_:	mov h, edx
	}
	switch (h)
	{
	case 1: {
		cout << "Понедельник ";
		break;
	}
	case 2: {
		cout << "Вторник ";
		break;
	}
	case 3: {
		cout << "Среда ";
		break;
	}
	case 4: {
		cout << "Четверг ";
		break;
	}
	case 5: {
		cout << "Пятница ";
		break;
	}
	case 6: {
		cout << "Суббота ";
		break;
	}
	case 7: {
		cout << "Воскресенье ";
		break;
	}
	}
	cout << h << endl;
	system("pause");
	return 0;
}