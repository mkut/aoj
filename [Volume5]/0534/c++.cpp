#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	while(cin >> N, N != 0)
	{
		vector<int> vi(N);
		for(int i = 0; i < N; i++) cin >> vi[i];
		
		int _min = N;
		for(int i = 0; i < N; i++)
		{
			for(int color = 1; color <= 3; color++)
			{
				int colorstk = vi[i];
				vi[i] = color;
				int nextpos = i;
				int prevpos = i-1;
				int curcolor = color;
				int sum = 0;
				while(true)
				{
					int samecolor = 0;
					int pos;
					for(pos = nextpos; pos < N; pos++)
						if(vi[pos] == curcolor)
							samecolor++;
						else break;
					nextpos = pos;
					
					for(pos = prevpos; pos >= 0; pos--)
						if(vi[pos] == curcolor)
							samecolor++;
						else break;
					prevpos = pos;
					
					if(samecolor < 4)
						break;
					else
					{
						curcolor = vi[nextpos];
						sum += samecolor;
					}
				}
				_min = min(_min, N-sum);
				vi[i] = colorstk;
			}
		}
		cout << _min << endl;
	}
	return 0;
}
