#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int count(vector<char> cards, int n)
{
	int sum = 0;
	int ace = 0;
	for(int i = 0; i < n; i++)
	{
		if(cards[i] == 'A')
			sum += 11, ace++;
		else if(cards[i] >= '2' && cards[i] <= '9')
			sum += cards[i] - '0';
		else
			sum += 10;
	}
	while(ace && (sum == 17 || sum > 21))
		sum -= 10, ace--;
	
	return sum;
}

int main()
{
	int N; cin >> N;
	while(N--)
	{
		vector<char> cards(10);
		for(int i = 0; i < 10; i++)
		{
			string str; cin >> str;
			cards[i] = str[0];
		}
		
		int n = 2;
		while(count(cards, n) <= 16)
			n++;
		
		int c = count(cards, n);
		if(c == 21 && n == 2)
			cout << "blackjack" << endl;
		else if(c > 21)
			cout << "bust" << endl;
		else
			cout << c << endl;
	}
	return 0;
}
