#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string itos(int i)
{
	char a[100];
	sprintf(a, "%d", i);
	return string(a);
}

string output0(string a, string b, int ope)
{
	char cope[6] = {'+', '-', '-', '*', '/', '/'};
	switch(ope)
	{
	  case 0:
	  case 1:
	  case 3:
	  case 4:
		return "(" + a + " " + cope[ope] + " " + b + ")";
	  case 2:
	  case 5:
		return "(" + b + " " + cope[ope] + " " + a + ")";
	}
	return "";
}

string output1(vector<int>::iterator it, int ope1, int ope2, int ope3)
{
	string ret;
	ret = output0(itos(*it), itos(*(it+1)), ope1);
	ret = output0(ret, itos(*(it+2)), ope2);
	ret = output0(ret, itos(*(it+3)), ope3);
	return ret;
}
string output2(vector<int>::iterator it, int ope1, int ope2, int ope3)
{
	string ret, ret2;
	ret = output0(itos(*it), itos(*(it+1)), ope1);
	ret2 = output0(itos(*(it+2)), itos(*(it+3)),ope2);
	ret = output0(ret, ret2, ope3);
	return ret;
}

void calc2(int* _n, int* _d, int n, int d, int ope)
{
	switch(ope)
	{
	  case 0:
		*_n = (*_n) * d + n * (*_d);
		*_d = d * (*_d);
		break;
	  case 1:
		*_n = (*_n) * d - n * (*_d);
		*_d = d * (*_d);
		break;
	  case 2:
		*_n = n * (*_d) - (*_n) * d;
		*_d = d * (*_d);
		break;
	  case 3:
		*_n *= n;
		*_d *= d;
		break;
	  case 4:
		*_n *= d;
		*_d *= n;
		break;
	  case 5:
		int tmp = *_d;
		*_d = d * (*_n);
		*_n = n * tmp;
		break;
	}
	return;
}

int calc(vector<int>::iterator p, int ope1, int ope2, int ope3)
{
	int ope[3] = {ope1, ope2, ope3};
	vector<int>::iterator it = p;
	int n = *it;
	int d = 1;
	
	for(int i = 0; i < 3; i++)
	{
		calc2(&n, &d, *(it+i+1), 1, ope[i]);
	}
	if(d != 0) if((double)n/d == 10) return 1;
	
	it = p;
	n = *it;
	d = 1;
	calc2(&n, &d, *(it+1), 1, ope[0]);
	int n2 = *(p+2);
	int d2 = 1;
	calc2(&n2, &d2, *(it+3), 1, ope[1]);
	calc2(&n, &d, n2, d2, ope[2]);
	if(d != 0) if((double)n/d ==10) return 2;
	
	return 0;
}

string solve(vector<int> p)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				int result = calc(p.begin(), i, j, k);
				if(result == 1) return output1(p.begin(), i, j, k);
				if(result == 2) return output2(p.begin(), i, j, k);
			}
		}
	}
	return "";
}

int main()
{
	int a, b, c, d;
	while(cin >> a >> b >> c >> d, a != 0)
	{
		vector<int> p;
		p.insert(p.end(), a);
		p.insert(p.end(), b);
		p.insert(p.end(), c);
		p.insert(p.end(), d);
		sort(p.begin(), p.end());
		
		bool finish = false;
		do{
			string result = solve(p);
			if(result != "")
			{
				cout << result << endl;
				finish = true;
				break;
			}
		}
		while(next_permutation(p.begin(), p.end()));
		
		if(!finish) cout << "0" << endl;
	}
	
	return 0;
}