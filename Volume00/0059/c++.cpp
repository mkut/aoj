#include <iostream>
using namespace std;

int main()
{
	double x[4] = {}, y[4] = {};
	while(cin >> x[0] >> y[0])
	{
		for(int i = 1; i < 4; i++) cin >> x[i] >> y[i];
		
		if(x[0] <= x[3] && x[2] <= x[1] && y[0] <= y[3] && y[2] <= y[1]) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}
	return 0;
}