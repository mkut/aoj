#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		map<char, char> table;
		for(int i = 0; i < n; i++)
		{
			char from, to; cin >> from >> to;
			table[from] = to;
		}
		
		int m;
		cin >> m;
		for(int i = 0; i < m; i++)
		{
			char val; cin >> val;
			if(table.count(val) == 0) cout << val;
			else cout << table[val];
		}
		cout << endl;
	}
	return 0;
}