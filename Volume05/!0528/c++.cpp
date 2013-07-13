#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	/*
	int A = 89119276, B = 918672, C = 891726485;
	int X = 897631;
	for(int i = 0; i < 4000; i++)
	{
		if(X & 1)
			cout << "A";
		else
			cout << "B";
		X = (X * A + B) % C;
	}
	cout << endl;
	for(int i = 0; i < 4000; i++)
	{
		if(X & 1)
			cout << "A";
		else
			cout << "B";
		X = (X * A + B) % C;
	}
	cout << endl;
	*/
	
	string a, b;
	while(cin >> a >> b)
	{
		a += '.';
		b += ',';
		int ans = 0;
		for(int i = 0; i < a.length(); i++)
		{
			if(a.length() - i < ans)
				break;
			for(int j = 0; j < b.length(); j++)
			{
				if(b.length() - j < ans)
					break;
				int count = 0;
				for(int k = 0; a[i+k] == b[j+k]; k++)
					count++;
				ans = max(ans, count);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
