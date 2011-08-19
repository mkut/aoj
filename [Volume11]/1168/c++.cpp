#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class solver
{
	vector<string> blocks;
	vector<int> left, right, weight;
	vector<double> center;
	vector<vector<int> > upper;
	vector<char> ans;
	
public:
	solver(vector<string> vs)
	{
		blocks = vs;
	}
	
	vector<int> lnk(int X, int Y, char c, int id, int k)
	{
		const int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
		if(blocks[X][Y] == '.')
			return vector<int>();
		
		vector<int> ret;
		if(blocks[X][Y] == c)
		{
			blocks[X][Y] = '.';
			if(X+1 < blocks.size() && blocks[X+1][Y] != '.' && blocks[X+1][Y] != c || c == '_')
			{
				left[id] = min(left[id], Y-1);
				right[id] = max(right[id], Y);
			}
			center[id] = (center[id]*weight[id] + Y-0.5) / (weight[id]+1);
			weight[id] = weight[id] + 1;
			for(int k = 0; k < 4; k++)
			{
				vector<int> tmp = lnk(X+dx[k], Y+dy[k], c, id, k);
				for(int i = 0; i < tmp.size(); i++)
					ret.push_back(tmp[i]);
			}
		}
		else if(k==0)
		{
			int upid = unlnk(X, Y);
			ret.push_back(upid);
			center[id] = (center[id]*weight[id] + center[upid]*weight[upid]) / (weight[id]+weight[upid]);
			weight[id] = weight[id] + weight[upid];
		}
		return ret;
	}

	int unlnk(int X, int Y)
	{
		int id = left.size();
		left.push_back(Y-1);
		right.push_back(Y);
		center.push_back(0);
		weight.push_back(0);
		ans.push_back(1);
		upper.push_back(vector<int>());
		vector<int> vi = lnk(X, Y, blocks[X][Y], id, 0);
		upper[id] = vi;
		return id;
	}
	
	bool solve()
	{
		unlnk(blocks.size()-2, 1);
		bool ans = true;
		for(int i = 1; i < left.size(); i++)
		{
			ans &= (left[i] < center[i] ? 1 : 0);
			ans &= (center[i] < right[i] ? 1 : 0);
		}
		
		return ans;
	}
};

int main()
{
	int w, h;
	while(cin >> w >> h, w)
	{
		vector<string> blocks(h+3);
		blocks[0] = "."; blocks[h+1] = "."; blocks[h+2] = ".";
		for(int i = 1; i <= w; i++)
		{
			blocks[0] += "."; blocks[h+1] += "_"; blocks[h+2] += ".";
		}
		blocks[0] += "."; blocks[h+1] += "."; blocks[h+2] += ".";
		for(int i = 1; i <= h; i++)
		{
			string tmp; cin >> tmp;
			blocks[i] = "." + tmp + ".";
		}
		
		//for(int i = 0; i < blocks.size(); i++)
		//	cout << blocks[i] << endl;
		
		solver prob(blocks);
		cout << (prob.solve() ? "STABLE" : "UNSTABLE") << endl;
	}
	
	return 0;
}
