#include <iostream>
using namespace std;

class solver
{
  private:
	vector<vector<int> > hate;
	
	
  public:
	solver(vector<vector<int> > _hate)
	{
		hate = _hate;
	}
};

int main()
{
	int n;
	while(cin >> n)
	{
		vector<vector<int> > hate(n);
		for(int i = 0; i < n; i++)
		{
			hate[i] = vector<int>(n);
			for(int j = 0; j < n; j++)
			{
				cin >> hate[i][j];
			}
		}
		
		solver prob(hate);
	}
	return 0;
}