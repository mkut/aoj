#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct score
{
	int win, lose;
	char name;
	score(char Name) : name(Name) {}
	
	bool operator<(const score& a) const
	{
		return win > a.win || win == a.win && lose < a.lose;
	}
};

int main()
{
	int n;
	while(cin >> n, n)
	{
		vector<score> vs;
		for(int i = 0; i < n; i++)
		{
			string str; cin >> str;
			vs.push_back(score(str[0]));
			for(int j = 0; j < n-1; j++)
			{
				int tmp; cin >> tmp;
				if(tmp == 0) vs.back().win++;
				else if(tmp == 1) vs.back().lose++;
			}
		}
		
		stable_sort(vs.begin(), vs.end());
		
		for(int i = 0; i < n; i++)
			cout << vs[i].name << endl;
	}
	return 0;
}
