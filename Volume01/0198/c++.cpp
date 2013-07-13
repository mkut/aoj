#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct dice
{
	vector<int> rev;
	bool dir;
	
	dice(vector<int> vi) : rev(6), dir(false)
	{
		for(int i = 0; i < 6; i++)
			rev[vi[i]] = vi[5-i];
		
		for(int i = 0; i < 3; i++)
			if(vi[i] > rev[vi[i]])
				dir = !dir, vi[i] = rev[vi[i]];
		
		for(int i = 0; i < 3; i++)
			for(int j = i+1; j < 3; j++)
				if(vi[i] > vi[j])
					dir = !dir;
	}
	
	bool equalTo(const dice& a) const
	{
		return rev == a.rev && dir == a.dir;
	}
	
	void d()
	{
		for(int i = 0; i < 6; i++)
			cout << rev[i] << " ";
		cout << (dir ? "o" : "x") << endl;
	}
};

int main()
{
	int n;
	map<string,int> colorToId;
	colorToId["Cyan"] = 0; colorToId["Yellow"] = 1; colorToId["Red"] = 2;
	colorToId["Magenta"] = 3; colorToId["Green"] = 4; colorToId["Blue"] = 5;
	
	while(cin >> n, n)
	{
		vector<dice> unique;
		for(int i = 0; i < n; i++)
		{
			vector<int> vi(6);
			for(int j = 0; j < 6; j++)
			{
				string color; cin >> color;
				vi[j] = colorToId[color];
			}
			dice cur(vi);
			
			//cur.d();
			
			bool ok = true;
			for(int j = 0; j < unique.size(); j++)
			{
				if(unique[j].equalTo(cur))
				{
					ok = false;
					break;
				}
			}
			if(ok)
				unique.push_back(cur);
		}
		cout << n - unique.size() << endl;
	}
	return 0;
}
