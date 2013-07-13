/* aoj header */
#include <vector>

char rep[256] = {};

void init()
{
	rep['('] = ')';
	rep[')'] = '(';
	rep['{'] = '}';
	rep['}'] = '{';
	rep['['] = ']';
	rep[']'] = '[';
}

void rev(string::iterator begin, string::iterator end)
{
	reverse(begin, end);
	for(string::iterator it = begin; it != end; ++it)
		*it = rep[*it];
}

int main()
{
	init();
	string input, a, b;
	cin >> input;
	int p = input.find("iwi");
	a = input.substr(0, p);
	b = input.substr(p+3);
	rev(b.begin(), b.end());

	int m = a.length(), n = b.length();
	vector<vector<int> > dp(m + 1, vector<int>(n + 1));
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
		{
			dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			if(a[i] == b[j])
				dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
		}
	cout << dp[m][n] * 2 + 3 << endl;
	return 0;
}
