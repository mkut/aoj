#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

template<int N>
bitset<N> generate_primes_bs(){
	//assert(N >= 2);
	bitset<N> notprime;
	notprime[0] = true;
	notprime[1] = true;
	for(int i = 2; i < N; i++){
		if(!notprime[i]){
			for(int j = i+i; j < N; j+=i){
				notprime[j] = true;
			}
		}
	}
	return notprime;
}

int main()
{
	bitset<1000001> notprime = generate_primes_bs<1000001>();
	int n, x;
	while(cin >> n >> x, n != 0)
	{
		int ans = -1;
		vector<int> menu(n);
		for(int i = 0; i < n; i++)
			cin >> menu[i];
		
		priority_queue<int> Q;
		Q.push(0);
		while(-Q.top() <= x)
		{
			int top = -Q.top();
			cout << top << endl;
			if(!notprime[top])
				ans = max(ans, top);
			
			for(int i = 0; i < n; i++)
				Q.push(Q.top() - menu[i]);
			
			while(-Q.top() == top)
				Q.pop();
		}
		if(ans == -1)
			cout << "NA" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
