#include <milib/template/aoj>

//tuple key(int a, int b);

class solver
{
private:
	int N;
	string message, ans;
	vector<key> vk;
public:
	//>>[solver
	N
	message
	vk[N]:key
	//>>]
	//<<[solver
	ans
	//<<]
	void solve()
	{
		ans = message;
		for(int i = N-1; i >= 0; i--)
		{
			int a = vk[i].a - 1;
			int b = vk[i].b - 1;
			char tmp = ans[a];
			ans[a] = ans[b];
			ans[b] = tmp;
			ans[a] = add(ans[a], abs(a-b));
			ans[b] = add(ans[b], abs(a-b));
		}
	}
	char add(char c, int x) { return 'a' + (c - 'a' + x) % 26; }
};

int main()
{
	solver prob;
	while(cin >> prob)
	{
		prob.solve();
		cout << prob;
	}
	return 0;
}
