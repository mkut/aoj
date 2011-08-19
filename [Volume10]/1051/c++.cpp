#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		vector<int> vi(n+1);
		for(int i = 0; i < n; i++)
			cin >> vi[i];
		
		bool first = true;
		int cntn = 0;
		for(int i = 0; i < n+1; i++)
		{
			if(first)
			{
				first = false;
				cout << vi[i];
			}
			else if(vi[i] == vi[i-1] + 1 && i < n)
			{
				cntn++;
			}
			else
			{
				if(cntn != 0)
					cout << "-" << vi[i-1];
				
				if(i < n)
				{
					if(!first) cout << " ";
					first = false;
					cout << vi[i];
					cntn = 0;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
