#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool match(string a, string b)
{
	if(a.length() != b.length()) return false;
	for(int i = 0; i < a.length(); i++)
		if(a[i] != b[i] && a[i] != '?' && b[i] != '?')
			return false;
	return true;
}

int main()
{
	int n, m;
	while(cin >> n >> m, n+m)
	{
		vector<string> rule_type(n), rule_from(n), rule_to(n);
		for(int i = 0; i < n; i++)
			cin >> rule_type[i] >> rule_from[i] >> rule_to[i];
		
		vector<string> out_from, out_to, out_mes;
		for(int i = 0; i < m; i++)
		{
			string from, to, mes; cin >> from >> to >> mes;
			bool permit = false;
			for(int j = 0; j < n; j++)
				if(match(rule_from[j], from) && match(rule_to[j], to))
					permit = rule_type[j] == "permit";
			if(permit)
				out_from.push_back(from), out_to.push_back(to), out_mes.push_back(mes);
		}
		cout << out_from.size() << endl;
		for(int i = 0; i < out_from.size(); i++)
			cout << out_from[i] << " " << out_to[i] << " " << out_mes[i] << endl;
	}
	return 0;
}
