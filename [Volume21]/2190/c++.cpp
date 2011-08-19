#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

class solver
{
	vector<int> stairs, melody;
public:
	solver(vector<int>& Stairs, vector<int>& Melody) : stairs(Stairs), melody(Melody) {}
	bool solve(int pos, int step)
	{
		if(step < 0)
			return pos == 0;
		if(pos <= 0 || pos >= stairs.size())
			return false;
		
		if(stairs[pos] == melody[step])
			return solve(pos-1, step-1);
		if((stairs[pos] + 1)% 12 == melody[step])
			return solve(pos-2, step-1);
		if((stairs[pos] + 11)% 12 == melody[step])
			return solve(pos+1, step-1);
		return false;
	}
	bool solve()
	{
		return solve(stairs.size() - 2, melody.size() - 1) || solve(stairs.size() - 3, melody.size() - 1);
	}
};

int main()
{
	map<string,int> sound;
	sound["A"] = 0;
	sound["A#"]= 1;
	sound["B"] = 2;
	sound["C"] = 3;
	sound["C#"]= 4;
	sound["D"] = 5;
	sound["D#"]= 6;
	sound["E"] = 7;
	sound["F"] = 8;
	sound["F#"]= 9;
	sound["G"] =10;
	sound["G#"]=11;
	
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> stairs(n+2), melody(m);
		
		for(int i = 1; i <= n; i++)
		{
			string tmp; cin >> tmp;
			stairs[i] = sound[tmp];
		}
		for(int i = 0; i < m; i++)
		{
			string tmp; cin >> tmp;
			melody[i] = sound[tmp];
		}
		
		solver prob(stairs, melody);
		bool ans = prob.solve();
		cout << (ans ? "Yes" : "No") << endl;
	}
	return 0;
}
