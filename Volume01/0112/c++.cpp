#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  int time[10000];
  while(cin >> n, n != 0)
  {
    unsigned int sum = 0;
    
    for(int i = 0; i < n; i++)
    {
      cin >> time[i];
    }
    sort(time, time+n);
    
    for(int i = 0; i < n; i++)
    {
      sum += time[i] * (n-i-1);
    }
    
    cout << sum << endl;
  }
  return 0;
}