#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, A, B, C, X;
	while(cin >> N >> A >> B >> C >> X, N != 0)
	{
		vector<int> lst(N);
		for(int i = 0; i < N; i++)
			cin >> lst[i];
		
		vector<int>::iterator it = lst.begin();
		int count = 0;
		for(vector<int>::iterator it = lst.begin(); count <= 10000; count++)
		{
			if(X == *it)
			{
				++it;
				if(it == lst.end())
					break;
			}
			X = (A * X + B) % C;
		}
		cout << (count > 10000 ? -1 : count) << endl;
		
	}
	return 0;
}
