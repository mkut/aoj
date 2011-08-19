#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <stdlib.h>
using namespace std;

vector<string> split(string str, char delim)
{
	vector<string> ret;
	for(string::size_type pos = str.find(delim); pos != string::npos; pos = str.find(delim)){
		ret.push_back(str.substr(0, pos));
		str = str.substr(pos+1);
	}
	if(str.length() > 0){
		ret.push_back(str);
	}
	return ret;
}

struct Panel
{
	string name;
	int l, t, r, b;
	vector<Panel*> children;
	
	Panel(string name, int l, int t, int r, int b)
	{
		this->name = name;
		this->l = l;
		this->t = t;
		this->r = r;
		this->b = b;
	}
	
	void addChild(Panel* p)
	{
		children.push_back(p);
	}
	
	Panel* solve(int x, int y)
	{
		for(vector<Panel*>::iterator it = children.begin(); it != children.end(); it++)
		{
			if((*it)->l <= x && x <= (*it)->r && (*it)->t <= y && y <= (*it)->b)
			{
				return (*it)->solve(x, y);
			}
		}
		return this;
	}
};

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		string structure;
		cin >> structure;
		
		list<Panel> lst;
		stack<Panel*> stk;
		vector<string> parts = split(structure, '<');
		lst.push_back(Panel("OUT OF MAIN PANEL", 0, 0, 10000, 10000));
		stk.push(&lst.back());
		for(int i = 1; i < parts.size(); i++)
		{
			if(parts[i][0] != '/')
			{
				string name = parts[i].substr(0, parts[i].find('>'));
				vector<string> spos = split(parts[i].substr(parts[i].find('>')+1), ',');
				int pos[4];
				for(int i = 0; i < 4; i++) pos[i] = atoi(spos[i].c_str());
				lst.push_back(Panel(name, pos[0], pos[1], pos[2], pos[3]));
				stk.top()->addChild(&lst.back());
				stk.push(&lst.back());
			}
			else
			{
				stk.pop();
			}
		}
		
		for(int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			Panel* ans = lst.front().solve(x, y);
			cout << ans->name << " " << ans->children.size() << endl;
		}
	}
	return 0;
}