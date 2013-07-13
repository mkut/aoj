#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		cin.ignore(100, '\n');
		double x[100], y[100];
		for(int i = 0; i < n; i++)
		{
			string tmp;
			getline(cin, tmp, ',');
			x[i] = atof(tmp.c_str());
			getline(cin, tmp);
			y[i] = atof(tmp.c_str());
		}
		
		int begin = 0;
		for(int i = 1; i < n; i++)
		{
			if(x[i] < x[begin]) begin = i;
		}
		
		int cur = begin;
		int count = 0;
		double dirx = 0, diry = 1;
		do{
			double maxmlt = -100000000;
			int next = -1;
			for(int i = 0; i < n; i++)
			{
				if(i == cur) continue;
				
				double mlt = (dirx*(x[i]-x[cur]) + diry*(y[i]-y[cur])) / sqrt((x[i]-x[cur])*(x[i]-x[cur]) + (y[i]-y[cur])*(y[i]-y[cur]));
				if(mlt > maxmlt)
				{
					maxmlt = mlt;
					next = i;
				}
			}
			count++;
			dirx = x[next]-x[cur];
			diry = y[next]-y[cur];
			cur = next;
		}
		while(cur != begin);
		
		cout << n-count << endl;
	}
	return 0;
}