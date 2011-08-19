#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int L;
	while(cin >> L, L != 0)
	{
		bool finished = false;
		int sum = 0;
		for(int i = 0; i < 12; i++)
		{
			int M, N;
			cin >> M >> N;
			sum += M - N;
			if(!finished && sum >= L)
			{
				cout << i+1 << endl;
				finished = true;
			}
		}
		if(!finished)
			cout << "NA" << endl;
	}
	return 0;
}
