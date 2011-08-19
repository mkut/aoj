#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N; cin >> N; N -= 2;
	vector<long long> prev(21);
	int begin; cin >> begin;
	prev[begin] = 1;
	while(N--)
	{
		int number; cin >> number;
		vector<long long> next(21);
		for(int i = 0; i + number < 21; i++)
			next[i+number] += prev[i];
		for(int i = 20; i - number >= 0; i--)
			next[i-number] += prev[i];
		prev = next;
	}
	int ans; cin >> ans;
	cout << prev[ans] << endl;
	return 0;
}
