#include <iostream>
using namespace std;

bool check2(int pai, int n)
{
	if(n == 0) return true;
	
	for(int i = 0; i < 9; i++)
	{
		if((pai >> 3*i & 7) >= 3)
		{
			if(check2(pai - (3 << i*3), n-1))
			{
				return true;
			}
		}
	}
	for(int i = 0; i < 7; i++)
	{
		if((pai >> 3*i & 7) >= 1 && (pai >> 3*(i+1) & 7) >= 1 && (pai >> 3*(i+2) & 7) >= 1)
		{
			if(check2(pai - (73 << i*3), n-1))
			{
				return true;
			}
		}
	}
	return false;
}

bool check(int pai)
{
	/*
	for(int i = 0; i < 9; i++)
	{
		cout << ((pai >> 3*i) & 7);
	}
	cout << endl;
	*/
	for(int i = 0; i < 9; i++)
	{
		if((pai >> 3*i & 7) >= 2)
		{
			if(check2(pai - (2 << i*3), 4))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	long long input;
	while(cin >> input)
	{
		int pai = 0;
		for(; input != 0; input /= 10)
		{
			pai += 1 << (input%10-1)*3;
		}
		
		bool first = true;
		for(int i = 0; i < 9; i++)
		{
			if(((pai >> i*3) & 7) == 4) continue;
			
			if(check(pai + (1 << i*3)))
			{
				cout << (first ? "" : " ") << i+1;
				first = false;
			}
		}
		cout << (first ? "0" : "") << endl;
	}
	return 0;
}