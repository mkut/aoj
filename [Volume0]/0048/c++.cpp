#include <iostream>
using namespace std;

int main()
{
	double border[] = {48,51,54,57,60,64,69,75,81,91};
	string rank[] = {"light fly", "fly", "bantam", "feather", "light", "light welter", "welter", "light middle", "middle", "light heavy", "heavy"};
	
	double input;
	while(cin >> input)
	{
		for(int i = 0; i <= 10; i++)
		{
			if(i == 10)
			{
				cout << rank[i] << endl;
				break;
			}
			if(input <= border[i])
			{
				cout << rank[i] << endl;
				break;
			}
		}
	}
	return 0;
}