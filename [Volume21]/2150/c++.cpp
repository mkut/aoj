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

int main()
{
	vector<int> primes = generate_primes_v(1000000);
	
	int N, P;
	while(cin >> N >> P, N != -1)
	{
		int begin = 0;
		while(primes[begin] <= N)
			begin++;
		
		vector<int> lst;
		for(int i = begin; i < begin+100; i++)
			for(int j = i; j < begin+100; j++)
				lst.push_back(primes[i] + primes[j]);
		
		sort(lst.begin(), lst.end());
		cout << lst[P-1] << endl;
	}
	return 0;
}
