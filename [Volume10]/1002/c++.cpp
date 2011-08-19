#include <iostream>
using namespace std;

class solver
{
  private:
	string input;
	int N;
	bool posup;
	bool posmid;
	
  public:
	solver(string input)
	{
		this->input = input;
		this->N = input.length()/4;
	}
	
	int solve()
	{
		int sum = _solve_fst();
		for(int i = 1; i < N; i++)
		{
			sum += _solve(i);
		}
		return sum + _solve_lst();
	}
	
  private:
	int _solve(int i)
	{
		if(!book_up(i) && !book_btm(i))
		{
			return 1;
		}
		if(book_up(i) && !book_btm(i))
		{
			posup = true; posmid = true;
			return 2;
		}
		if(!book_up(i) && book_btm(i))
		{
			int ret = posmid ? 2 : 3;
			posup = false; posmid = true;
			return ret;
		}
		if(book_up(i) && book_btm(i))
		{
			posup = posmid; posmid = true;
			return 3;
		}
	}
	int _solve_fst()
	{
		if(!book_up(0) && !book_btm(0))
		{
			posup = true; posmid = false;
			return 1;
		}
		if(book_up(0) && !book_btm(0))
		{
			posup = true; posmid = true;
			return 2;
		}
		if(!book_up(0) && book_btm(0))
		{
			posup = false; posmid = true;
			return 3;
		}
		if(book_up(0) && book_btm(0))
		{
			posup = false; posmid = true;
			return 3;
		}
	}
	int _solve_lst()
	{
		if(!book_up(N) && !book_btm(N))
		{
			return posup ? 0 : 1;
		}
		if(book_up(N) && !book_btm(N))
		{
			return 1;
		}
		if(!book_up(N) && book_btm(N))
		{
			return posmid ? 2 : 3;
		}
		if(book_up(N) && book_btm(N))
		{
			return posmid ? 2 : 3;
		}
	}
	bool book_up(int i)
	{
		if(i == 0) return input[0] == 'Y';
		if(i == N) return input[2*N-1] ==  'Y';
		else return input[2*i-1] == 'Y' || input[2*i] == 'Y';
	}
	bool book_btm(int i)
	{
		if(i == 0) return input[2*N] == 'Y';
		if(i == N) return input[4*N-1] ==  'Y';
		else return input[2*(i+N)-1] == 'Y' || input[2*(i+N)] == 'Y';
	}
	
};

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		string input;
		cin >> N >> input;
		
		solver prob(input);
		cout << prob.solve() << endl;
	}
	return 0;
}