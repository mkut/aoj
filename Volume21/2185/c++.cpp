#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int x, y, w, h;
		cin >> x >> y >> w >> h;
		w += x;
		h += y;
		int n;
		cin >> n;
		int count = 0;
		for(int i = 0; i < n; i++)
		{
			int tx, ty;
			cin >> tx >> ty;
			if(tx >= x && tx <= w && ty >= y && ty <= h)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}
