#include "StudContainer.h"
#include <algorithm>

StudContainer::StudContainer(int& _n)
{
	_size = _n;
	p = new Student[_size];
	_count = 0;
}

StudContainer::StudContainer(const StudContainer& c)
{
	_size = c._size;
	_count = c._count;
	p = new Student[_size];
	for (int i = 0; i < _size; i++)
	{
		strcpy(p[i].name, c.p[i].name);
		p[i].grade = c.p[i].grade;
		p[i].num = c.p[i].num;
	}
}

StudContainer::~StudContainer()
{
	delete[] p;
}

bool StudContainer::insert(const Student& s)
{
	//const char* str = "Not enough memory!";
	if (_count == _size)
		//throw bad_alloc();
		return false;
	strcpy(p[_count].name, s.name);
	p[_count].grade = s.grade;
	p[_count].num = s.num;
	_count++;
	return true;
}

bool StudContainer::del(char* name)
{
	if (!_count)
		return false;
	strcpy(p[_count - 1].name, "");
	p[_count].grade = 0;
	p[_count].num = 0;
	_count--;
}

int compName(const void* st1, const void* st2)
{
	Student a = *(Student*)st1;
	Student b = *(Student*)st2;
	return strcmp(a.name, b.name);
}

void StudContainer::sortByName()
{
	qsort(p, _count, sizeof(p[0]), compName);
}

Student* StudContainer::findByName(char* name)
{
	for (int i = 0; i < _count; i++)
	{
		if (!strcmp(p[i].name, name))
			return &p[i];
	}
	return nullptr;
}

int compGroupName(const void *st1, const void *st2)
{
	Student a = *(Student*)st1;
	Student b = *(Student*)st2;
	if (a.num < b.num)
		return -1;
	else if (a.num > b.num)
		return 1;
	else
		return strcmp(a.name, b.name);
}

void StudContainer::sortByGroupAndName()
{
	qsort(p, _count, sizeof(p[0]), compGroupName);
}

void StudContainer::report(ostream& out)
{
	int **groups = new int*[2];
	for (int i = 0; i < 3; i++)
	{
		groups[i] = new int[100];
		for (int j = 0; j < 100; j++)
			groups[i][j] = 0;
	}
	double *marks = new double[100];
	for (int i = 0; i < 100; i++)
		marks[i] = 0;

	int m = 0;
	for (int i = 0; i < _count; i++)
	{
		bool f = false;
		for (int j = 0; j < m; j++)
			if (groups[0][j] == p[i].num)
			{
				f = true;
				//groups[1][j] += p[i].grade;
				groups[1][j]++;
				marks[j] += p[i].grade;
			}
		if (!f)
		{
			groups[0][m] = p[i].num;
			//groups[1][m] = p[i].grade;
			marks[m] += p[i].grade;
			groups[1][m]++;
			m++;
		}
	}

	cout << "GROUP - AVERAGE MARK" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << groups[0][i] << " " << marks[i] / groups[1][i] << endl;
	}
}

void StudContainer::print(ostream& out)
{
	cout << "NAME " << "GROUP " << "GRADE" << endl;
	for (int i = 0; i < _count; i++)
	{
		cout << setw(4) << p[i].name << " " << p[i].num << " " << p[i].grade << endl;
	}
}

int StudContainer::size()
{
	return _size;
}

int StudContainer::count()
{
	return _count;
}