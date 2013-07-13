#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int order_num = 0;
struct order
{
	string dealer;
	int price, id;
	order(string dealer, int price) : dealer(dealer), price(price), id(order_num++) {}
};
bool sell_order(const order& a, const order& b)
{
	return a.price > b.price || a.price == b.price && a.id < b.id ;
}
bool buy_order(const order& a, const order& b)
{
	if(a.price > 0) return false;
	if(b.price > 0) return true;
	return a.price > b.price || a.price == b.price && a.id < b.id ;
}

struct good_state
{
	int count, sum, high, low;
	good_state() : count(0), sum(0), high(0), low(100000) {}
};

struct dealer_state
{
	int buy, sell;
	dealer_state() : buy(0), sell(0) {}
};

class solver
{
	map<string, vector<order> > queue_table;
	map<string, good_state> good_table;
	map<string, dealer_state> dealer_table;
public:
	solver() {}
	void trade(string good, string buyer, string seller, int price)
	{
		good_table[good].count++;
		good_table[good].high = max(good_table[good].high, price);
		good_table[good].low = min(good_table[good].low, price);
		good_table[good].sum += price;
		dealer_table[buyer].buy += price;
		dealer_table[seller].sell += price;
	}
	void sell(string dealer, string good, int price)
	{
		dealer_table[dealer];
		vector<order>& table = queue_table[good];
		sort(table.begin(), table.end(), price < 0 ? sell_order : buy_order);
		bool traded = false;
		for(int i = 0; i < table.size(); i++)
		{
			if(table[i].price * price > 0 || table[i].price + price < 0) break;
			if(table[i].dealer != dealer)
			{
				trade(good, price < 0 ? table[i].dealer : dealer, price < 0 ? dealer : table[i].dealer, (abs(table[i].price) + abs(price))/2);
				table.erase(table.begin() + i);
				traded = true;
				break;
			}
		}
		if(!traded)
		{
			table.push_back(order(dealer, price));
		}
	}
	void print()
	{
		for(map<string, good_state >::iterator it = good_table.begin(); it != good_table.end(); ++it)
			cout << it->first << " " << it->second.low << " " << it->second.sum / it->second.count << " " << it->second.high << endl;
		cout << "--" << endl;
		for(map<string, dealer_state >::iterator it = dealer_table.begin(); it != dealer_table.end(); ++it)
			cout << it->first << " " << it->second.buy << " " << it->second.sell << endl;
		cout << "----------" << endl;
	}
};

int main()
{
	int n;
	while(cin >> n, n)
	{
		solver prob;
		while(n--)
		{
			string dealer, sellbuy, good; int price; cin >> dealer >> sellbuy >> good >> price;
			prob.sell(dealer, good, sellbuy == "SELL" ? -price : price);
		}
		prob.print();
	}
	return 0;
}
