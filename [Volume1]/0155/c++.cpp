#include <iostream>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

typedef pair<int,int> point;
typedef pair<int,int> edge;

inline double size_v(double x, double y)
{
	return sqrt(x * x + y * y);
}

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		map<int, point> building;
		map<edge, double> distance;
		for(int i = 0; i < n; i++)
		{
			int b, x, y;
			cin >> b >> x >> y;
			building[b] = point(x,y);
		}
		
		for(map<int, point>::iterator it1 = building.begin(); it1 != building.end(); it1++)
		{
			for(map<int, point>::iterator it2 = building.begin(); it2 != building.end(); it2++)
			{
				distance[edge(it1->first, it2->first)] = 1e8;
				distance[edge(it2->first, it1->first)] = 1e8;
			}
		}
		
		for(map<int, point>::iterator it = building.begin(); it != building.end(); it++)
		{
			for(map<int, point>::iterator it2 = it; it2 != building.end(); it2++)
			{
				if(size_v(it->second.first - it2->second.first, it->second.second - it2->second.second) <= 50)
				{
					distance[edge(it->first, it2->first)] = it == it2 ? 0 : size_v(it->second.first - it2->second.first, it->second.second - it2->second.second);
					distance[edge(it2->first, it->first)] = it == it2 ? 0 : size_v(it->second.first - it2->second.first, it->second.second - it2->second.second);
				}
			}
		}
		
		for(map<int, point>::iterator it = building.begin(); it != building.end(); it++)
		{
			for(map<int, point>::iterator it1 = building.begin(); it1 != building.end(); it1++)
			{
				for(map<int, point>::iterator it2 = building.begin(); it2 != building.end(); it2++)
				{
					distance[edge(it1->first, it2->first)] = min(distance[edge(it1->first, it2->first)], distance[edge(it1->first, it->first)] + distance[edge(it->first, it2->first)]);
				}
			}
		}
		
		int m;
		cin >> m;
		for(int i = 0; i < m; i++)
		{
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			if(distance[edge(tmp1, tmp2)] == 1e8) cout << "NA" << endl;
			else
			{
				while(tmp1 != tmp2)
				{
					cout << tmp1 << " ";
					double _min = 1e8;
					int i_min;
					for(map<int, point>::iterator it = building.begin(); it != building.end(); it++)
					{
						if(tmp1 == it->first) continue;
						if(distance[edge(tmp1, tmp2)] +1e-4 >= distance[edge(tmp1, it->first)] + distance[edge(it->first, tmp2)])
						{
							if(distance[edge(tmp1, it->first)] < _min)
							{
								_min = distance[edge(tmp1, it->first)];
								i_min = it->first;
							}
						}
					}
					tmp1 = i_min;
				}
				cout << tmp2 <<endl;
			}
		}
	}
	
	return 0;
}