#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1LL<<40

class solver
{
	vector<long long> sepX, sepH, flowX, flowA;
	int N, M;
public:
	solver(vector<long long>& sepX, vector<long long>& sepH, vector<long long>& flowX, vector<long long>& flowA)
		: sepX(sepX), sepH(sepH), flowX(flowX), flowA(flowA), N(sepX.size()), M(flowX.size()) {}
	
	void flow(int i, vector<long long>& curSepX, vector<long long>& curSepH, vector<long long>& amount)
	{
		//cout << i << ":" << (double)amount[i] / 30 << endl;
		long long capacity = (curSepX[i+1] - curSepX[i]) * min(curSepH[i], curSepH[i+1]) * 30;
		if(amount[i] <= capacity)
			return;
		if(curSepH[i] < curSepH[i+1])
		{
			if(amount[i-1] == (curSepX[i] - curSepX[i-1]) * curSepH[i] * 30)
			{
				amount[i-1] += amount[i]; amount.erase(amount.begin()+i);
				curSepX.erase(curSepX.begin()+i);
				curSepH.erase(curSepH.begin()+i);
				flow(i-1, curSepX, curSepH, amount);
			}
			else
			{
				amount[i-1] += amount[i] - capacity;
				amount[i] = capacity;
				flow(i-1, curSepX, curSepH, amount);
			}
		}
		else
		{
			if(amount[i+1] == (curSepX[i+2] - curSepX[i+1]) * curSepH[i] * 30)
			{
				amount[i+1] += amount[i]; amount.erase(amount.begin()+i);
				curSepX.erase(curSepX.begin()+i+1);
				curSepH.erase(curSepH.begin()+i+1);
				flow(i, curSepX, curSepH, amount);
			}
			else
			{
				amount[i+1] += amount[i] - capacity;
				amount[i] = capacity;
				flow(i+1, curSepX, curSepH, amount);
			}
		}
	}
	double solve(long long x, long long t)
	{
		vector<long long> curSepX = sepX, curSepH = sepH, amount(N-1);
		
		for(int i = 0; i < M; i++)
		{
			int pos = lower_bound(curSepX.begin(), curSepX.end(), flowX[i]) - curSepX.begin() - 1;
			amount[pos] += flowA[i] * t;
			flow(pos, curSepX, curSepH, amount);
		}
		int check_pos = lower_bound(curSepX.begin(), curSepX.end(), x) - curSepX.begin() - 1;
		return (double)amount[check_pos] / (curSepX[check_pos+1]-curSepX[check_pos]) / 30;
	}
};

int main()
{
	int D; cin >> D;
	while(D--)
	{
		int N; cin >> N;
		vector<long long> B(N+4), H(N+4);
		B[0] = -INF; B[1] =  0; B[N+2] = 100; B[N+3] = INF;
		H[0] =  INF; H[1] = 50; H[N+2] =  50; H[N+3] = INF;
		for(int i = 2; i <= N+1; i++)
			cin >> B[i] >> H[i];
		
		int M; cin >> M;
		vector<long long> F(M), A(M);
		for(int i = 0; i < M; i++)
			cin >> F[i] >> A[i];
		
		solver prob(B, H, F, A);
		int L; cin >> L;
		for(int i = 0; i < L; i++)
		{
			long long P, T; cin >> P >> T;
			cout << prob.solve(P, T) << endl;
		}
	}
	return 0;
}
