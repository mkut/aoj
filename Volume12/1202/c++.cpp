#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	int n;
	int No = 0;
	while(cin >> n, No++, n != 0)
	{
		vector<double> borderx, bordery;
		borderx.push_back(-1e10);
		borderx.push_back(1e10);
		bordery.push_back(-1e10);
		bordery.push_back(1e10);
		vector<vector<char> > inner;
		inner.push_back(vector<char>(1));
		while(n--)
		{
			double x, y, r;
			cin >> x >> y >> r;
			int L, R, B, T;
			for(L = 1; L < borderx.size(); L++)
			{
				if(borderx[L] == x-r)
				{
					break;
				}
				if(borderx[L] > x-r)
				{
					borderx.insert(borderx.begin() + L, x-r);
					inner.insert(inner.begin() + L, inner[L-1]);
					break;
				}
			}
			for(R = L; R < borderx.size(); R++)
			{
				if(borderx[R] == x+r)
				{
					break;
				}
				if(borderx[R] > x+r)
				{
					borderx.insert(borderx.begin() + R, x+r);
					inner.insert(inner.begin() + R, inner[R-1]);
					break;
				}
			}
			
			for(B = 0; B < bordery.size(); B++)
			{
				if(bordery[B] == y-r)
				{
					break;
				}
				if(bordery[B] > y-r)
				{
					bordery.insert(bordery.begin() + B, y-r);
					for(int i = 0; i < inner.size(); i++)
					{
						inner[i].insert(inner[i].begin() + B, inner[i][B-1]);
					}
					break;
				}
			}
			for(T = B; T < bordery.size(); T++)
			{
				if(bordery[T] == y+r)
				{
					break;
				}
				if(bordery[T] > y+r)
				{
					bordery.insert(bordery.begin() + T, y+r);
					for(int i = 0; i < inner.size(); i++)
					{
						inner[i].insert(inner[i].begin() + T, inner[i][T-1]);
					}
					break;
				}
			}
			
			for(int i = L; i < R; i++)
				for(int j = B; j < T; j++)
					inner[i][j] = 1;
		}
		
		/*
		for(int i = 0; i < borderx.size(); i++)
			cout << borderx[i] << " ";
		cout << endl;
		for(int i = 0; i < bordery.size(); i++)
			cout << bordery[i] << " ";
		cout << endl;
		for(int i = 0; i < inner.size(); i++)
		{
			for(int j = 0; j < inner[i].size(); j++)
				cout << (inner[i][j] ? '*' : '.');
			cout << endl;
		}
		cout << endl;
		*/
		
		double ans = 0;
		for(int i = 0; i < inner.size(); i++)
			for(int j = 0; j < inner[i].size(); j++)
				if(inner[i][j])
					ans += (borderx[i+1]-borderx[i])*(bordery[j+1]-bordery[j]);
		printf("%d %.2f\n", No, ans);
	}
	return 0;
}
