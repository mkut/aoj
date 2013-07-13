#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m, n)
	{
		map<string,int> list;
		while(n--)
		{
			string snum;
			int prize;
			cin >> snum >> prize;
			while(snum[0] == '*')
				snum = snum.substr(1);
			list[snum] = prize;
		}
		int sum = 0;
		while(m--)
		{
			string snum;
			cin >> snum;
			for(int i = 0; i < 8; i++)
			{
				if(list.count(snum.substr(i)))
				{
					sum += list[snum.substr(i)];
					break;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
