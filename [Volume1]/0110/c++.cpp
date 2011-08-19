#include <iostream>
#include <vector>
using namespace std;

struct Integer
{
	vector<int> vi;
	Integer(string s)
	{
		for(int i = s.length()-1; i >= 0; i--)
		{
			vi.push_back(s[i]-'0');
		}
	}
	Integer(vector<int> VI)
	{
		vi = VI;
	}
	
	Integer operator+(const Integer& b) const
	{
		vector<int> r;
		for(int i = 0; i < max(vi.size(), b.vi.size()); i++)
		{
			int v = 0;
			if(i < vi.size())
				v += vi[i];
			if(i < b.vi.size())
				v += b.vi[i];
			r.push_back(v);
		}
		for(int i = 0; i < r.size(); i++)
		{
			if(r[i] >= 10)
			{
				r[i] -= 10;
				if(i != r.size()-1)
					r[i+1]++;
				else
				{
					r.push_back(1);
					break;
				}
			}
		}
		return Integer(r);
	}
	
	bool operator==(const Integer& b) const
	{
		if(vi.size() != b.vi.size())
			return false;
		for(int i = 0; i < vi.size(); i++)
			if(vi[i] != b.vi[i])
				return false;
		return true;
	}
	
	friend ostream& operator<<(ostream& os, const Integer& itg)
	{
		for(int i = itg.vi.size()-1; i >= 0; i--)
			os << itg.vi[i];
		return os;
	}
};

int main()
{
	string input;
	while(cin >> input)
	{
		bool finished = false;
		for(int ans = 0; ans < 10; ans++)
		{
			string tmp = input;
			for(int i = 0; i < tmp.size(); i++)
				if(tmp[i] == 'X')
					tmp[i] = ans + '0';
			
			Integer A = Integer(tmp.substr(0, tmp.find("+")));
			Integer B = Integer(tmp.substr(tmp.find("+")+1, tmp.find("=")-tmp.find("+")-1));
			Integer C = Integer(tmp.substr(tmp.find("=")+1));
			if(A + B == C)
			{
				cout << ans << endl;
				finished = true;
				break;
			}
		}
		if(!finished)
			cout << "NA" << endl;
	}
	return 0;
}
