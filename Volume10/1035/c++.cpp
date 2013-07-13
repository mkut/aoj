#include <iostream>
#include <vector>
using namespace std;

int check(const vector<int>& space, int width)
{
	int count = 0;
	for(int i = 0; i < space.size(); i++)
	{
		if(space[i] == -1) count++;
		else count = 0;
		if(count == width) return i-width+1;
	}
	return -1;
}

int main()
{
	int W, Q;
	while(cin >> W >> Q, W != 0 || Q != 0)
	{
		vector<int> space(W);
		for(int i = 0; i < W; i++) space[i] = -1;
		for(int i = 0; i < Q; i++)
		{
			char c;
			int number;
			cin >> c >> number;
			if(c == 's')
			{
				int width;
				cin >> width;
				int pos = check(space, width);
				if(pos != -1)
				{
					for(int i = 0; i < width; i++)
					{
						space[pos+i] = number;
					}
					cout << pos << endl;
				}
				else
				{
					cout << "impossible" << endl;
				}
			}
			else
			{
				for(int i = 0; i < space.size(); i++)
				{
					if(space[i] == number) space[i] = -1;
				}
			}
		}
		cout << "END" << endl;
	}
	return 0;
}