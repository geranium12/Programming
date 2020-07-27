/*
	Герасимчик Анна. 1 курс. 7 группа
	Условие:
	Анкета для опроса населения содержит две группы вопросов.
	Первая группа содержит сведения о респонденте:
	- возраст;
	- пол;
	- образование (начальное, среднее, высшее).
	Вторая группа содержит собственно вопрос анкеты, ответ на
	который может быть ДА или НЕТ.
	Программа должна обеспечивать:
	+ начальный ввод анкет и формирование из них линейного списка;
	+ ответы на следующие вопросы на основе анализа анкет:
		а). сколько мужчин старше 40 лет, имеющих только высшее
		образование, ответили ДА на вопрос анкеты;
		б). сколько женщин моложе 30 лет, имеющих только среднее
		образование, ответили НЕТ на вопрос анкеты;
		в). сколько мужчин моложе 25 лет, имеющих только начальное
		образование, ответили ДА на вопрос анкеты;
		г). вывод всех анкет и ответов на вопросы в консоль.

*/
#include <iostream>
#include <Windows.h>
#include <string>
#include "List.h"

using namespace std;

struct Respondents
{
	List age;
	List gender;
	List education;
	List smoke;
};

Respondents r;

void LINE()
{
	cout << "__________________________________________________________________" << endl;
}

void InputAnkets()
{
	LINE();
	cout << "Ввод анкет..." << endl;
	cout << "Введите количество респондентов " << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Респондент N" << i + 1 << endl;
		cout << "Возраст - ";
		int x;
		cin >> x;
		r.age.push_back(x);
		cout << "Пол (0 - мужской, 1 - женский) - ";
		cin >> x;
		r.gender.push_back(x);
		cout << "Полученное образование (0 - начальное, 1 - среднее, 2 - высшее) - ";
		cin >> x;
		r.education.push_back(x);
		cout << "Вопрос анкеты: Вы курите? (0 - нет, 1 - да) - ";
		cin >> x;
		r.smoke.push_back(x);
	}
	cout << "Ввод анкет завершен." << endl;
	LINE();
}

void OutputAnkets(Respondents &r)
{
	LINE();
	cout << "Вывод анкет..." << endl;
	int count = r.age.size();
	for (int i = 0; i < count; i++)
	{
		cout << "Респондент N" << i + 1 << endl;
		cout << "Возраст - " << r.age.peek(i) << endl;
		cout << "Пол (0 - мужской, 1 - женский) - " << r.gender.peek(i) << endl;
		cout << "Полученное образование (0 - начальное, 1 - среднее, 2 - высшее) - " << r.education.peek(i) << endl;
		cout << "Вы курите? (0 - нет, 1 - да) - " << r.smoke.peek(i) << endl;
	}
	cout << "Вывод анкет завершен." << endl;
	LINE();
}

// Сколько мужчин старше 40 лет, имеющих только высшее образование, ответили ДА на вопрос анкеты;
int ManGreater40UniYes(Respondents &r)
{
	int count = 0;
	int s = r.age.size();
	for (int i = 0; i < s; i++)
	{
		if (!(r.gender.peek(i)) && (r.age.peek(i) > 40) && (r.education.peek(i) == 2) && (r.smoke.peek(i)))
		{
			count++;
		}
	}
	return count;
}

// Сколько женщин моложе 30 лет, имеющих только среднее образование, ответили НЕТ на вопрос анкеты;
int WomanLess30MidNo(Respondents &r)
{
	int count = 0;
	int s = r.age.size();
	for (int i = 0; i < s; i++)
	{
		if ((r.gender.peek(i)) && (r.age.peek(i) < 30) && (r.education.peek(i) == 1) && (!r.smoke.peek(i)))
		{
			count++;
		}
	}
	return count;
}

// Сколько мужчин моложе 25 лет, имеющих только начальное образование, ответили ДА на вопрос анкеты;
int ManLess25PrimaryYes(Respondents &r)
{
	int count = 0;
	int s = r.age.size();
	for (int i = 0; i < s; i++)
	{
		if (!(r.gender.peek(i)) && (r.age.peek(i) < 25) && (r.education.peek(i) == 0) && (r.smoke.peek(i)))
		{
			count++;
		}
	}
	return count;
}
int main()
{
	//setlocale(LC_ALL, ".1251");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	InputAnkets();
	cout << "A) " << ManGreater40UniYes(r) << " мужчин старше 40 лет, имеющих только высшее образование, ответили ДА на вопрос анкеты." << endl;
	cout << "B) " << WomanLess30MidNo(r) << " женщин моложе 30 лет, имеющих только среднее образование, ответили НЕТ на вопрос анкеты." << endl;
	cout << "C) " << ManLess25PrimaryYes(r) << " мужчин моложе 25 лет, имеющих только начальное образование, ответили ДА на вопрос анкеты." << endl;
	OutputAnkets(r);
	system("pause");
	return 0;
}