#include <iostream>
#include <cstdio>
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

vector<int> primes = generate_primes_v(1100);

int kn(int n)
{
	int ret = 0;
	int last = 0;
	for(int i = 0; primes[i]*primes[i] <= n; i++)
	{
		if(n % primes[i] == 0)
		{
			ret -= last;
			last = primes[i];
			while(n % primes[i] == 0)
				n /= primes[i];
		}
	}
	if(n != 1)
	{
		ret -= last;
		last = n;
	}
	return last + ret;
}

int main()
{
	int a, b;
	while(cin >> a >> b, a)
		cout << (kn(a) > kn(b) ? 'a' : 'b') << endl;
	return 0;
}
