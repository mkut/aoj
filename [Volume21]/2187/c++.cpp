#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<class T>
vector<T> gen(T begin, T(&f)(T), int size){
//	assert(size >= 0);
	if(size == 0) return vector<int>();
	vector<int> r(size);
	r[0] = begin;
	for(int i = 1; i < size; i++){
		r[i] = (*f)(r[i-1]);
	}
	return r;
}

int ascending(int x)
{
	return x+1;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int G[9], J[9];
		for(int i = 0; i < 9; i++)
			cin >> G[i];
		for(int i = 0; i < 9; i++)
			cin >> J[i];
		vector<int> p = gen(0, ascending, 9);
		
		int count = 0;
		for(int i = 0; i < 362880; i++)
		{
			int score = 0;
			for(int j = 0; j < 9; j++)
				if(G[j] > J[p[j]])
					score += G[j] + J[p[j]];
			if(score > 9*19/2)
				count++;
			next_permutation(p.begin(), p.end());
		}
		printf("%.5f %.5f\n", count / 362880.0, 1 - count / 362880.0);
	}
	return 0;
}
