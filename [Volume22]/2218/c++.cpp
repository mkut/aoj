#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	for(int N, No = 1; cin >> N; No++)
	{
		if(No > 1) cout << endl;
		int base[4][13] = {}, rate[9] = {};
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 13; j++)
				cin >> base[i][j];
		for(int i = 0; i < 9; i++)
			cin >> rate[i];
		
		for(int i = 0; i < N; i++)
		{
			string c[5];
			for(int i = 0; i < 5; i++)
				cin >> c[i];
			int n[13] = {}, s[4] = {};
			int point = 0;
			for(int i = 0; i < 5; i++)
			{
				int num, suit;
				switch(c[i][0])
				{
				case 'T': num = 9; break;
				case 'J': num = 10; break;
				case 'Q': num = 11; break;
				case 'K': num = 12; break;
				case 'A': num = 0; break;
				default: num = c[i][0] - '1'; break;
				}
				switch(c[i][1])
				{
				case 'S': suit = 0; break;
				case 'C': suit = 1; break;
				case 'H': suit = 2; break;
				case 'D': suit = 3; break;
				}
				n[num]++; s[suit]++;
				point += base[suit][num];
			}
			
			bool flush = false;
			for(int i = 0; i < 4; i++)
				if(s[i] == 5)
					flush = true;
			int straight = -1;
			for(int i = 0; i < 10; i++)
			{
				bool ok = true;
				for(int j = 0; j < 5; j++)
					if(n[(i+j)%13] != 1)
					{
						ok = false;
						break;
					}
				if(ok)
				{
					straight = i;
					break;
				}
			}
			sort(n, n+13);
			reverse(n, n+13);
			
			int ans = 0;
			// Loyal flush
			if(flush && straight == 9)
				ans = rate[8];
			
			// Straight flush
			else if(flush && straight != -1)
				ans = rate[7];
			
			// Four cards
			else if(n[0] == 4)
				ans = rate[6];
			
			// Full house
			else if(n[0] == 3 && n[1] == 2)
				ans = rate[5];
			
			// Flush
			else if(flush)
				ans = rate[4];
			
			// Straight
			else if(straight != -1)
				ans = rate[3];
			
			// Three cards
			else if(n[0] == 3)
				ans = rate[2];
			
			// Two Pairs
			else if(n[0] == 2 && n[1] == 2)
				ans = rate[1];
			
			// One Pair
			else if(n[0] == 2)
				ans = rate[0];
			
			ans *= point;
			cout << ans << endl;
		}
	}
	return 0;
}
