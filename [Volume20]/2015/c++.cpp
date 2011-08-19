#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, m;
  while(cin >> n >> m, n != 0 || m != 0)
  {
    int tate[1500] = {0}, yoko[1500] = {0};
    short t_count[1500001] = {0}, y_count[1500001] = {0};
    for(int i = 0; i < n; i++)
      cin >> tate[i];
    for(int i = 0; i < m; i++)
      cin >> yoko[i];
    
    int max = 0;
    for(int i = 0; i < n; i++)
    {
      int sum = 0;
      for(int j = i; j < n; j++)
      {
        sum += tate[j];
        t_count[sum]++;
        max = max < sum ? sum : max;
      }
    }
    for(int i = 0; i < m; i++)
    {
      int sum = 0;
      for(int j = i; j < m; j++)
      {
        sum += yoko[j];
        y_count[sum]++;
        max = max < sum ? sum : max;
      }
    }
    
    int ans = 0;
    for(int i = 1; i <= max; i++)
    {
      ans += t_count[i]*y_count[i];
    }
    cout << ans << endl;
  }
  return 0;
}