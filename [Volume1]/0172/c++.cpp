#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <vector>
#include <sstream>
using namespace std;

struct base_state
{
	int room;
	bitset<16> light;
	
	base_state()
	{
	}
	base_state(int Room, bitset<16> Light)
	{
		room = Room;
		light = Light;
	}
	
	bool operator<(const base_state& b) const
	{
		return room < b.room || room == b.room && light.to_ulong() < b.light.to_ulong();
	}
};

struct state
{
	base_state bs;
	state* prev;
	vector<state*> next;
	
	state(base_state BS, state* Prev)
	{
		bs = BS;
		prev = Prev;
	}
	~state()
	{
		for(int i = 0; i < next.size(); i++)
			delete next[i];
	}
	
	state* addNext(base_state BS)
	{
		next.push_back(new state(BS, this));
		return next.back();
	}
};

int main()
{
	int n, m;
	while(cin >> n >> m, n != 0)
	{
		vector<vector<int> > path(n+1);
		vector<vector<int> > lswitch(n+1);
		for(int i = 0; i < m; i++)
		{
			int a, b; cin >> a >> b;
			path[a].push_back(b);
			path[b].push_back(a);
		}
		bitset<16> light;
		for(int i = 1; i <= n; i++)
		{
			int l; cin >> l;
			light[i] = (l == 1 ? true : false);
		}
		for(int i = 1; i <= n; i++)
		{
			int num; cin >> num;
			lswitch[i] = vector<int>(num);
			for(int j = 0; j < num; j++)
				cin >> lswitch[i][j];
			sort(lswitch[i].begin(), lswitch[i].end());
		}
		state* root = new state(base_state(1, light), NULL);
		
		bool escape = false, finished = false;
		vector<state*> prev;
		prev.push_back(root);
		set<base_state> done;
		vector<string> method;
		while(!prev.empty())
		{
			vector<state*> next;
			for(vector<state*>::iterator it = prev.begin(); it != prev.end(); ++it)
			{
				//cout << (*it)->bs.room << ":" << hex << (*it)->bs.light.to_ulong() << endl;
				if((*it)->bs.room == n)
				{
					escape = true;
					if((*it)->bs.light.count() == 1)
					{
						state* st = *it;
						int count = 0;
						while(st->prev != NULL)
						{
							ostringstream oss;
							count++;
							if(st->bs.room != st->prev->bs.room)
								oss << "Move to room " << st->bs.room << ".";
							else
								for(int i = 1; i <= n; i++)
									if(st->bs.light[i] != st->prev->bs.light[i])
										oss << "Switch " << (st->bs.light[i] ? "on" : "off") << " room " << i << ".";
							st = st->prev;
							method.push_back(oss.str());
						}
						ostringstream oss;
						oss << "You can go home in " << count << " steps.";
						method.push_back(oss.str());
						finished = true;
						break;
					}
				}
				
				//move
				for(int i = 0; i < path[(*it)->bs.room].size(); i++)
				{
					if((*it)->bs.light[path[(*it)->bs.room][i]])
					{
						state* nstate = (*it)->addNext(base_state(path[(*it)->bs.room][i], (*it)->bs.light));
						
						if(done.count(nstate->bs) == 0)
						{
							done.insert(done.begin(), nstate->bs);
							next.push_back(nstate);
						}
					}
				}
				
				//switch
				for(int i = 0; i < lswitch[(*it)->bs.room].size(); i++)
				{
					if((*it)->bs.room != lswitch[(*it)->bs.room][i])
					{
						state* nstate = (*it)->addNext(base_state((*it)->bs.room, (*it)->bs.light ^ bitset<16>((1<<lswitch[(*it)->bs.room][i]))));
						if(done.count(nstate->bs) == 0)
						{
							done.insert(done.begin(), nstate->bs);
							next.push_back(nstate);
						}
					}
				}
				
			}
			if(finished)
				break;
			
			prev = next;
		}
		if(!escape)
			cout << "Help me!" << endl;
		else if(!finished)
			cout << "You can not switch off all lights." << endl;
		else
		{
			for(int i = method.size()-1 ; i >= 0; i--)
				cout << method[i] << endl;
		}
		delete root;
	}
	return 0;
}
