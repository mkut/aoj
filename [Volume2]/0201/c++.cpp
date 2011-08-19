#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Item
{
	vector<Item*> recipe;
	int cost;
	bool checked;
	
	Item(int Cost)
	{
		cost = Cost;
		checked = true;
	}
	
	void addRecipe(vector<Item*> Recipe)
	{
		recipe = Recipe;
		checked = false;
	}
	
	int minimumCost()
	{
		if(!checked)
		{
			checked = true;
			int sum = 0;
			for(int j = 0; j < recipe.size(); j++)
			{
				if(recipe[j] == NULL)
					return cost;
				sum += recipe[j]->minimumCost();
			}
			cost = min(cost, sum);
		}
		return cost;
	}
};

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		map<string,Item*> materials;
		for(int i = 0; i < n; i++)
		{
			string name;
			int cost;
			cin >> name >> cost;
			materials[name] = new Item(cost);
		}
		
		int m;
		cin >> m;
		for(int i = 0; i < m; i++)
		{
			vector<Item*> recipe;
			string name;
			int num;
			cin >> name >> num;
			for(int j = 0; j < num; j++)
			{
				string matname;
				cin >> matname;
				recipe.push_back(materials[matname]);
			}
			if(materials[name] == NULL)
				materials[name] = new Item(100000000);
			materials[name]->addRecipe(recipe);
		}
		
		string item;
		cin >> item;
		cout << materials[item]->minimumCost() << endl;
		
		for(map<string,Item*>::iterator it = materials.begin(); it != materials.end(); it++)
			if(it->second != NULL)
				delete it->second;
	}
	return 0;
}
