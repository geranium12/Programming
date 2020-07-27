/*
	Герасимчик Анна. 1 курс. 7 группа
	Условие:
	Рекурсивно перевернуть очередь, состоящую из целых чисел.
	Идея:
	Опишем свою собственную структуру "очередь". Прочитаем и загрузим в
	очередь целые числа из файла. Сначала извлекаем все элементы из 
	очереди, а затем вставляем обратно в уже пустую очередь. Выводим 
	полученный результат.
	Тесты:
	input		output
	input.txt	output.txt
*/
#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <stdio.h> 
#include "Queue.h"

using namespace std;

void reverse(Queue *q)
{
	if (isEmpty(q))
		return; 
	int data = front(q);
	pop(q);
	reverse(q);  
	push(q, data);
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	if (!fin.is_open())
	{
		cout << "Error opening file" << endl;
		system("pause");
		return 0;
	}
	int *a = new int[100];
	int count = 0;
	while (!fin.eof())
	{
		fin >> a[count];
		count++;
	}
	Queue *q = create();
	for (int i = 0; i < count; i++)
		push(q, a[i]);
	reverse(q);
	print(q, fout);
	return 0;
}