#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct solver
{
	string seat;
	vector<int> distance;
	int n;
	
	solver(int N) : n(N), seat(N, '#'), distance(N, 10000) {}
	
	void select(char c)
	{
		bool ok = false;
		switch(c)
		{
			case 'A':
				for(int i = 0; i < n; i++)
					if(seat[i] == '#')
					{
						sit('A', i);
						break;
					}
				break;
				
			case 'B':
				for(int i = n-1; i >= 0; i--)
				{
					if(seat[i] == '#' && (i == 0 || seat[i-1] != 'A') && (i == n-1 || seat[i+1] != 'A'))
					{
						ok = true;
						sit('B', i);
						break;
					}
				}
				if(!ok)
				{
					for(int i = 0; i < n; i++)
						if(seat[i] == '#')
						{
							sit('B', i);
							break;
						}
				}
				break;
				
			case 'C':
				for(int i = 0; i < n; i++)
				{
					if(seat[i] != '#')
					{
						if(i < n-1 && seat[i+1] == '#')
						{
							ok = true;
							sit('C', i+1);
							break;
						}
						else if(i > 0 && seat[i-1] == '#')
						{
							ok = true;
							sit('C', i-1);
							break;
						}
					}
				}
				if(!ok)
				{
					sit('C', n/2);
				}
				break;
				
			case 'D':
				int p = 0, Min = 0;
				for(int i = 0; i < n; i++)
					if(Min < distance[i] && seat[i] == '#')
						Min = distance[i], p = i;
				sit('D', p);
		}
	}

	void sit(char c, int pos)
	{
		seat[pos] = c;
		for(int i = 0; i < distance.size(); i++)
			distance[i] = min(distance[i], abs(i-pos));
	}
};

int main()
{
	int n, m;
	while(cin >> n >> m, n)
	{
		solver prob(n);
		
		for(int i = 0; i < m; i++)
		{
			string str; cin >> str;
			prob.select(str[0]);
			//cout << prob.seat << endl;
		}
		cout << prob.seat << endl;
	}
	return 0;
}
