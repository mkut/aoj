#include <iostream>
using namespace std;

int main()
{
	const int chk[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
	
	string str[3];
	while(cin >> str[0], str[0] != "0")
	{
		cin >> str[1] >> str[2];
		string all = str[0] + str[1] + str[2];
		
		bool finished = false;
		for(int i = 0; i < 8; i++)
		{
			if(all[chk[i][0]] == all[chk[i][1]] && all[chk[i][0]] == all[chk[i][2]] && all[chk[i][0]] != '+')
			{
				cout << all[chk[i][0]] << endl;
				finished = true;
				break;
			}
		}
		
		if(!finished) cout << "NA" << endl;
	}
	return 0;
}