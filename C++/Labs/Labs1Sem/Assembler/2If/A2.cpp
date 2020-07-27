//Герасимчик Анна. 1 курс. 7 группа

#include <iostream>

using namespace std;

int main()
{
	int chislo, ans = -1;
	setlocale(LC_ALL, ".1251");
	cout << "Предсказание прекрасных дней" << endl << "Введите число [1, 12]" << endl;
	cin >> chislo;
	//cin.good
	__asm {
		mov eax, chislo
		cmp chislo, 4
		jg next1
		//x * x + 2 * x
		mul eax
		add eax, chislo
		add eax, chislo
		jmp fin
		next1:	cmp chislo, 8
				jle next2
				//5 * x - 22
				mov ebx, 5
				mul ebx
				sub eax, 22
				jmp fin
				next2:	//x * x - 3 * x + 3
						mul eax
						sub eax, chislo
						sub eax, chislo
						sub eax, chislo
						add eax, 3
						jmp fin
						fin: mov ans, eax
	}
	cout << "Ваш замечательный день настанет через " << ans << " д"  << endl;
	system("pause");
	return 0;
}