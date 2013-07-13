#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define EPS 1e-8

double H(vector<int>& num, int N)
{
	double ret = 0;
	for(int i = 0; i < num.size(); i++)
		if(num[i] > 0)
			ret -= (double)num[i] / N * log((double)num[i] / N);
	return ret;
}

int main()
{
	int N;
	while(cin >> N, N)
	{
		vector<int> I(N);
		for(int i = 0; i < N; i++)
			cin >> I[i];
		
		int ans_s, ans_a, ans_c;
		double ans_h = 1e99;
		for(int S = 0; S < 16; S++)
			for(int A = 0; A < 16; A++)
				for(int C = 0; C < 16; C++)
				{
					vector<int> num(256);
					for(int r = A*S+C, i = 0; i < N; r = (A*r+C)%256, i++)
						num[(r+I[i])%256]++;
					double h = H(num, N);
					if(h < ans_h - EPS)
						ans_h = h, ans_s = S, ans_a = A, ans_c = C;
				}
		cout << ans_s << " " << ans_a << " " << ans_c << endl;
	}
}
