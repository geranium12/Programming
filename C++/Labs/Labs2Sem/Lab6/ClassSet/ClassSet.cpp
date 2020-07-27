#include "ClassSet.h"
#include "MyException.h"

int* renew(int*temp, int oldN, int newN)
{
	int* p = nullptr;
	try
	{
		p = new int[newN];
		for (int t = 0; t < oldN; ++t)
			p[t] = temp[t];
	}
	catch (exception)
	{
		delete(p);
		return nullptr;
	}
	return p;
}

Set::Set() : p(nullptr), size(0) {}

Set::Set(int* _p, int _size)
{
	size = _size;
	try
	{
		if (size <= 0)
			throw MyException("Can't create an array with this size!", "", 0, "Set::Set(int* _p, int _size)");
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = _p[i];
		sort();
	}
	catch (MyException& ex)
	{
		std::cout << ex.what() << ex.get_info() << std::endl;
		std::cout << "Function: " << ex.get_func() << std::endl;
	}
}

Set::Set(const Set& s)
{
	size = s.size;
	p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = s.p[i];
}

void Set::sort()
{
	for (int i = 0; i < size - 1; i++)
		for (int j = size - 1; j > i; j--)
		{
			if (p[j] < p[j - 1])
			{
				int temp = p[j];
				p[j] = p[j - 1];
				p[j - 1] = temp;
			}
		}
}


bool Set::include(int x)
{
	bool ans = false;
	for (int i = 0; i < size; i++)
	{
		if (p[i] == x)
		{
			ans = true;
			break;
		}
	}
	return ans;
}

Set operator + (const Set &s1, const int n)
{
	Set s;
	bool flag = true;
	for (int i = 0; i < s1.size; i++)
		if (s1.p[i] == n)
			flag = false;
	if (flag)
	{
		s.p = renew(s1.p, s1.size, s1.size + 1);
		s.size = s1.size + 1;
		s.p[s.size - 1] = n;
		s.sort();
	}
	else
	{
		s = s1;
	}
	return s;
}

Set operator - (const Set &s1, const int n)
{
	Set s;
	int x = -1;
	for (int i = 0; i < s1.size; i++)
		if (s1.p[i] == n)
			x = i;
	if (x != -1)
	{
		for (int i = 0; i < s1.size; i++)
			if (i != x)
				s = s + s1.p[i];
	}
	else
		s = s1;
	return s;
}

bool operator == (const Set&s1, const Set&s2)
{
	if (s1.size != s2.size)
		return false;
	for (int i = 0; i < s1.size; i++)
		if (s1.p[i] != s2.p[i])
			return false;
	return true;
}

bool operator != (const Set&s1, const Set&s2)
{
	return !(s1 == s2);
}

bool operator > (const Set&s2, const Set&s1)
{
	for (int i = 0; i < s1.size; i++)
	{
		bool flag = false;
		for (int j = 0; j < s2.size; j++)
		{
			if (s1.p[i] == s2.p[j])
				flag = true;
		}
		if (!flag)
			return false;
	}
	if (s1.size == s2.size) 
		return false;
	return true;
}

bool operator < (const Set&s1, const Set&s2)
{
	for (int i = 0; i < s1.size; i++)
	{
		bool flag = false;
		for (int j = 0; j < s2.size; j++)
		{
			if (s1.p[i] == s2.p[j])
				flag = true;
		}
		if (!flag)
			return false;
	}
	if (s1.size == s2.size)
		return false;
	return true;
}

bool operator >= (const Set& s2, const Set& s1)
{
	for (int i = 0; i < s1.size; i++)
	{
		bool flag = false;
		for (int j = 0; j < s2.size; ++j)
			if (s1.p[i] == s2.p[j])
				flag = true;
		if (!flag)
			return false;
	}
	return true;
}

bool operator <= (const Set&s1, const Set&s2)
{
	for (int i = 0; i < s1.size; i++)
	{
		bool flag = false;
		for (int j = 0; j < s2.size; j++)
		{
			if (s1.p[i] == s2.p[j])
				flag = true;
		}
		if (!flag)
			return false;
	}
	return true;
}

Set Set::operator * (const Set&s1)
{
	Set temp;
	for (int i = 0; i < size; i++)
	{
		bool flag = false;
		int j = 0;
		while (j < s1.size)
		{
			if (p[i] == s1.p[j])
				flag = true;
			j++;
		}
		if (flag)
			temp = temp + p[i];
	}
	return temp;
}

Set Set::operator + (const Set&s1)
{
	Set temp(s1);
	for (int i = 0; i < size; i++)
	{
		bool flag = false;
		for (int j = 0; j < s1.size; j++)
			if (p[i] == s1.p[j])
				flag = true;
		if (!flag)
			temp = temp + p[i];
	}
	return temp;
}
Set Set::operator - (const Set&s1)
{
	Set temp(s1);
	for (int i = 0; i < size; i++)
	{
		bool flag = false;
		for (int j = 0; j < s1.size; j++)
			if (p[i] == s1.p[j])
				flag = true;
		if (flag)
			temp = temp - p[i];
	}
	return temp;
}

Set& Set::operator += (const int n)
{
	*this = *this + n;
	return *this;
}

Set& Set::operator -= (const int n)
{
	*this = *this - n;
	return *this;
}

Set& Set::operator *= (const Set&s1)
{
	*this = *this * s1;
	return *this;
}

Set& Set::operator += (const Set&s1)
{
	*this = *this + s1;
	return *this;
}

Set& Set::operator -= (const Set&s1)
{
	*this = *this - s1;
	return *this;
}

ostream& operator << (ostream &out, const Set &s)
{
	for (int i = 0; i < s.size; i++)
	{
		out << setw(4) << s.p[i];
	}
	return out;
}

istream& operator >> (istream &in, Set &s)
{
	in >> s.size;
	s.p = new int[s.size];
	for (int i = 0; i < s.size; i++)
	{
		in >> s.p[i];
	}
	s.sort();
	return in;
}