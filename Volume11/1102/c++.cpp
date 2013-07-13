#include <iostream>
#include <cstdio>
#include <algorithm>
#include <complex>
#include <sstream>
using namespace std;

struct comp
{
	complex<int> val;
	bool overflow;
	comp() : val(0), overflow(false) {}
	comp(complex<int> val) : val(val), overflow(false) {}
	comp(int r, int i) : val(r, i), overflow(false) {}
	comp(bool overflow) : overflow(overflow) {}

	bool isoverflow() { return abs(real())> 10000 || abs(imag()) > 10000; }
	int real() const { return val.real(); }
	int imag() const { return val.imag(); }
	friend comp operator+(comp a, comp b)
	{
		return a.overflow || b.overflow || comp(a.val + b.val).isoverflow() ? comp(true) : comp(a.val+b.val);
	}
	friend comp operator-(comp a, comp b)
	{
		return a.overflow || b.overflow || comp(a.val - b.val).isoverflow() ? comp(true) : comp(a.val-b.val);
	}
	friend comp operator*(comp a, comp b)
	{
		return a.overflow || b.overflow || comp(a.val * b.val).isoverflow() ? comp(true) : comp(a.val*b.val);
	}
	friend ostream& operator<<(ostream& os, const comp& a)
	{
		if(a.overflow) os << "overflow";
		else if(a.real() == 0 && a.imag() == 0) os << "0";
		//else if(a.real() == 0 && a.imag() == 1) os << "i";
		//else if(a.real() == 0 && a.imag() == -1) os << "-i";
		else if(a.real() == 0) os << a.imag() << "i";
		else if(a.imag() == 0) os << a.real();
		//else if(a.imag() == 1) os << a.real() << "+i";
		//else if(a.imag() == -1) os << a.real() << "-i";
		else if(a.imag() > 0) os << a.real() << "+" << a.imag() << "i";
		else if(a.imag() < 0) os << a.real() << a.imag() << "i";
		else os << "invalid";
		return os;
	}
};

comp parse_add(string);

comp parse_val(string str)
{
	if(str[0] == '(') return parse_add(str.substr(1, str.length()-2));
	if(str[0] == '+') return parse_val(str.substr(1));
	if(str[0] == '-') return comp() - parse_val(str.substr(1));
	if(str[0] == 'i') return comp(0, 1);
	return comp(atoi(str.c_str()), 0);
}

comp parse_mlt(string str)
{
	comp ret(1, 0);
	int nest = 0;
	int prev = 0;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == '(') nest++;
		else if(str[i] == ')') nest--;
		else if(str[i] == '*' && nest == 0 && i-prev > 0)
		{
			ret = ret * parse_val(str.substr(prev, i-prev));
			prev = i + 1;
		}
		if(i == str.length() - 1)
		{
			ret = ret * parse_val(str.substr(prev));
		}
	}
	//cout << "*" << str << ":" << ret << endl;
	return ret;
}

comp parse_add(string str)
{
	comp ret;
	int nest = 0;
	int prev = 0;
	bool add = true;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == '(') nest++;
		else if(str[i] == ')') nest--;
		else if((str[i] == '+' || str[i] == '-') && nest == 0 && i-prev > 0)
		{
			ret = add ? ret + parse_mlt(str.substr(prev, i-prev)) : ret - parse_mlt(str.substr(prev, i-prev));
			prev = i + 1;
			add = str[i] == '+';
		}
		if(i == str.length() - 1)
		{
			ret = add ? ret + parse_mlt(str.substr(prev)) : ret - parse_mlt(str.substr(prev));
		}
	}
	//cout << "+" << str << ":" << ret << endl;
	return ret;
}

int main()
{
	string str;
	while(cin >> str)
	{
		cout << parse_add(str) << endl;
	}
	return 0;
}
