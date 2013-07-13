#include <iostream>
using namespace std;

int main()
{
	int b, e;
	bool fst = true;
	while(cin >> b >> e, b != 0)
	{
		if(!fst) cout << endl;
		fst = false;
		
		bool finished = false;
		for(int i = b; i <= e; i++)
		{
			if(i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
			{
				cout << i << endl;
				i += 3;
				finished = true;
			}
		}
		if(!finished) cout << "NA" << endl;
	}
	
	return 0;
}