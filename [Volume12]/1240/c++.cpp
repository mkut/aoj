#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n; cin >> n;
	while(n--)
	{
		string key, val;
		cin >> key >> val;
		
		reverse(key.begin(), key.end());
		int L = val.length();
		for(int i = 0; i < key.length(); i++)
		{
			switch(key[i])
			{
				case 'C':
					val = val.substr(1) + val[0];
					break;
				case 'J':
					val = val[L-1] + val.substr(0, L-1);
					break;
				case 'E':
					val = val.substr((L+1)/2) + (L%2 ? val.substr(L/2,1) : "") + val.substr(0, L/2);
					break;
				case 'A':
					reverse(val.begin(), val.end());
					break;
				case 'M':
					for(int j = 0; j < L; j++)
					{
						if(val[j] >= '0' && val[j] <= '8')
							val[j]++;
						else if(val[j] == '9')
							val[j] = '0';
					}
					break;
				case 'P':
					for(int j = 0; j < L; j++)
					{
						if(val[j] >= '1' && val[j] <= '9')
							val[j]--;
						else if(val[j] == '0')
							val[j] = '9';
					}
					break;
			}
		}
		
		cout << val << endl;
	}
	return 0;
}
