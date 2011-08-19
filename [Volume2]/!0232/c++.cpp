#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <complex>
using namespace std;

struct state
{
	double plus, double minus;
	state() : plus(0), minus(0) {}
	state(double plus, double, minus) : plus(plus), minus(minus) {}
	friend state operator+(state a, double b) { return state(a.plus + max(0, b + a.minus), min(0, b + a.minus)); }
	
	static const state nan = state(0, 1);
}

struct event
{
	int go, money;
	event() : go(0), money(0) {}
	event(int go, int money) : go(go), money(money) {}
};

class solver
{
	vector<state> memo;
	vector<int> go;
	int Y;
	vector<event> events;
public:
	solver(vector<int>& go, int Y, vector<event>& events) : go(go), Y(Y), events(events), memo(Y, state::nan) {}
	complex<double> solve(int pos)
	{
		if(pos >= Y) return 0;
		if(memo[pos] != state::nan) return memo[pos];
		state ret;
		for(int i = 0; i < go.size(); i++)
			ret += complex<double>(solve_event(pos + go[i]).plus / go.size(), solve_event(pos + go[i]).minus / go.size());
		memo[pos] = ret;
		cout << pos << ":" << ret << endl;
		return ret;
	}
	complex<double> solve_event(int pos)
	{
		if(pos >= Y) return 0;
		int money = events[pos].money;
		pair<double, double> tmp = solve(pos + events[i].go);
		return solve(pos + events[pos].go) + complex<double>(max(0, money + tmp.plus), min(0, tmp.minus + money));
	}
};

int main()
{
	int X, Y, Z;
	while(cin >> X >> Y >> Z, X)
	{
		vector<int> go(X);
		for(int i = 0; i < X; i++)
			cin >> go[i];
		vector<event> events(Y);
		for(int i = 0; i < Z; i++)
		{
			int N, E, A; cin >> N >> E >> A;
			if(E == 1)
				events[N].go = A;
			else
				events[N].money = E == 2 ? A : -A;
		}
		solver prob(go, Y, events);
		cout << (int)prob.solve(0) << endl;
	}
	return 0;
}
