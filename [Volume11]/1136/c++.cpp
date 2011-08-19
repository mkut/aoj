#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		vector<int> ori_l;
		bitset<10> ori_d;
		
		for(int i = 0; i < 1; i++)
		{
			int m;
			cin >> m;
			int prevx, prevy;
			char prevd = 0;
			cin >> prevx >> prevy;
			for(int j = 0; j < m-1; j++)
			{
				int x, y; cin >> x >> y;
				ori_l.push_back(abs(x-prevx)+abs(y-prevy));
				char curd = x == prevx ? (y > prevy ? 8 : 2) : (x > prevx ? 6 : 4);
				if(prevd != 0)
					ori_d[j-1] = (prevd == 8 && curd == 4) || (prevd == 4 && curd == 2) || (prevd == 2 && curd == 6) || (prevd == 6 && curd == 8);
				prevx = x; prevy = y;
				prevd = curd;
			}
		}
		
		for(int i = 1; i <= n; i++)
		{
			vector<int> cur_l;
			bitset<10> cur_d;
			int m;
			cin >> m;
			int prevx, prevy;
			char prevd = 0;
			cin >> prevx >> prevy;
			for(int j = 0; j < m-1; j++)
			{
				int x, y; cin >> x >> y;
				cur_l.push_back(abs(x-prevx)+abs(y-prevy));
				char curd = x == prevx ? (y > prevy ? 8 : 2) : (x > prevx ? 6 : 4);
				if(prevd != 0)
					cur_d[j-1] = (prevd == 8 && curd == 4) || (prevd == 4 && curd == 2) || (prevd == 2 && curd == 6) || (prevd == 6 && curd == 8);
				prevx = x; prevy = y;
				prevd = curd;
			}
			if(m != ori_l.size() + 1)
				continue;
			
			if(ori_l == cur_l)
			{
				bool ok = true;
				for(int j = 0; j < cur_l.size() - 1; j++)
					if(ori_d[j] != cur_d[j])
						ok = false;
				if(ok)
				{
					cout << i << endl;
					continue;
				}
			}
			reverse(cur_l.begin(), cur_l.end());
			if(ori_l == cur_l)
			{
				bool ok = true;
				for(int j = 0; j < cur_l.size() - 1; j++)
					if(ori_d[j] == cur_d[cur_l.size() - 2 - j])
						ok = false;
				if(ok)
				{
					cout << i << endl;
					continue;
				}
			}
		}
		cout <<  "+++++" << endl;
	}
	return 0;
}
