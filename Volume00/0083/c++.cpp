#include <iostream>
using namespace std;

int main()
{
	int era[4] = {18680908,19120730,19261225,19890108};
	string sera[4] = {"meiji", "taisho", "showa", "heisei"};
	
	int y, m, d;
	while(cin >> y >> m >> d)
	{
		bool finished = false;
		for(int i = 3; i >= 0; i--)
		{
			if(d+m*100+y*10000 >= era[i])
			{
				cout << sera[i] << " " << y-era[i]/10000 + 1 << " " << m << " " << d << endl;
				finished = true;
				break;
			}
		}
		if(finished) continue;
		
		cout << "pre-meiji" << endl;
	}
	return 0;
}