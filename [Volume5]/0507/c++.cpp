#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void d(vector<int> vi)
{
	bool first = true;
	for(int i = 0; i < vi.size(); i++)
	{
		cout << (first ? "" : " ") << vi[i];
		first = false;
	}
	cout << endl;
}

vector<vector<int> > solve(int n, int _max)
{
	if(n == 0) return vector<vector<int> >();
	vector<vector<int> > r;
	if(n <= _max)
	{
		r.push_back(vector<int>(1));
		r[0][0] = n;
	}
	for(int i = min(n, _max); i >= 1; i--)
	{
		vector<vector<int> > prev = solve(n-i, i);
		for(int j = 0; j < prev.size(); j++)
		{
			prev[j].insert(prev[j].begin(), i);
		}
		r.insert(r.end(), prev.begin(), prev.end());
	}
	return r;
}

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		vector<vector<int> > ans = solve(n, n);
		for(int i = 0; i < ans.size(); i++) d(ans[i]);
	}
	return 0;
}