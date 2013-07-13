#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<string> Dice;

const int _rev[9] = {8,7,6,5,4,3,2,1,0};
const int _left[9]= {2,5,8,1,4,7,0,3,6};
const int _right[9]={6,3,0,7,4,1,8,5,2};

string arrange(string& s, const int arr[9])
{
	string ret;
	for(int i = 0; i < 9; i++) ret += s[arr[i]];
	return ret;
}

Dice rotateF(Dice d)
{
	Dice ret(6);
	ret[0] = d[4];
	ret[1] = arrange(d[1], _left); 
	ret[2] = arrange(d[5], _rev);
	ret[3] = arrange(d[3], _right);
	ret[4] = arrange(d[2], _rev);
	ret[5] = d[0];
	return ret;
}
Dice rotateB(Dice d) { return rotateF(rotateF(rotateF(d))); }
Dice rotateL(Dice d)
{
	Dice ret(6);
	ret[0] = arrange(d[0], _left);
	ret[1] = arrange(d[5], _left); 
	ret[2] = arrange(d[2], _right);
	ret[3] = arrange(d[4], _left);
	ret[4] = arrange(d[1], _left);
	ret[5] = arrange(d[3], _left);
	return ret;
}
Dice rotateR(Dice d) { return rotateL(rotateL(rotateL(d))); }

bool ok(string& s)
{
	return s[6] == '*' || s[7] == '*' || s[8] == '*';
}

int solve(Dice d, int rem)
{
	if(rem < 0) return 100;
	if(ok(d[0]) && ok(d[2])) return 0;
	
	int ret = 100;
	ret = min(ret, solve(rotateF(d), rem-1) + 1);
	ret = min(ret, solve(rotateB(d), rem-1) + 1);
	ret = min(ret, solve(rotateL(d), rem-1) + 1);
	ret = min(ret, solve(rotateR(d), rem-1) + 1);
	return ret;
}

int main()
{
	while(true)
	{
		Dice dice(6);
		for(int i = 0; i < 6; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				string tmp; cin >> tmp;
				dice[i] += tmp;
			}
		}
		if(dice[0][0] == '#') break;
		
		int ans = solve(dice, 3);
		cout << ans << endl;
	}
	
	return 0;
}
