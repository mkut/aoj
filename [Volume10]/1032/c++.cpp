#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Lecture
{
	int val;
	int req;
	Lecture(int val, int req)
	{
		this->val = val;
		this->req = req;
	}
};

class solver
{
  private:
	vector<Lecture> lecs;
	
  public:
	solver(vector<Lecture> lecs)
	{
		this->lecs = lecs;
	}
	
	int solve(int sum)
	{
		for(int i = 0; i <= lecs.size(); i++)
		{
			if(_solve(i, sum, 0, 0)) return i;
		}
		return -1;
	}
	
	bool _solve(int rem_num, int rem_sum, int pos, int selected)
	{
		if(rem_sum <= 0 && check_tree(selected)) return true;
		if(rem_num == 0) return false;
		
		for(int i = pos; i < lecs.size(); i++)
		{
			if(_solve(rem_num - 1, rem_sum - lecs[i].val, i+1, selected | 1<<i)) return true;
		}
		return false;
	}
	
	bool check_tree(int selected)
	{
		for(int i = 0; i < lecs.size(); i++)
		{
			if(selected >> i & 1)
			{
				if((selected & lecs[i].req) != lecs[i].req) return false;
			}
		}
		//cout << hex << setw(4) << setfill('0') << selected << "," <<dec;
		return true;
	}
};

int main()
{
	int n, U;
	while(cin >> n >> U, n != 0)
	{
		vector<Lecture> lecs;
		for(int i = 0; i < n; i++)
		{
			int c, k, r = 0;
			cin >> c >> k;
			for(int j = 0; j < k; j++)
			{
				int tmp; cin >> tmp;
				r |= 1 << tmp;
			}
			lecs.push_back(Lecture(c, r));
		}
		
		solver prob(lecs);
		
		cout << prob.solve(U) << endl;
	}
	return 0;
}