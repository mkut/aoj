#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> generate_primes_v(int N){
	//assert(N >= 2);
	vector<int> primes;
	bool* notprime = new bool[N];
	notprime[0] = true;
	notprime[1] = true;
	for(int i = 2; i < N; i++){
		if(!notprime[i]){
			primes.push_back(i);
			for(int j = i+i; j < N; j+=i){
				notprime[j] = true;
			}
		}
	}
	delete [] notprime;
	return primes;
}

long long _solve(vector<int>::iterator cur, vector<int>::iterator end)
{
	if(cur == end)
		return 1;
	return _solve(cur+1, end) * ((*cur)*2+1);
}

long long solve(vector<int>::iterator cur, vector<int>::iterator end)
{
	if(cur == end)
		return 1;
	return _solve(cur+1, end) * (*cur) + solve(cur+1,end);
}

int main()
{
	vector<int> primes = generate_primes_v(1000000);
	
	long long n;
	while(cin >> n, n != 0)
	{
		vector<int> sups;
		for(int i = 0; i < primes.size() && primes[i] <= n; i++)
		{
			if(n % primes[i] == 0)
			{
				int count = 0;
				while(n % primes[i] == 0)
				{
					n /= primes[i];
					count++;
				}
				sups.push_back(count);
			}
		}
		if(n != 1)
			sups.push_back(1);
		
		cout << solve(sups.begin(), sups.end()) << endl;
	}
	
	return 0;
}
