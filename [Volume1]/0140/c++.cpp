#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	const int stop[] = {0,1,2,3,4,5,6,7,8,9,5,4,3,2,1,0,1,2,3,4,5,6,7,8,9};
	
	int n;
	cin >> n;
	while(n--)
	{
		int start, goal;
		cin >> start >> goal;
		ostringstream ans;
		ans << start;
		for(int i = start+1; stop[i] != goal; i++)
		{
			ans << " " << stop[i];
			if(stop[i] == start)
			{
				ans.str("");
				ans << start;
			}
		}
		ans << " " << goal;
		cout << ans.str() << endl;
	}
	return 0;
}