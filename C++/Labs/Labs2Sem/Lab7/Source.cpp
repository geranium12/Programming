#include "ClassTContainer.h"
#include "StudContainer.h"
#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;

using namespace std;

//template <class T>
/*
CONTAINER <Container3> intersection(CONTAINER <Container1> cont1, CONTAINER <Container2> cont2)
{
	Container3 *temp = new Container3[MAX_SIZE];
	//Container3 *temp = new Container3(MAX_SIZE);

	int count = 0;
	for (int i = 0; i < cont1.getCount(); i++)
	{
		for (int j = 0; j < cont2.getCount(); j++)
		{
		
			if (!strcmp(cont1[i], cont2[j].getName()))
			{
				if (cont1[i].getMark() > 8)
					strcpy(temp[count++].name, cont1[i].getName());
			}
		
		}
	}
	CONTAINER <Container3> res(temp, count);
	return res;
}

CONTAINER <Container2> findActive(CONTAINER <Container2> cont, const char * str)
{
	Container2 *temp = new Container2[MAX_SIZE];
	int count = 0;
	for (int i = 0; i < cont.getCount(); i++)
	{
		
		if (!strcmp(cont[i].getSpace(), str))
			{
				strcpy(temp[count++].name, cont[i].getSpace());
			}
			
	}
	CONTAINER <Container2> res(temp, count);
	return res;
}

void mySort(CONTAINER <Container1> & cont)
{
	for (int i = 0; i < cont.getCount(); i++)
	{
		for (int j = 0; j < cont.getCount() - i; j++)
		{
			if (cont[i] < cont[j])
			{
				Container1 temp = cont[i];
				cont[i] = cont[j];
				cont[j] = temp;
			}
		}
	}
}
*/

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	CONTAINER <Container1> cont1;
	//fin >> cont1;

	//CONTAINER <Container2> cont2;
	//fin >> cont2;

	/*
	CONTAINER <Container3> cont3 = intersection(cont1, cont2); // или Container1 st или Container2 st
	fout << cont3;
	CONTAINER <Container2> cont22 = findActive(cont2, "Sport");
	fout << cont22;
	mySort(cont1);
	fout << cont1;
	*/
	//R.function1Varianta(K,M); //Функция внутри класса-шаблона
	//	function2Varianta( Х  , st); //функция-шаблон, первый параметр согласно индивидуальному варианту
	//	X.Sortfunction3();//какой контейнер X (М, К, R)  - указано в индивидуальном варианте
	//system("pause");
	return 0;
}