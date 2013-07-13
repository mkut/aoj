#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	string a, b;
	while(cin >> a >> b, a != "0")
	{
		int anum[10] = {}, bnum[10] = {};
		for(int i = 0; i < 4; i++)
			anum[a[i]-'0']++, bnum[b[i]-'0']++;
		
		int hit = 0, blow = 0;
		for(int i = 0; i < 4; i++)
			if(a[i] == b[i])
				hit++;
		
		for(int i = 0; i < 10; i++)
			if(anum[i] && bnum[i])
				blow++;
		cout << hit << " " << blow - hit << endl;
	}
	return 0;
}
