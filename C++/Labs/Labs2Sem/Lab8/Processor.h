#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>

class Processor 
{
protected:
	double MHz;
public:
	Processor()
	{
		MHz = 0;
	}
	Processor(double _MHz)
	{
		MHz = _MHz;
	}
	// virtual Processor() = 0;
	//virtual int GetId() = 0 const;

	//virtual void SetXY(double a, double b)
	//virtual void Show(ostream&) = 0;
	virtual ~Processor() {}
};

class Computer : public Processor {
protected:
	Processor proc;
	char* model;
	double price;
public:
	Computer()
	{
		// proc();
		proc = 0;
		model = nullptr;
		price = 0;
	}
	Computer(Processor _proc, char* _model, double _price)
	{
		proc = _proc;
		strcpy(model, _model);
		price = _price;
	}
	//virtual void Show(ostream&);
	virtual ~Computer() : Processor() {
	}
};

class ComputerWithMonitor : public Computer
{
private:
	Computer comp;
	double screenSize;
public:
	ComputerWithMonitor()
	{

	}
	ComputerWithMonitor(Computer _comp, double _screenSize)
	{
		comp = _comp;
		screenSize = _screenSize;
	}
	~ComputerWithMonitor() : ~Computer() {}
};
