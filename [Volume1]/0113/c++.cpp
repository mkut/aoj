#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int p, q;
	while(cin >> p >> q)
	{
		int begin = p;
		vector<int> amari;
		vector<int> sho;
		do
		{
			amari.push_back(p);
			p *= 10;
			cout << p/q;
			p %= q;
		}
		while(count(amari.begin(), amari.end(), p) == 0 && p != 0);
		cout << endl;
		if(p != 0)
		{
			vector<int>::iterator it = amari.begin();
			vector<int>::iterator dot = find(amari.begin(), amari.end(), p);
			for(; it != dot; it++)
				cout << " ";
			for(; it != amari.end(); ++it)
				cout << "^";
			cout << endl;
		}
	}
}
