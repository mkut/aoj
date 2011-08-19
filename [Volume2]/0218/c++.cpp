#include <iostream>
#include <algorithm>
using namespace std;

char grade(int m, int e, int j)
{
	if(m == 100 || e == 100 || j == 100) return 'A';
	if(m + e >= 180) return 'A';
	if(m + e + j >= 240) return 'A';
	if(m + e + j >= 210) return 'B';
	if(m + e + j >= 150 && max(m, e) >= 80) return 'B';
	return 'C';
	
}

int main()
{
	int n;
	while(cin >> n, n)
	{
		while(n--)
		{
			int pm, pe, pj; cin >> pm >> pe >> pj;
			cout << grade(pm, pe, pj) << endl;
		}
	}
	return 0;
}
