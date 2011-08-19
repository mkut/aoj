#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef pair<int,int> Point;
typedef pair<Point,int> State;
struct DPState
{
	State first;
	int second;
	
	DPState(State f, int s)
	{
		first = f;
		second = s;
	}
};

bool operator<(const DPState& a, const DPState& b)
{
	return a.second > b.second;
}

int main()
{
	int h, w;
	while(cin >> h >> w, h != 0)
	{
		vector<vector<int> > _map(h);
		for(int i = 0; i < h; i++)
		{
			_map[i] = vector<int>(w);
			for(int j = 0; j < w; j++)
				cin >> _map[i][j];
		}
		Point start, goal;
		int x, y;
		cin >> x >> y;
		start = Point(x,y);
		cin >> x >> y;
		goal = Point(x,y);
		
		priority_queue<DPState> Q;
		Q.push(DPState(State(start,1+2*010+3*0100),0));
		set<State> used;
		used.insert(State(start,1+2*010+3*0100));
		while(Q.size())
		{
			DPState top = Q.top();
			Q.pop();
			
			if(top.first.first == goal)
			{
				cout << top.second << endl;
				break;
			}
			if(top.first.first.first > 0)
			{
				Point nextPos = Point(top.first.first.first-1, top.first.first.second);
				int ue = top.first.second & 07, minami = (top.first.second & 070) >> 3, higashi = (top.first.second & 0700) >> 6;
				int nextDice = minami * 01 + (7-ue) * 010 + higashi * 0100;
				int nextCost = top.second + _map[nextPos.first][nextPos.second] * (7-(nextDice & 07));
				//cout << "^" << endl;
				//cout << ue << "," << minami << "," << higashi << endl;
				//cout << (nextDice & 07) << "," << ((nextDice & 070)>>3) << "," << ((nextDice & 0700)>>6) << endl;
				if(used.insert(State(nextPos, nextDice)).second)
					Q.push(DPState(State(nextPos, nextDice), nextCost));
			}
			if(top.first.first.first < h-1)
			{
				Point nextPos = Point(top.first.first.first+1, top.first.first.second);
				int ue = top.first.second & 07, minami = (top.first.second & 070) >> 3, higashi = (top.first.second & 0700) >> 6;
				int nextDice = (7-minami) * 01 + ue * 010 + higashi * 0100;
				int nextCost = top.second + _map[nextPos.first][nextPos.second] * (7-(nextDice & 07));
				//cout << "v" << endl;
				//cout << ue << "," << minami << "," << higashi << endl;
				//cout << (nextDice & 07) << "," << ((nextDice & 070)>>3) << "," << ((nextDice & 0700)>>6) << endl;
				if(used.insert(State(nextPos, nextDice)).second)
					Q.push(DPState(State(nextPos, nextDice), nextCost));
			}
			if(top.first.first.second > 0)
			{
				Point nextPos = Point(top.first.first.first, top.first.first.second-1);
				int ue = top.first.second & 07, minami = (top.first.second & 070) >> 3, higashi = (top.first.second & 0700) >> 6;
				int nextDice = higashi * 01 + minami * 010 + (7-ue) * 0100;
				int nextCost = top.second + _map[nextPos.first][nextPos.second] * (7-(nextDice & 07));
				//cout << "<" << endl;
				//cout << ue << "," << minami << "," << higashi << endl;
				//cout << (nextDice & 07) << "," << ((nextDice & 070)>>3) << "," << ((nextDice & 0700)>>6) << endl;
				if(used.insert(State(nextPos, nextDice)).second)
					Q.push(DPState(State(nextPos, nextDice), nextCost));
			}
			if(top.first.first.second < w-1)
			{
				Point nextPos = Point(top.first.first.first, top.first.first.second+1);
				int ue = top.first.second & 07, minami = (top.first.second & 070) >> 3, higashi = (top.first.second & 0700) >> 6;
				int nextDice = (7-higashi) * 01 + minami * 010 + ue * 0100;
				int nextCost = top.second + _map[nextPos.first][nextPos.second] * (7-(nextDice & 07));
				//cout << ">" << endl;
				//cout << ue << "," << minami << "," << higashi << endl;
				//cout << (nextDice & 07) << "," << ((nextDice & 070)>>3) << "," << ((nextDice & 0700)>>6) << endl;
				if(used.insert(State(nextPos, nextDice)).second)
					Q.push(DPState(State(nextPos, nextDice), nextCost));
			}
		}
	}
	
	return 0;
}
