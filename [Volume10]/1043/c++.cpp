#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Team
{
	int id, belongs, correct, penalty;
	Team(int i, int b, int c, int p)
	{
		id = i;
		belongs = b;
		correct = c;
		penalty = p;
	}
};

bool operator<(Team a, Team b)
{
	return a.correct > b.correct || (a.correct == b.correct && (a.penalty < b.penalty || (a.penalty == b.penalty && a.id < b.id)));
}

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		vector<Team> teams;
		map<int,int> univ;
		for(int i = 0; i < n; i++)
		{
			int i, b, c, p;
			cin >> i >> b >> c >> p;
			teams.push_back(Team(i,b,c,p));
		}
		sort(teams.begin(), teams.end());
		int ranked = 0;
		for(int i = 0; i < teams.size(); i++)
		{
			if(ranked < 10)
			{
				if(univ[teams[i].belongs]++ < 3)
				{
					cout << teams[i].id << endl;
					ranked++;
				}
			}
			else if(ranked < 20)
			{
				if(univ[teams[i].belongs]++ < 2)
				{
					cout << teams[i].id << endl;
					ranked++;
				}
			}
			else if(ranked < 26)
			{
				if(univ[teams[i].belongs]++ < 1)
				{
					cout << teams[i].id << endl;
					ranked++;
				}
			}
		}
	}
	return 0;
}