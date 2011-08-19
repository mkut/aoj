#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void d(vector<int> vi)
{
	for(int i = 0; i < vi.size(); i++) cout << vi[i] << " ";
	cout << endl;
}

class solver
{
  private:
	vector<vector<int> > set;
	vector<int> U;
	
  public:
	solver(vector<vector<int> > _set, vector<int> _U)
	{
		set = _set;
		U = _U;
	}
	
	vector<int> solve(string str)
	{
		int pos = 0;
		vector<int> right, left;
		char ope;
		
		// right part section
		if(str[0] == ')')
		{
			int nest = 0;
			for(; pos < str.length(); pos++)
			{
				if(str[pos] == ')') nest++;
				else if(str[pos] == '(') nest--;
				if(nest == 0)
				{
					right = solve(str.substr(1, pos-1));
					pos++;
					break;
				}
			}
		}
		else
		{
			right = set[str[0]-'A'];
			pos++;
		}
		while(str[pos] == 'c')
		{
			right = cmp(right);
			pos++;
		}
		
		if(pos == str.length()) return right;
		
		// operator section
		ope = str[pos++];
		
		// left part section
		left = solve(str.substr(pos));
		
		// calculation
		if(ope == 'u') return uni(right, left);
		if(ope == 'i') return inter(right, left);
		if(ope == 'd') return dif(right, left);
		if(ope == 's') return sym(right, left);
		else return vector<int>();
	}
	
	vector<int> uni(vector<int> r, vector<int> l)
	{
		vector<int> res = r;
		for(int i = 0; i < l.size(); i++) res.push_back(l[i]);
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}
	vector<int> inter(vector<int> r, vector<int> l)
	{
		vector<int> res;
		for(int i = 0; i < U.size(); i++)
		{
			if(find(r.begin(), r.end(), U[i]) != r.end() && find(l.begin(), l.end(), U[i]) != l.end())
			{
				res.push_back(U[i]);
			}
		}
		return res;
	}
	vector<int> dif(vector<int> r, vector<int> l)
	{
		vector<int> res;
		for(int i = 0; i < l.size(); i++)
		{
			if(find(r.begin(), r.end(), l[i]) == r.end())
			{
				res.push_back(l[i]);
			}
		}
		return res;
	}
	vector<int> sym(vector<int> r, vector<int> l)
	{
		return uni(dif(r, l), dif(l, r));
	}
	vector<int> cmp(vector<int> set)
	{
		return dif(set, U);
	}
};

int main()
{
	char name;
	int num;
	while(cin >> name >> num)
	{
		vector<vector<int> > set(5);
		vector<int> U;
		while(name != 'R')
		{
			for(int i = 0; i < num; i++)
			{
				int tmp; cin >> tmp;
				set[name-'A'].push_back(tmp);
				U.push_back(tmp);
			}
			cin >> name >> num;
		}
		sort(U.begin(), U.end());
		U.erase(unique(U.begin(), U.end()), U.end());
		solver prob(set, U);
		
		string input;
		cin >> input;
		
		reverse(input.begin(), input.end());
		vector<int> ans = prob.solve(input);
		sort(ans.begin(), ans.end());
		bool first = true;
		if(ans.size() == 0) cout << "NULL";
		else
		{
			for(int i = 0; i < ans.size(); i++)
			{
				cout << (first ? "" : " ") << ans[i];
				first = false;
			}
		}
		cout << endl;
		
	}
	return 0;
}