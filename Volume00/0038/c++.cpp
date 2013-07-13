#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	char input[5][100];
	while(cin.getline(input[0], 100, ','))
	{
		for(int i = 1; i < 4; i++) cin.getline(input[i], 100, ',');
		cin.getline(input[4], 100, '\n');
		
		int card[14] = {};
		for(int i = 0; i < 5; i++) card[atoi(input[i])-1]++;
		card[13] = card[0];
		
		// 7.
		bool check7 = false;
		for(int i = 0; i < 13; i++)
		{
			if(card[i] == 4)
			{
				check7 = true;
				break;
			}
		}
		if(check7)
		{
			cout << "four card" << endl;
			continue;
		}
		
		// 6.
		int check6 = 0;
		for(int i = 0; i < 13; i++)
		{
			if(card[i] >=2)
			{
				check6 += card[i];
			}
		}
		if(check6 == 5)
		{
			cout << "full house" << endl;
			continue;
		}
		
		// 5.
		bool check5 = false;
		for(int i = 0; i < 10; i++)
		{
			if(card[i] == 1 && card[i+1] == 1 && card[i+2] == 1 && card[i+3] == 1 && card[i+4] == 1)
			{
				check5 = true;
			}
		}
		if(check5)
		{
			cout << "straight" << endl;
			continue;
		}
		
		// 4.
		bool check4 = false;
		for(int i = 0; i < 13; i++)
		{
			if(card[i] == 3)
			{
				check4 = true;
			}
		}
		if(check4)
		{
			cout << "three card" << endl;
			continue;
		}
		
		// 3.
		int check23 = 0;
		for(int i = 0; i < 13; i++)
		{
			if(card[i] == 2)
			{
				check23 += card[i];
			}
		}
		if(check23 == 4)
		{
			cout << "two pair" << endl;
			continue;
		}
		
		// 2.
		if(check23 == 2)
		{
			cout << "one pair" << endl;
			continue;
		}
		
		// 1.
		cout << "null" << endl;
	}
	return 0;
}