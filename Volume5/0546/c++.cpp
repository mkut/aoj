#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void solve(vector<int>& cards, vector<char> used, set<int>& S, int k, int cur)
{
	if(k== 0)
	{
		S.insert(cur);
		return;
	}
	
	for(int i = 0; i < used.size(); i++)
	{
		if(!used[i])
		{
			used[i] = true;
			solve(cards, used, S, k-1, cur*(cards[i]<10 ? 10 : 100) + cards[i]);
			used[i] = false;
		}
	}
}

int main()
{
	int n, k;
	while(cin >> n >> k, n)
	{
		vector<int> cards(n);
		for(int i = 0; i < n; i++)
			cin >> cards[i];
		
		set<int> S;
		
		solve(cards, vector<char>(n), S, k, 0);
		cout << S.size() << endl;
	}
	return 0;
}
