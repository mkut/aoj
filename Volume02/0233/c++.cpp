#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n)
	{
		vector<int> array;
		bool minus = n < 0;
		n = abs(n);
		while(abs(n))
			array.push_back(n%10), n/= 10;
		for(int i = 0; i < array.size(); i++)
			if(i%2 xor minus) array[i] *= -1;
		for(int i = 0; i < array.size(); i++)
			if(array[i] < 0)
			{
				array[i] += 10;
				if(i+1 < array.size())
					array[i+1] += 1;
				else
					array.push_back(1);
			}
			else if(array[i] >= 10)
			{
				array[i] -= 10;
				if(i+1 < array.size())
					array[i+1] -= 1;
				else
					array.push_back(-1);
			}
		for(int i = array.size() - 1; i >= 0; i--)
			cout << array[i];
		cout << endl;
	}
	return 0;
}
