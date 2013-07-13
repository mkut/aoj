#include <iostream>
#include <vector>
#include <map>
using namespace std;

class solver
{
	map<pair<int,int>,int> memo;
	vector<int> cards;
public:
	solver(vector<int>& cards) : cards(cards) {}
	int solve() { return solve(0, cards.size()); }
	int solve(int a, int b)
	{
		if(b - a <= 2) return 0;
		pair<int, int> index = make_pair(a, b);
		if(memo.count(index))
			return memo[index];
		int ret = cards[a] * cards[a+1] * cards[a+2] * cards[b-1] + solve(a+2, b);
		for(int i = a + 4; i < b; i += 2)
			ret = min(ret, cards[a] * cards[i-1] * cards[i] * cards[b-1] + solve(a, i) + solve(i, b));
		//cout << a << "," << b << ":" << ret << endl;
		memo[index] = ret;
		return ret;
	}
};

int main()
{
	int n;
	cin >> n;
	vector<int> cards;
	for(int i = 0; i < 2*n; i++)
	{
		int tmp; cin >> tmp;
		cards.push_back(tmp);
	}
	
	solver prob(cards);
	cout << prob.solve() << endl;
	return 0;
}
