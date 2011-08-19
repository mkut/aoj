#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 99999999

struct Food
{
	string f;
	int w, s;
	Food(string f, int w, int s) : f(f), w(w), s(s) {}
	bool operator<(const Food& a) const { return w < a.w || w == a.w && s < a.s || w == a.w && s == a.s && f < a.f; }
};

int g(vector<Food>& fs)
{
	int n = fs.size();
	int weight = 0;
	int ret = 0;
	for(int i = 0; i < n; i++)
	{
		if(fs[i].s < weight)
			return INF;
		ret += (n-i) * fs[i].w;
		weight += fs[i].w;
	}
	return ret;
}

int main()
{
	int n;
	int fact[11] = {1};
	for(int i = 1; i < 11; i++) fact[i] = fact[i-1] * i;
	while(cin >> n, n)
	{
		vector<Food> fs;
		for(int i = 0; i < n; i++)
		{
			string f; int w, s; cin >> f >> w >> s;
			fs.push_back(Food(f, w, s));
		}
		int ans_g = INF;
		vector<Food> ans;
		for(int i = 0; i < fact[n]; i++)
		{
			int G = g(fs);
			if(ans_g > G)
				ans_g = G, ans = fs;
			next_permutation(fs.begin(), fs.end());
		}
		for(int i = n-1; i >= 0; i--)
			cout << ans[i].f << endl;
	}
	return 0;
}
