#pragma once

struct Container1
{
	char name[50];
	int  AverageMark;

	/*
	friend istream& operator>>(istream& in, Container1& cont)
	{
		in >> cont.name >> cont.AverageMark;
		return in;
	}
	*/
	char* getName() { return name; }
	int getMark() { return AverageMark; }
	istream& operator>>(istream& in)
	{
		in >> name >> AverageMark;
		return in;
	}
};

struct Container2
{
	char name[50];
	char space[50];

	istream& operator>>(istream& in)
	{
		in >> name >> space;
		return in;
	}
};

struct Container3
{
	char name[50];
	int  AverageMark;
};
