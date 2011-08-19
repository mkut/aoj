#include <iostream>
using namespace std;

int main()
{
	const double time[7][2] = {{35.5,71}, {37.5,77}, {40,83}, {43,89}, {50,105}, {55,116}, {70,148}};
	const string lank[7] = {"AAA", "AA", "A", "B", "C", "D", "E"};
	
	double time500, time1000;
	while(cin >> time500 >> time1000)
	{
		for(int i = 0; i < 8; i++)
		{
			if(i == 7)
			{
				cout << "NA" << endl;
				break;
			}
			if(time500 < time[i][0] && time1000 < time[i][1])
			{
				cout << lank[i] << endl;
				break;
			}
		}
	}
	
	return 0;
}