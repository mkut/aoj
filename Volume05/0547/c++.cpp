#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int solve(int w, int h, bool tate)
{
	if(w == 1 || h == 1) return 1;
	
	static map<int,int> memo;
	int hash = (w*128+h)*2+(tate?1:0);
	if(memo.count(hash))
		return memo[hash];
	
	int M = tate ? h-2 : w-2;
	int ret = 0;
	for(int i = 1; i <= M; i++)
		ret += solve(tate ? w : i, tate ? i : h, !tate);
	
	memo[hash] = ret % 100000;
	return memo[hash];
}

int main()
{
	int w, h;
	while(cin >> w >> h, w)
	{
		cout << (solve(w, h, true) + solve(w, h, false) + solve(w-1, h, true) + solve(w, h-1, false)) % 100000 << endl;
	}
	return 0;
}
