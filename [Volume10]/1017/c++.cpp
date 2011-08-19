#include <iostream>
#include <vector>
using namespace std;

vector<int> shuffle(vector<int> deck, int c)
{
	vector<int> r;
	vector<int>::iterator it1 = deck.begin(), it2 = deck.begin() + deck.size()/2;
	for(;;)
	{
		if(r.size() == deck.size()) break;
		if(it2 + c < deck.end()) {r.insert(r.end(), it2, it2+c); it2+=c;}
		else {r.insert(r.end(), it2, deck.end()); it2=deck.end();}
		if(it1 + c < deck.begin() + deck.size()/2) {r.insert(r.end(), it1, it1+c); it1+=c;}
		else {r.insert(r.end(), it1, deck.begin() + deck.size()/2); it1=deck.begin() + deck.size()/2;}
	}
	return r;
}

int main()
{
	int n, r;
	while(cin >> n >> r)
	{
		vector<int> deck(n);
		for(int i = 0; i < n; i++) deck[i] = i;
		for(int i = 0; i < r; i++)
		{
			int c; cin >> c;
			deck = shuffle(deck, c);
		}
		cout << deck[deck.size()-1] << endl;
	}
	return 0;
}