#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		vector<int> ls;
		int count = 0;
		int top[5] = {};
		for(int i = 0; i < n; i++)
		{
			int d, p, q;
			cin >> d >> p >> q;
			count += p;
			if(d==1)
			{
				int val = ((1 << p) - 1) << (q-1);
				int _pos = 0;
				for(int j = q-1; j < p+q-1; j++)
				{
					_pos = max(_pos, top[j]);
				}
				if(_pos == ls.size()) ls.push_back(val);
				else ls[_pos] |= val;
				for(int j = q-1; j < p+q-1; j++)
				{
					top[j] = _pos+1;
				}
			}
			else
			{
				for(int j = top[q-1]; j < top[q-1]+p; j++)
				{
					if(j == ls.size()) ls.push_back(1<<(q-1));
					else ls[j] |= 1<<(q-1);
				}
				top[q-1] += p;
			}
			
			for(int i = ls.size()-1; i >= 0; i--)
			{
				if(ls[i] == 31)
				{
					ls.erase(ls.begin()+i);
					count -= 5;
				}
			}
			for(int j = 0; j < 5; j++)
			{
				while(top[j]> ls.size() || (top[j] > 0 && ((ls[top[j]-1]>>j)&1)==0))
				{
					top[j]--;
				}
			}
			/*
			for(int i = 0; i < ls.size(); i++)
			{
				for(int j = 0; j <5; j++)
				{
					if((ls[i] >> j) & 1) cout << '#';
					else cout << '.';
				}
				cout << endl;
			}
			for(int i = 0; i < 5; i++)
			{
				cout << top[i];
			}
			cout << endl;
			cout << endl;
			*/
		}
		
		cout << count << endl;
	}
	return 0;
}