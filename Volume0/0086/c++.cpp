#include <iostream>
#include <map>
using namespace std;

int main()
{
	int a, b;
	while(cin >> a >> b)
	{
		map<int, int> rank;
		rank[a]++;
		rank[b]++;
		while(cin >> a >> b, a != 0 || b != 0)
		{
			rank[a]++;
			rank[b]++;
		}
		string ans = "OK";
		for(map<int, int>::iterator it = rank.begin(); it != rank.end(); it++)
		{
			if(((it->second & 1) != 0 && it->first > 2) || ((it->second & 1) != 1 && it->first <= 2))
			{
				ans = "NG";
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}