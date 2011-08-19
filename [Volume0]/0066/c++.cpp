#include <iostream>
using namespace std;

int main()
{
	string input;
	while(cin >> input)
	{
		int row[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
		bool finished = false;
		for(int i = 0; i < 8; i++)
		{
			if(input[row[i][0]] == input[row[i][1]] && input[row[i][0]] == input[row[i][2]])
			{
				if(input[row[i][0]] != 's')
				{
					cout << input[row[i][0]] << endl;
					finished = true;
					break;
				}
			}
		}
		if(!finished) cout << 'd' << endl;
	}
	return 0;
}