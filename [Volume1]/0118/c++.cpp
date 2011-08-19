#include <iostream>
using namespace std;

void draw(char* input, int pos, char type)
{
	input[pos] = '/';
	int next[] = {-102, -1, 1, 102};
	
	for(int i = 0; i < 4; i++)
	{
		if(input[pos+next[i]] == type) draw(input, pos+next[i], type);
	}
}

int main()
{
	int H, W;
	while(cin >> H >> W, H != 0)
	{
		char input[102][102];
		for(int i = 1; i <= H; i++)
		{
			cin >> (input[i]+1);
			input[i][0] = '/';
			input[i][W+1] = '/';
		}
		for(int i = 0; i < 102; i++)
		{
			input[0][i] = '/';
			input[H+1][i] = '/';
		}
		
		int count = 0;
		for(int i = 1; i <= H; i++)
		{
			for(int j = 1; j <= W; j++)
			{
				if(input[i][j] != '/')
				{
					draw(input[0], i*102+j, input[i][j]);
					count++;
				}
			}
		}
		cout << count << endl;
	}
	
	return 0;
}