#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int top=1, south=2, east=3, west=4, north=5, bottom=6;
		int sum = 1;
		for(int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			
			if(str == "North")
			{
				int tmp = top;
				top = south;
				south = bottom;
				bottom = north;
				north = tmp;
			}
			else if(str == "East")
			{
				int tmp = top;
				top = west;
				west = bottom;
				bottom = east;
				east = tmp;
			}
			else if(str == "South")
			{
				int tmp = top;
				top = north;
				north = bottom;
				bottom = south;
				south = tmp;
			}
			else if(str == "West")
			{
				int tmp = top;
				top = east;
				east = bottom;
				bottom = west;
				west = tmp;
			}
			else if(str == "Right")
			{
				int tmp = south;
				south = east;
				east = north;
				north = west;
				west = tmp;
			}
			else if(str == "Left")
			{
				int tmp = south;
				south = west;
				west = north;
				north = east;
				east = tmp;
			}
			sum += top;
		}
		cout << sum << endl;
	}
	return 0;
}