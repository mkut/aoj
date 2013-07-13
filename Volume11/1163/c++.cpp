#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int x, int y){
	return x % y == 0 ? y : gcd(y, x % y);
}

class solver
{
	vector<vector<char> > pathR, pathL;
	vector<char> pathG;
	
public:
	solver(vector<vector<char> > PR, vector<vector<char> > PL, vector<char> PG)
	{
		pathR = PR;
		pathL = PL;
		pathG = PG;
	}
	
	int solve()
	{
		int count = 0;
		for(int i = 0; i < pathR.size(); i++)
		{
			doneL = vector<char>(pathR.size());
			doneR = vector<char>(pathL.size());
			if(flow(i, false))
				count++;
		}
		return count;
	}
	
private:
	vector<char> doneL, doneR;
	bool flow(int cur, bool R)
	{
		if(R && pathG[cur])
		{
			pathG[cur] = 0;
			return true;
		}
		if(R)
		{
			if(doneR[cur])
				return false;
			doneR[cur] = true;
			for(int i = 0; i < pathL[cur].size(); i++)
			{
				if(pathL[cur][i] && flow(i, !R))
				{
					pathL[cur][i] = 0;
					pathR[i][cur] = 1;
					return true;
				}
			}
		}
		else // if(!R)
		{
			if(doneL[cur])
				return false;
			doneL[cur] = true;
			for(int i = 0; i < pathR[cur].size(); i++)
			{
				if(pathR[cur][i] && flow(i, !R))
				{
					pathR[cur][i] = 0;
					pathL[i][cur] = 1;
					return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	int m, n;
	while(cin >> m >> n, m != 0)
	{
		vector<int> blue(m), red(n);
		for(int i = 0; i < m; i++)
			cin >> blue[i];
		for(int i = 0; i < n; i++)
			cin >> red[i];
			
		vector<vector<char> > pathR(m), pathL(n);
		for(int i = 0; i < m; i++)
			pathR[i] = vector<char>(n);
		for(int i = 0; i < n; i++)
			pathL[i] = vector<char>(m);
		vector<char> pathG(n);
		
		for(int i = 0; i < n; i++)
			pathG[i] = 1;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(gcd(blue[i], red[j]) != 1)
					pathR[i][j] = 1;
		
		solver prob(pathR, pathL, pathG);
		cout << prob.solve() << endl;
	}
	return 0;
}
