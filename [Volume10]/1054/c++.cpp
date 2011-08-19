#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef pair<int,int> Point;
typedef pair<Point,Point> Button;

class Page
{
public:
	string name;
	vector<pair<Button,string> > buttons;
	
	Page(string Name)
	{
		name = Name;
	}
	
	string click(Point p)
	{
		for(int i = 0; i < buttons.size(); i++)
		{
			if(p.first < buttons[i].first.first.first) continue;
			if(p.first > buttons[i].first.second.first) continue;
			if(p.second < buttons[i].first.first.second) continue;
			if(p.second > buttons[i].first.second.second) continue;
			return buttons[i].second;
		}
		return "";
	}
};

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int W, H;
		cin >> W >> H;
		map<string,Page*> pages;
		vector<Page*> history;
		for(int i = 0; i < n; i++)
		{
			string name;
			int num;
			cin >> name >> num;
			pages[name] = new Page(name);
			for(int j = 0; j < num; j++)
			{
				int x1, y1, x2, y2;
				string namae;
				cin >> x1 >> y1 >> x2 >> y2 >> namae;
				pages[name]->buttons.push_back(pair<Button,string>(Button(Point(x1,y1),Point(x2,y2)),namae));
			}
			if(history.size() == 0)
				history.push_back(pages[name]);
		}
		
		int m; cin >> m;
		vector<Page*>::iterator it = history.begin();
		
		for(int i = 0; i < m; i++)
		{
			string str; cin >> str;
			if(str == "click")
			{
				int x, y;
				cin >> x >> y;
				string next = (*it)->click(Point(x,y));
				if(pages.count(next))
				{
					history.erase(it+1, history.end());
					it = history.insert(history.end(), pages[next]);
				}
			}
			else if(str == "back")
			{
				if(it != history.begin())
					--it;
			}
			else if(str == "forward")
			{
				if(it+1 != history.end())
					++it;
			}
			else if(str == "show")
			{
				cout << (*it)->name << endl;
			}
			else
			{
				//cerr << "err" << endl;
			}
		}
	}
	return 0;
}
