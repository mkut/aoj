#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n)
	{
		int ok[3] = {}, all[3] = {};
		string name[3] = {"lunch", "dinner", "midnight"};
		while(n--)
		{
			int a, b, c; char ign;
			cin >> a >> ign >> b >> c;
			int block = -1;
			if(a >= 11 && a <= 14)
				block = 0;
			else if(a >= 18 && a <= 20)
				block = 1;
			else if(a >= 21 || a <= 1)
				block = 2;
			if(block == -1)
				continue;
	
			all[block]++;
			if(b <= c && c <= b+8 || b <= c+60 && c+60 <= b+8)
				ok[block]++;
		}
		for(int i = 0; i < 3; i++)
		{
			cout << name[i] << " ";
			if(all[i] == 0)
				cout << "no guest";
			else
				cout << 100 * ok[i] / all[i];
			cout << endl;
		}
	}
}
