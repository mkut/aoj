#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class generator
{
  private:
	int i;
  public:
	generator(){ i = 0; }
	int operator ()() { return ++i; }
};


int main()
{
	int n, m;
	while(cin >> n >> m, n != 0 || m != 0)
	{
		vector<int> vec(n);
		generate(vec.begin(), vec.end(), generator());
		for(int i = 0; vec.size() > 1; )
		{
			i = (i+m-1) % vec.size();
			vec.erase(vec.begin()+i);
		}
		cout << vec.front() << endl;
	}
	return 0;
}