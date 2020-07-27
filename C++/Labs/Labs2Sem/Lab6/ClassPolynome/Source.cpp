#include "ClassPolynome.h"

using namespace std;

int main()
{
	int n1 = 1; // 3
	double *d = new double[n1 + 1];
	d[0] = 1; d[1] = 1;
	Polynome p1(n1, d);
	int n2 = 1;	// 2
	d[0] = 2; d[1] = 1;
	//d[0] = 1; d[1] = 2; d[2] = 0; d[3] = 1;
	//Polynome p1(n1, d);
	//d[0] = 2; d[1] = 1; d[2] = 1;
	Polynome p2(n2, d);
	cout << "POLYNOMES:" << endl;
	cout << "p1 =	" << p1 << endl;
	cout << "p2 =	" << p2 << endl;

	/*
	cout << "PLUS" << endl;
	cout << "p1 + p2 =	" << p1 + p2 << endl;
	Polynome p3 = p1;
	Polynome p4 = p2;
	p1 += p2;
	cout << "p1 += p2 = 	"<< p1 << endl;

	cout << "MINUS" << endl;
	cout << "p1 - p2 =	" << p4 - p3 << endl;
	p4 -= p3;
	cout << "p1 -= p2 =		" << p4 << endl;
	*/
	cout << "MUL" << endl;
	cout << "p1 * p2 = " << p1 * p2 << endl;
	p1 *= p2;
	cout << "p1 *= p2 " << p1 << endl;
	cout << -p1;
	system("pause");
	return 0;
}