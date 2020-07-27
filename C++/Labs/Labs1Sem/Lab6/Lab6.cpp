/*
	Герасимчик Анна. 1 курс. 7 группа
	Условие:
	1.	Задан текстовый файл, содержащий информацию о студентах в следующем виде :
	ФИО пробел ГРУППА пробел НОМЕР ЗАЧЕТКИ Оценка МАН  пробел Оценка ГЕО  пробел Оценка ПРОГ
	Например
	Иванов 4  456345   5 3 4.
	Петров  4  456348   4 3 4.
	Иванова  5 456340   5 3 5
	Петрова  5 456349   4 5 4
	Составить программу получения:
	•	среднего балла каждого студента
	•	общего среднего балла
	•	общего списка, состоящего из фамилии, номера группы, номера зачетки, среднего балла.
	•	списка отличников, состоящего из фамилии, номера группы, номера зачетки
	•	списка имеющих неудовлетворительные  оценки, состоящего из фамилии, номера группы, номера зачетки
	•	Для проверки результатов информацию созданных списков вывести на экран.
	Все  полученные списки записать  текстовые файлы OutОll.txt, OutО.txt, OutN.txt,  и в бинарные файлы OutОll.bin, OutО.bin OutN.bin, упорядочив списки по группам, каждую группу по фамилиям  в алфавитном порядке (используя  свою  и стандартную процедуры сортировки)  и вывести на экран.
	Из бинарных файлов  информацию переписать в текстовые файлы OutОll.txt, OutО.txt, OutN.txt.
	Общий средний балл записать первой строкой в файл OutОll.txt.
	Идея:
	Создадим структуру для считывания всех студентов из файла.
	Опишем все заданные функции.
	Создадим отдельные структуры для общего списка и для отличившихся студентов.
	Создадим 2 массива отличившихся студентов для отличников и для имеющих неудовлетворительные оценки.
	Отсортируем стандартной сортировкой и отсортируем своей ("пузырьком").
	Выведем все полученные отсортированные результаты в заданные файлы и в консоль.
	Тесты:
	input			output
	input.txt		outOll.txt	outO.txt	outN.txt
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

const int STUDENTS_NUM = 100;
const int STR_SIZE = 80;

struct mark
{
	int math;
	int geo;
	int prog;
	double average;
};

struct student
{
	char *name;
	int group;
	int number;
	mark marks;
};

struct studentSelection
{
	char *name;
	int group;
	int number;
	double average;
};

struct diffStudent
{
	char *name;
	int group;
	int number;
};

double averagePersonMark(student person)
{
	return (person.marks.math + person.marks.geo + person.marks.prog) / 3.;
}

double averageStudentsMark(student *pupil, const int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += pupil[i].marks.average;
	sum /= n;
	return sum;
}

studentSelection *studList(student *pupil, const int n)
{
	studentSelection *list = new studentSelection[n];
	for (int i = 0; i < n; i++)
	{
		list[i].name = pupil[i].name;
		list[i].group = pupil[i].group;
		list[i].number = pupil[i].number;
		list[i].average = pupil[i].marks.average;
	}
	return list;
}

diffStudent *excStudList(student *pupil, const int n, int &count)
{
	diffStudent *list = new diffStudent[n];
	count = 0;
	for (int i = 0; i < n; i++)
	{
		if (pupil[i].marks.average == 5)
		{
			list[count].name = pupil[i].name;
			list[count].group = pupil[i].group;
			list[count].number = pupil[i].number;
			count++;
		}
	}
	return list;
}

diffStudent *loseStudList(student *pupil, const int n, int &count)
{
	diffStudent *list = new diffStudent[n];
	count = 0;
	for (int i = 0; i < n; i++)
	{
		if ((pupil[i].marks.geo < 3) || (pupil[i].marks.math < 3) || (pupil[i].marks.prog < 3))
		{
			list[count].name = pupil[i].name;
			list[count].group = pupil[i].group;
			list[count].number = pupil[i].number;
			count++;
		}
	}
	return list;
}

bool compareSelection(studentSelection stud1, studentSelection stud2)
{
	if (stud1.group > stud2.group)
	{
		return 0;
	}
	else
	{
		if (stud1.group < stud2.group)
		{
			return 1;
		}
		else
		{
			if (stud1.name < stud2.name)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}
}

bool compareDiff(diffStudent stud1, diffStudent stud2)
{
	if (stud1.group > stud2.group)
	{
		return 0;
	}
	else
	{
		if (stud1.group < stud2.group)
		{
			return 1;
		}
		else
		{
			if (stud1.name < stud2.name)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}
}

void sortSelection(studentSelection *students, const int count)
{
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count - i - 1; j++)
		{
			if ((students[j].group > students[j + 1].group) ||
				((students[j].group == students[j + 1].group) &&
				(students[j].name > students[j + 1].name)))
			{
				swap(students[j], students[j + 1]);
			}
		}
}

int main()
{
	setlocale(LC_ALL, ".1251");
	ifstream fin("input.txt");

	student *students = new student[STUDENTS_NUM];
	int n = 0;
	while (!fin.eof())
	{
		char *str = new char[STR_SIZE];
		fin >> str;
		students[n].name = str;
		int d;
		fin >> d;
		students[n].group = d;
		fin >> d;
		students[n].number = d;
		fin >> d;
		students[n].marks.math = d;
		fin >> d;
		students[n].marks.geo = d;
		fin >> d;
		students[n].marks.prog = d;
		n++;
	}
	fin.close();

	//	среднего балла каждого студента
	for (int i = 0; i < n; i++)
		students[i].marks.average = averagePersonMark(students[i]);

	//	общего среднего балла
	double commonAverageMark = averageStudentsMark(students, n);

	//	общего списка, состоящего из фамилии, номера группы, номера зачетки, среднего балла.
	studentSelection *studentsList = new studentSelection[n];
	studentsList = studList(students, n);

	//	списка отличников, состоящего из фамилии, номера группы, номера зачетки
	diffStudent *excellentStudents = new diffStudent[n];
	int countExc;
	excellentStudents = excStudList(students, n, countExc);

	//	списка имеющих неудовлетворительные  оценки, состоящего из фамилии, номера группы, номера зачетки
	int countLoser;
	diffStudent *loseStudents = new diffStudent[n];
	loseStudents = loseStudList(students, n, countLoser);

	// Сортировка полученных списков
	sortSelection(studentsList, n);

	sort(excellentStudents, excellentStudents + countExc, compareDiff);
	sort(loseStudents, loseStudents + countLoser, compareDiff);
	sort(studentsList, studentsList + n, compareSelection);

	// Вывод в текстовые файлы OutОll.txt, OutО.txt  и OutN.txt
	
	ofstream foutOLL("OutOLL.txt");
	ofstream foutO("OutO.txt");
	ofstream foutN("OutN.txt");

	foutOLL << "Common average mark: " << commonAverageMark << endl;
	for (int i = 0; i < n; i++)
		foutOLL << i + 1 << " " << studentsList[i].name << " " << studentsList[i].group << " "
		<< studentsList[i].number << " " << studentsList[i].average << endl;

	for (int i = 0; i < countExc; i++)
		foutO << i + 1 << " " << excellentStudents[i].name << " " << excellentStudents[i].group << " "
		<< excellentStudents[i].number << endl;

	for (int i = 0; i < countLoser; i++)
		foutN << i + 1 << " " << loseStudents[i].name << " " << loseStudents[i].group << " "
		<< loseStudents[i].number << endl;

	foutOLL.close();
	foutO.close();
	foutN.close();

	ofstream foutOLLBin("OutOLL.bin", ios::binary);
	ofstream foutOBin("OutO.bin", ios::binary);
	ofstream foutNBin("OutN.bin", ios::binary);

	const char *stroka = "Common average mark: ";
	foutOLLBin.write((const char*)&stroka, sizeof(stroka));
	foutOLLBin.write((char*)&commonAverageMark, sizeof(commonAverageMark));
	foutOLLBin.write((char *)studentsList, sizeof(studentSelection));
	foutOBin.write((char *)excellentStudents, sizeof(diffStudent));
	foutNBin.write((char *)loseStudents, sizeof(diffStudent));

	foutOLLBin.close();
	foutOBin.close();
	foutNBin.close();
	return 0;
}