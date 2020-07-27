/*
	Герасимчик Анна. 1 курс. 7 группа
	Условие:
	Задано выражение (инфиксная форма, например (5+45)*(55-5))
	содержащее числа (любого типа), знаки операций, круглые скобки.
	Записать его в виде обратной польской записи (постфиксная форма)
	и вычислить его значение.
	Идея:
	Используем структуру данных стек для перевода из инфиксной записи
	в постфиксную и для дальнейшего подсчета постфиксного выражения.
	Алгоритм очевиден и описан в файле с условием.
	Тесты:
	input		output
	input.txt	output.txt
*/
#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

 string StrToPostfix(string str)
{
	string ans = "";
	stack <char> st;
	char f = false;
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		switch (c)
		{
		case '(':
		{
			st.push(c);
			f = false;
			break;
		}
		case ')':
		{
			ans += ' ';
			while (st.top() != '(')
			{
				ans += st.top();
				//ans += ' ';
				st.pop();
			}
			st.pop();
			f = false;
			break;
		}
		case '+':	case '-':
		{
			if ((st.top()!= '*') || (st.top() != '/'))
			{
				st.push(c);
			}
			f = false;
			break;
		}
		case '*':	case '/':
		{
			st.push(c);
			f = false;
			break;
		}
		default: {
			if (!f)
			{
				ans += ' ';
			}
			ans += c;
			f = true;
		}
		}
	}
	while (!st.empty())
	{
		if (st.top() != '(')
		{
			ans += st.top();
		}
		st.pop();
	}
	return ans;
}

int PostfixToNumber(string str)
{
	stack <int> st;
	ofstream fout("output.txt");
	int i = 0;
	while (i < str.length())
	{
		int curNumber = 0;
		while (isdigit(str[i]))
		{
			curNumber *= 10;
			curNumber += (str[i] - 48);
			i++;
		}
		if (curNumber)
		{
			st.push(curNumber);
		}
		else
		{
			char c = str[i];
			int n1, n2;
			switch (c)
			{
			case '+':
			{
				n1 = st.top();
				st.pop();
				n2 = st.top();
				st.pop();
				st.push(n1 + n2);
				break;
			}
			case '-':
			{
				n1 = st.top();
				st.pop();
				n2 = st.top();
				st.pop();
				st.push(n2 - n1);
				break;
			}
			case '*':
			{
				n1 = st.top();
				st.pop();
				n2 = st.top();
				st.pop();
				st.push(n1 * n2);
				break;
			}
			case '/':
			{
				n1 = st.top();
				st.pop();
				n2 = st.top();
				st.pop();
				st.push(n2 / n1);
			}
			}
		}
		i++;
	}
	int n = st.top();
	st.pop();
	return n;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string str;
	getline(fin, str);
	str = StrToPostfix(str);
	int number = PostfixToNumber(str);
	fout << number << endl;
	return 0;
}