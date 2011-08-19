#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int,int> Point;
typedef vector<Point> Snake;

bool linked(Point a, Point b)
{
	const int dx[] = {0,1,-1,1,-1,0};
	const int dy[] = {-1,-1,0,0,1,1};
	for(int i = 0; i < 6; i++)
		if(a.first == b.first + dx[i] && a.second == b.second + dy[i])
			return true;
	return false;
}

bool movable(const Snake& sn, int pos, const Point& dir, vector<Point> blocks)
{
	if(count(blocks.begin(), blocks.end(), dir) == 1)
		return false;
	bool prev = pos == 0, next = pos == sn.size()-1;
	for(int i = 0; i < sn.size(); i++)
	{
		if(i == pos)
			continue;
		if(linked(dir, sn[i]))
		{
			if(i == pos-1)
				prev = true;
			else if(i == pos+1)
				next = true;
			else
				return false;
		}
	}
	return prev && next;
}

vector<Snake> next_snakes(Snake sn, int pos, const vector<Point>& blocks)
{
	vector<Snake> res;
	for(int i = pos; i < sn.size(); i++)
	{
		const int dx[] = {0,1,-1,1,-1,0};
		const int dy[] = {-1,-1,0,0,1,1};
		for(int k = 0; k < 6; k++)
		{
			if(movable(sn, i, Point(sn[i].first + dx[k], sn[i].second + dy[k]), blocks))
			{
				Snake next_snake = sn;
				next_snake[i] = Point(sn[i].first + dx[k], sn[i].second + dy[k]);
				vector<Snake> tmp = next_snakes(next_snake, i+2, blocks);
				res.insert(res.end(), tmp.begin(), tmp.end());
			}
		}
	}
	res.push_back(sn);
	return res;
}

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		Snake sn;
		for(int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			sn.push_back(Point(x,y));
		}
		vector<Point> blocks;
		int m; cin >> m;
		for(int i =0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			blocks.push_back(Point(x,y));
		}
		Point goal;
		for(int i =0; i < 1; i++)
		{
			int x, y;
			cin >> x >> y;
			goal = Point(x,y);
		}
		
		vector<Snake> prev;
		vector<Snake> done;
		prev.push_back(sn);
		done.push_back(sn);
		bool finished = false;
		for(int i = 0; !finished; i++)
		{
			//cout << i << endl;
			vector<Snake> next;
			for(vector<Snake>::iterator it = prev.begin(); it != prev.end(); ++it)
			{
				//cout << (*it)[0].first << "," << (*it)[0].second << endl;
				if((*it)[0] == goal)
				{
					//cout << i << endl;
					finished = true;
					break;
				}
				vector<Snake> snakes = next_snakes(*it, 0, blocks);
				for(int j = 0; j < snakes.size(); j++)
					if(count(done.begin(), done.end(), snakes[j]) == 0)
					{
						next.push_back(snakes[j]);
						done.push_back(snakes[j]);
					}
			}
			cout << next.size() << endl;
			prev = next;
		}
	}
	return 0;
}
