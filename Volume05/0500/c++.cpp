#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int A = 0, B = 0;
		for(int i = 0; i < n; i++)
		{
			int ta, tb; cin >> ta >> tb;
			if(ta > tb) A += ta+tb;
			else if(tb > ta) B += ta+tb;
			else {A += ta; B +=tb;}
		}
		cout << A << " " << B << endl;
	}
	return 0;
}