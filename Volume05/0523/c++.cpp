#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int play(list<int>& p1, list<int>::iterator p1cur, 
		list<int>& p2, list<int>::iterator p2cur, int field, bool taro)
{
	while(p1cur != p1.end())
	{
		if(*p1cur > field)
		{
			field = *p1cur;
			p1cur = p1.erase(p1cur);
			if(p1.size() == 0)
			{
				return p2.size() * (taro ? 1 : -1);
			}
			return play(p2, p2cur, p1, p1cur, field, !taro);
		}
		++p1cur;
	}
	return play(p2, p2.begin(), p1, p1.begin(), 0, !taro);
}

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		list<int> taro, hanako;
		list<int>::iterator ittaro;
		for(int i = 0; i < n; i++)
		{
			int tmp; cin >> tmp;
			taro.push_back(tmp);
		}
		taro.sort();
		
		ittaro = taro.begin();
		for(int i = 1; i <= 2*n; i++)
		{
			if(*ittaro == i) ++ittaro;
			else hanako.push_back(i);
		}
		int ans = play(taro, taro.begin(), hanako, hanako.begin(), 0, true);
		cout << max(ans, 0) << endl << max(-ans, 0) << endl;
	}
	return 0;
}