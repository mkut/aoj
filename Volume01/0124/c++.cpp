#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<string, int> l, pair<string, int> r)
{
	return l.second > r.second;
}

int main()
{
	int n;
	bool fst = true;
	while(cin >> n, n != 0)
	{
		if(!fst) cout << endl;
		fst = false;
		
		vector<pair<string, int> > score;
		
		for(int i = 0; i < n; i++)
		{
			string stmp;
			int win, lose, draw;
			cin >> stmp >> win >> lose >> draw;
			score.push_back(pair<string,int>(stmp, win*3 + draw));
		}
		stable_sort(score.begin(), score.end(), comp);
		
		for(vector<pair<string, int> >::iterator it = score.begin(); it != score.end(); it++)
		{
			cout << it->first << "," <<  it->second << endl;
		}
	}
	return 0;
}