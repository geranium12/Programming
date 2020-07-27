#include <iostream>
#include <fstream> 

using namespace std;

/*
УABS_LIBФ.ƒл€ класса предусмотреть абстрактные виртуальные функции, члены класса :
1)	ввод из бинарного потока(файла) массива данных(функци€ ReadData)
2)	вывод в бинарный  поток(файл) массива данных(функци€ WriteData)
3)	вывод в текстовый  поток(файл) массива данных(функци€ PutData(ostream&))
4)	ѕолучение нового массива данных, содержащего данные только о тех студентах, которые есть в первом и нет во втором массиве(функци€ Difference(ABS_LIB&, ABS_LIB&)
*/

class ABS_LIB
{
public:
	virtual void ReadDataT(istream& in) = 0;
	virtual void WriteDataT(ostream& out) = 0;
	virtual void ReadDataB(istream& in) = 0;
	virtual void WriteDataB(ostream& out) = 0;
};

struct S1 
{
	char Name[50]; 
	double Price;
};

struct S2 
{
	char Name[50];
};

struct S3 
{
	char Name[50]; 
	char ControlDate[25]; 
	double Price;
};

class Stud3;

class Stud1 : public ABS_LIB 
{
	int count;	
	S1 *M;
public:
	/* нужные функции */
	Stud1()
	{
		count = 0;
		M = nullptr;
	}

	~Stud1() { delete[] M; }

	void ReadDataT(istream& in)
	{
		in.seekg(0, ios::end);
		count = in.tellg() / sizeof(Stud1);
		in.seekg(0, ios::beg);
		M = new S1[count];
		for (int i = 0; i < count; i++)
			in >> M[i].Name >> M[i].Price;
	}

	void WriteDataT(ostream& out)
	{
		for (int i = 0; i < count; i++)
			out << M[i].Name << " " << M[i].Price << endl;
	}

	void ReadDataB(istream& in)
	{
		//cout << in.tellg() << endl;
		in.seekg(0, ios::end);
		//cout << in.tellg() << endl << sizeof(Stud1) << endl;
		count = in.tellg() / sizeof(Stud1);
		cout << count << endl;
		in.seekg(0, ios::beg);
		M = new S1[count];
		for (int i = 0; i < count; i++)
			in.read((char*)(&M[i]), sizeof(Stud1));
	}

	void WriteDataB(ostream& out)
	{
		out.write((char*)M, count * sizeof(Stud1));
	}

	friend Stud3;
};

class Stud2 : public ABS_LIB 
{
	int count;
	S2 *M;
public:
	/* нужные функции */
	Stud2()
	{
		count = 0;
		M = nullptr;
	}
	~Stud2();
	void ReadDataT(istream& in);
	void WriteDataT(ostream& out);
	void ReadDataB(istream& in);
	void WriteDataB(ostream& out);
	friend Stud3;
};

class Stud3 : public ABS_LIB 
{
	int count;	
	S3 *M;
public:
	/* нужные функции */
	Stud3()
	{
		count = 0;
		M = nullptr;
	}
	~Stud3();
	void ReadDataT(istream& in);
	void WriteDataT(ostream& out);
	void ReadDataB(istream& in);
	void WriteDataB(ostream& out);
	void Difference(Stud1& s1, Stud2& s2);
	void sort();
};

int main()
{
	Stud1 M1; //Stud2 K1; Stud3 R;
	//ABS_LIB *A1, *A2, *A3, *A4;

	ifstream input1("input1.txt");
	M1.ReadDataT(input1);
	//fstream output1b("output1b.bin", ios::in | ios::out | ios::binary);
	ofstream output1b("output1b.txt", ios::out | ios::binary);
	M1.WriteDataB(output1b);
	output1b.close();

	Stud1 M2;
	ifstream input1b("output1b.txt", ios::in | ios::binary);
	M2.ReadDataB(input1b);
	ofstream output1("output1.txt");
	M2.WriteDataT(output1);

	/*
	fstream in1(УOb1.binФ, ios::in | ios::out);
	A1 = &M1; A1->ReadData(in1); A1->PutData(cout);

	fstream in2(УNob1.binФ, ios::in | ios::out);
	A2 = &K1; A2->ReadData(in2); A2->PutData(cout);
	fstream out1(УRes.binФ, ios::out);

	// алгоритм получени€ Ђразностиї массивов M1 и K1 в массиве R
	A3 = &R; A3->Difference(A1, A2);
	// сортировка
	ofstream out3(УStud.txtФ);
	A3->WriteData(out1);
	A3->PutData(cout);
	A3->PutData(out3);
	*/	
	system("pause");
	return 0;
}
