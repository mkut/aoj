#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class solver
{
	int P, S, mhp;
	vector<vector<int> > memo;
	vector<int> damage, pots;
	vector<int> life;
public:
	solver(int p, int s, int HP, int MHP, vector<int> Damage, vector<int> Pots)
			: P(p), S(s), mhp(MHP), memo(1<<p, vector<int>(s+1, 100000000)), damage(Damage), pots(Pots), life(1<<p)
	{
		life[0] = HP;
		for(int i = 1; i < 1<<P; i++)
			for(int j = 0; j < P; j++)
				if(i >> j & 1)
					life[i] = life[i-(1<<j)] + pots[j];
	}
	
	bool _solve(vector<int>::iterator cur, int loss, int bitpot)
	{
		//cout << "[" << cur-damage.begin() << "]" << loss << "(" << bitpot << ")" << endl;
		if(loss >= memo[bitpot][cur-damage.begin()])
			return false;
		for(int i = cur-damage.begin(); i >= 0 && memo[bitpot][i] > loss; i--)
			memo[bitpot][i] = loss;
		if(cur == damage.end())
			return true;
		vector<int>::iterator next = lower_bound(damage.begin(), damage.end(), life[bitpot] - loss);
		if(cur != next)
			return _solve(next, loss, bitpot);
		else
		{
			for(int i = 0; i < P; i++)
				if(!(bitpot >> i & 1) && _solve(next, loss + max(0, life[bitpot] - loss - *(next-1) + pots[i] - mhp), bitpot + (1 << i)))
					return true;
			return false;
		}
	}
	bool solve(){ return _solve(damage.begin(), 0, 0); }
};

int main()
{
	int HP, MHP;
	while(cin >> HP >> MHP, HP)
	{
		int R, C; cin >> R >> C;
		vector<string> view(R);
		for(int i = 0; i < R; i++)
			cin >> view[i];
		vector<int> d_table(26);
		int T; cin >> T;
		for(int i = 0; i < T; i++)
		{
			char c; int d; cin >> c >> d;
			d_table[c-'A'] = d;
		}
		int S; cin >> S;
		string query = "";
		for(int i = 0; i < S; i++)
		{
			char c; int n; cin >> c >> n;
			query += string(n, c);
		}
		int P; cin >> P;
		vector<int> pots(P);
		for(int i = 0; i < P; i++)
			cin >> pots[i];
		
		vector<vector<int> > v_damage(R, vector<int>(C));
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				v_damage[i][j] = d_table[view[i][j]-'A'];
		
		vector<int> damage(query.size()+1);
		int x = 0, y = 0;
		for(int i = 0; i < query.size(); i++)
		{
			if(query[i] == 'U') x--;
			else if(query[i] == 'D') x++;
			else if(query[i] == 'L') y--;
			else if(query[i] == 'R') y++;
			damage[i+1] = damage[i] + v_damage[x][y];
		}
		
		solver prob(P, damage.size(), HP, MHP, damage, pots);
		
		bool ans = prob.solve();
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
