#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int,int> score;

bool cmp(score a, score b)
{
	return a.second > b.second || (a.second == b.second && a.first < b.first);
}

int main()
{
	int m;
	while(cin >> m, m != 0)
	{
		vector<score> scores;
		
		for(int i = 0; i < m; i++)
		{
			int number;
			cin >> number;
			
			int sum = 0;
			int mlt1 = 1, mlt2 = 1;
			for(int game = 0; game < 10; game++)
			{
				if(game == 9)
				{
					int tmp; cin >> tmp;
					if(tmp == 10)
					{
						sum += mlt1*10;
						cin >> tmp;
						sum += mlt2*tmp;
						cin >> tmp;
						sum += tmp;
					}
					else
					{
						int tmp2; cin >> tmp2;
						sum += mlt1*tmp + mlt2*tmp2;
						if(tmp + tmp2 == 10)
						{
							cin >> tmp;
							sum += tmp;
						}
					}
					break;
				}
				int tmp; cin >> tmp;
				if(tmp == 10)
				{
					sum += mlt1*10;
					mlt1 = mlt2+1;
					mlt2 = 2;
					continue;
				}
				int tmp2; cin >>tmp2;
				sum += mlt1*tmp +mlt2*tmp2;
				if(tmp + tmp2 == 10)
				{
					mlt1 = 2;
				}
				else
				{
					mlt1 = 1;
				}
				mlt2 = 1;
			}
			
			scores.push_back(score(number, sum));
		}
		
		sort(scores.begin(), scores.end(), cmp);
		for(int i = 0; i < scores.size(); i++)
		{
			cout << scores[i].first << " " << scores[i].second << endl;
		}
	}
	
	return 0;
}