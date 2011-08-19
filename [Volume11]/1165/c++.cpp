#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	while(cin >> N, N != 0)
	{
		int left = 0, bottom = 0, right = 0, top = 0;
		vector<int> x(1), y(1);
		for(int i = 1; i < N; i++)
		{
			int n, d;
			cin >> n >> d;
			if(d == 0)
			{
				left = max(left, -(x[n]-1));
				x.push_back(x[n]-1);
				y.push_back(y[n]);
			}
			else if(d == 1)
			{
				bottom = max(bottom, -(y[n]-1));
				x.push_back(x[n]);
				y.push_back(y[n]-1);
			}
			else if(d == 2)
			{
				right = max(right, x[n]+1);
				x.push_back(x[n]+1);
				y.push_back(y[n]);
			}
			else if(d == 3)
			{
				top = max(top, y[n]+1);
				x.push_back(x[n]);
				y.push_back(y[n]+1);
			}
		}
//		cout << left << "," << right << "," << bottom << "," << top << endl;
		cout << left + right + 1 << " " << bottom + top + 1 << endl;
	}
}
