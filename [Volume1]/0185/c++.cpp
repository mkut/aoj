#include <iostream>
#include <bitset>
using namespace std;

template<int N>
bitset<N> generate_primes_bs(){
	//assert(N >= 2);
	bitset<N> notprime;
	notprime[0] = true;
	notprime[1] = true;
	for(int i = 2; i < N; i++){
		if(!notprime[i]){
			for(int j = 2; i*j < N; j++){
				notprime[i*j] = true;
			}
		}
	}
	return notprime;
}

int main()
{
	bitset<1000001> notprime = generate_primes_bs<1000001>();
	
	int n;
	while(cin >> n, n != 0)
	{
		int count = 0;
		for(int i = 3; i <= n/2; i+=2)
		{
			if(!notprime[i] && !notprime[n-i]) count++;
		}
		cout << count << endl;
	}
	return 0;
}