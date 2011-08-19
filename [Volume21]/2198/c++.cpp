#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct seed
{
	string name;
	double rate;
	seed() : name(""), rate(0) {}
	seed(string Name, double Rate) : name(Name), rate(Rate) {}
	bool operator<(const seed& a) const
	{
		return rate > a.rate || (fabs(rate - a.rate) < 1e-8 && name < a.name);
	}
};

int main()
{
	int N;
	while(cin >> N, N)
	{
		vector<seed> ss(N);
		for(int i = 0; i < N; i++)
		{
			string L;
			int P, A, B, C, D, E, F, S, M;
			cin >> L >> P >> A >> B >> C >> D >> E >> F >> S >> M;
			double rate = (double)(F*S*M-P) / (A+B+C+(D+E)*M);
			ss[i] = seed(L, rate);
		}
		sort(ss.begin(), ss.end());
		for(int i = 0; i < N; i++)
			cout << ss[i].name << endl;
		cout << "#" << endl;
	}
	return 0;
}
