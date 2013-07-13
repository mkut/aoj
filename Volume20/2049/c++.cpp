#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int done[1000000];

void reset() { memset(done, -1, 1000000*sizeof(int)); }

int main()
{
	int x, y;
	while(cin >> x >> y, x)
	{
		//map<int,int> done;
		done[x] = 0;
		reset();
		int b, r;
		for(int i = 0; ; i++)
		{
			//if(done.count(x))
			if(~done[x])
			{
				b = done[x];
				r = i - b;
				break;
			}
			if(x == 0)
			{
				b = i;
				r = 0;
				break;
			}
			done[x] = i;
			x = x * 10 % y;
		}
		cout << b << " " << r << endl;
	}
	return 0;
}
