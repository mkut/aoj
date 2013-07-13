#include <iostream>
#include <algorithm>
#include <map>
//#include <set>
#include <vector>
using namespace std;

typedef pair<int,int> Pos;
typedef pair<Pos,Pos> State;

int f(State s)
{
	return s.first.first + s.first.second*52 + s.second.first*52*52 + s.second.second*52*52*52;
}

int main()
{
	int W, H;
	while(cin >> W >> H, W != 0)
	{
		vector<string> mapL(H+2), mapR(H+2);
		for(int i = 1; i <= H; i++)
		{
			string tmp;
			cin >> tmp;
			mapL[i] = "#" + tmp + "#";
			cin >> tmp;
			mapR[i] = "#" + tmp + "#";
		}
		mapL[0] = "####################################################";
		mapL[H+1] = "####################################################";
		mapR[0] = "####################################################";
		mapR[H+1] = "####################################################";
		
		State start, goal;
		for(int i = 1; i <= H; i++)
		{
			for(int j = 1; j <= W; j++)
			{
				if(mapL[i][j] == 'L')
					start.first = Pos(i,j);
				if(mapL[i][j] == '%')
					goal.first = Pos(i,j);
				if(mapR[i][j] == 'R')
					start.second = Pos(i,j);
				if(mapR[i][j] == '%')
					goal.second = Pos(i,j);
			}
		}
		
		//set<State> memo;
		bool* memo = new bool[52*52*52*52];
		vector<State> prev;
		//memo.insert(start);
		memo[f(start)] = true;
		prev.push_back(start);
		bool yes = false;
		while(!prev.empty())
		{
			vector<State> next;
			for(vector<State>::iterator it = prev.begin(); it != prev.end(); ++it)
			{
				//printf("(%d,%d), (%d,%d)\n", it->first.first, it->first.second, it->second.first, it->second.second);
				if(*it == goal)
				{
					yes = true;
					break;
				}
				if(it->first == goal.first || it->second == goal.second)
					continue;
				const int dfirst[] = {1,-1,0,0};
				const int dsecond[] = {0,0,1,-1};
				for(int i = 0; i < 4; i++)
				{
					Pos nextL(it->first.first + dfirst[i], it->first.second + dsecond[i]);
					Pos nextR(it->second.first + dfirst[i], it->second.second - dsecond[i]);
					if(mapL[nextL.first][nextL.second] == '#')
						nextL = it->first;
					if(mapR[nextR.first][nextR.second] == '#')
						nextR = it->second;
					State nextState(nextL, nextR);
					//if(memo.insert(nextState).second)
					//cout << nextState.first.first << "," << nextState.first.second << "," << nextState.second.first << "," << nextState.second.second << endl;
					if(!memo[f(nextState)])
					{
						memo[f(nextState)] = true;
						next.push_back(nextState);
					}
				}
			}
			if(yes)
				break;
			
			prev = next;
		}
		cout << (yes ? "Yes" : "No") << endl;
		
		delete [] memo;
	}
	return 0;
}
