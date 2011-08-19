#include <iostream>
#include <map>
#include <vector>
using namespace std;

class solver
{
  private:
	map<int, vector<int> > rail;
	int goal;
	
  public:
	solver(map<int, vector<int> > rail, int goal)
	{
		this->rail = rail;
		this->goal = goal;
	}
	
	bool solve(map<int, vector<int> > path, int remain)
	{
		while(remain--)
		{
			map<int, vector<int> > nextpath;
			for(map<int, vector<int> >::iterator it = path.begin(); it != path.end(); it++)
			{
				for(vector<int>::iterator vit = it->second.begin(); vit != it->second.end(); vit++)
				{
					if(nextpath.count(*vit) > 0) nextpath[*vit] = rail[*vit];
					else
					{
						nextpath[*vit] = rail[*vit];
						for(vector<int>::iterator tmpit = nextpath[*vit].begin(); tmpit != nextpath[*vit].end(); tmpit++)
						{
							if(*tmpit == it->first)
							{
								nextpath[*vit].erase(tmpit);
								break;
							}
						}
					}
				}
			}
			path = nextpath;
		}
		
		
		return path.count(goal) != 0;
	}
};

int main()
{
	int N, M, Z;
	while(cin >> N >> M >> Z, N != 0)
	{
		map<int, vector<int> > rail;
		while(M--)
		{
			int x, y;
			cin >> x >> y;
			rail[x].push_back(y);
			rail[y].push_back(x);
		}
		
		solver prob(rail, N);
		
		map<int, vector<int> > start;
		start[1] = rail[1];
		cout << (prob.solve(start, Z) ? "yes" : "no") << endl;
	}
	return 0;
}