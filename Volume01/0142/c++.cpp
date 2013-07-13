#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdlib.h>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		vector<int> lst;
		for(int i = 1; i <= n/2; i++)
		{
			lst.push_back(i*i%n);
		}
		sort(lst.begin(), lst.end());
		lst.erase(unique(lst.begin(), lst.end()), lst.end());
		
		//map<int, int> ans;
		int ans[10000] = {};
		for(vector<int>::iterator it = lst.begin(); it != lst.end(); it++)
		{
			for(vector<int>::iterator it2 = it+1; it2 != lst.end(); it2++)
			{
				ans[min(abs(*it - *it2), n-abs(*it - *it2))]++;
			}
		}
		for(int i = 1; i <= n/2; i++)
		{
			cout << ans[i]*2 << endl;
		}
	}
	return 0;
}