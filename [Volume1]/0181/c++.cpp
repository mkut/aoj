#include <iostream>
#include <vector>
using namespace std;

class solver
{
  private:
	vector<int> books;
	int m;
	
  public:
	solver(vector<int> books, int m)
	{
		this->books = books;
		this->m = m;
	}
	
	int solve(int start, int end)
	{
		if(start == end) return start;
		
		if(arrangable((start+end)/2)) return solve(start, (start+end)/2);
		else return solve((start+end)/2+1, end);
	}
	
	bool arrangable(int w)
	{
		int i = 0;
		for(int j = 0; j < m; j++)
		{
			for(int sum = 0; sum + books[i] <= w; sum+= books[i++])
			{
				if(i+1 == books.size()) return true;
			}
		}
		return false;
	}
};

int main()
{
	int m, n;
	while(cin >> m >> n, m != 0)
	{
		vector<int> books;
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			int tmp; cin >> tmp;
			books.push_back(tmp);
			sum += tmp;
		}
		
		solver prob(books, m);
		cout << prob.solve(sum/m, sum) << endl;
	}
	return 0;
}