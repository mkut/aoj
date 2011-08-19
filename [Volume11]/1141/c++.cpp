#include <iostream>
#include <algorithm>
using namespace std;

#include <bitset>
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
	bitset<1000000> notprime = generate_primes_bs<1000000>();
	
	int a, d, n;
	while(cin >> a >> d >> n, a != 0)
	{
		for(int i = 0, num = 0; num < n; i++)
			if(!notprime[a+d*i])
				if(++num == n)
					cout << a+d*i << endl;
	}
	return 0;
}
