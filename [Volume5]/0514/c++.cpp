#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

template<class T>
string expand(const string& sep, const T& val)
{
	ostringstream oss;
	oss << val;
	return oss.str();
}

template<class T>
string expand(const string& sep, const vector<T>& vt)
{
//	assert(sep.length() > 0);
	
	string str = "";
	bool first = true;
	for(int i = 0; i < vt.size(); i++)
	{
		if(!first) str += sep[0];
		str += expand(sep.substr(1), vt[i]);
		first = false;
	}
	return str;
}

template<class T>
string operator+(const string& sep, const vector<T>& vt){ return expand(sep, vt); }

int main()
{
	int a, b, c, N;
	while(cin >> a >> b >> c, a != 0)
	{
		vector<int> ans(a+b+c);
		vector<int> ea, eb, ec;
		for(int i = 0; i < a+b+c; i++) ans[i] = 2;
		cin >> N;
		for(int i = 0; i < N; i++)
		{
			int A, B, C, R;
			cin >> A >> B >> C >> R;
			if(R == 1)
			{
				ans[A-1] = 1;
				ans[B-1] = 1;
				ans[C-1] = 1;
			}
			else
			{
				ea.push_back(A-1);
				eb.push_back(B-1);
				ec.push_back(C-1);
			}
		}
		for(int i = 0; i < ea.size(); i++)
		{
			if(ans[ea[i]] == 1 && ans[eb[i]] == 1) ans[ec[i]] = 0;
			else if(ans[eb[i]] == 1 && ans[ec[i]] == 1) ans[ea[i]] = 0;
			else if(ans[ec[i]] == 1 && ans[ea[i]] == 1) ans[eb[i]] = 0;
		}
		cout << "\n"+ans << endl;
	}
	return 0;
}