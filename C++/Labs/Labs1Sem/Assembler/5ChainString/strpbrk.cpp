/*
	Герасимчик Анна. 1 курс. 7 группа.
	Условие:
	Написать свою реализацию функции strpbrk из библиотеки <cstring>.
	Идея:
	Идем по строке s1 и сравниваем элемент строки s1 с каждым
	элементом строки s2. Находим первое совпадение и выводим указатель
	на найденный в s1 знак. Выводим все совпадения элементов из строки
	s2 в s1.
	Тесты:
	input	output
1	12345	45
	45		5
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int STR_LENGTH = 105;

// Эта функция обнаруживает первое появление в строке, указанной s1 
//какого-либо знака из строки, указанной s2 (исключая завершающий знак NULL). 
//STRPBRK возвращает yказатель на найденный в s1 знак, или NULL-yказатель, 
//если знаков из s2 в s1 нет. 

char* STRPBRK(char *s1, char *s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int i = 0; int j = 0;
	char *c = NULL;
	while (i < len1)
	{
		j = 0;
		while (j < len2)
		{
			if (s2[j] == s1[i])
			{
				c = &s1[i];
				j = -1;
				break;
			}
			j++;
		}
		if (j == -1)
			break;
		i++;
	}
	return c;
}

char* STRPBRK_ASM(char *s1, char *s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int i = 0, j = 0;
	char *c = NULL;
	_asm
	{
		mov ebx, 0
		for1:	mov c, NULL
				cmp ebx, len1
				je exit1
				mov edi, s1
				mov al, [edi + ebx]
				inc ebx
				mov ecx, len2
				mov edi, s2
				repne scasb
				mov esi, s1
				dec ebx
				add esi, ebx
				inc ebx
				mov c, esi
				cmp ecx, 0
				jne exit1
				jmp for1
				exit1 :
	}
	return c;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	char *str1 = new char[STR_LENGTH];
	char *str2 = new char[STR_LENGTH];

	cout << "Enter the first string in which we will search symbols from the second string." << endl;
	fgets(str1, STR_LENGTH, stdin);
	cout << "Enter the second string from which we will search symbols in the first string." << endl;
	fgets(str2, STR_LENGTH, stdin);

	cout << "Mine implementation //  C++ Code:" << endl;
	int i = 1;
	char *c = strpbrk(str1, str2);
	while (c != NULL)
	{
		cout << i << '\t';
		cout << c << endl;
		c = strpbrk(c + 1, str2);
		i++;
	}
	cout << endl;

	cout << "Mine implementation // Assembly Code:" << endl;
	i = 1;
	c = STRPBRK_ASM(str1, str2);
	while (c != NULL)
	{
		cout << i << '\t';
		cout << c << endl;
		c = STRPBRK_ASM(c + 1, str2);
		i++;
	}
	cout << endl;
	system("pause");
}