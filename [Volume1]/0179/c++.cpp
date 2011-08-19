#include <iostream>
#include <vector>
#include <string.h>
#include <bitset>
using namespace std;

class solver
{
  private:
	bitset<1200000> used;
	int size;
	
  public:
	solver()
	{
	}
	
	int solve(string str)
	{
		size = str.length();
		vector<int> lst;
		lst.push_back(hash(str));
		int i = 0;
		for(; lst.size() > 0; i++)
		{
			if(_solve(lst)) return i;
		}
		return -1;
	}
	
  private:
	bool _solve(vector<int>& lst)
	{
		vector<int> r;
		for(int i = 0; i < lst.size(); i++)
		{
			vector<int> next = change(lst[i]);
			if(next.size() == 0) return true;
			for(int j = 0; j < next.size(); j++)
			{
				if(!used[next[j]])
				{
					r.push_back(next[j]);
					used[next[j]] = true;
				}
			}
		}
		lst = r;
		return false;
	}
	
	vector<int> change(int hash)
	{
		vector<int> r;
		for(int i = 0; i < size-1; i++)
		{
			int left = hash >> i*2 & 3;
			int right = hash >> i*2+2 & 3;
			if(left != right)
			{
				r.push_back((hash | 15<<i*2) ^ 15-(3-left-right)*5 << i*2);
			}
		}
		return r;
	}
	
	int hash(string str)
	{
		int r = 0;
		for(int i=0; i < str.length(); i++)
		{
			r = r*4 + (str[i] == 'r' ? 0 : (str[i] == 'g' ? 1 : 2));
		}
		return r;
	}
};

int main()
{
	string input;
	while(cin >> input, input != "0")
	{
		solver prob;
		int ans = prob.solve(input);
		if(ans == -1) cout << "NA" << endl;
		else cout << ans << endl;
	}
	return 0;
}