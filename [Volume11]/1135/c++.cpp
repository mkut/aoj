#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int m;
	cin >> m;
	while(m--)
	{
		int begin, year, n;
		cin >> begin >> year >> n;
		int _max = 0;
		while(n--)
		{
			int type, cost;
			double rate;
			cin >> type >> rate >> cost;
			
			int money = begin;
			if(type == 0)
			{
				int plus = 0;
				for(int i = 0; i < year; i++)
				{
					plus += (int)(money * rate);
					money -= cost;
				}
				money += plus;
			}
			else
			{
				money = begin;
				for(int i = 0; i < year; i++)
				{
					money = (int)(money * (1+rate) - cost);
				}
			}
			_max = max(_max, money);
		}
		cout << _max << endl;
	}
	return 0;
}
