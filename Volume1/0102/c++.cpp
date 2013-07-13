#include <iostream>
using namespace std;

int main()
{
  int n;
  while(cin >> n, n != 0)
  {
    int ans[11][11];
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        cin >> ans[i][j];
      }
    }
    for(int i = 0; i < n; i++)
    {
      int tmp1 = 0, tmp2 = 0;
      for(int j = 0; j < n; j++)
      {
        tmp1 += ans[i][j];
        tmp2 += ans[j][i];
      }
      ans[i][n] = tmp1;
      ans[n][i] = tmp2;
    }
    int tmp = 0;
    for(int i = 0; i < n; i++)
    {
      tmp += ans[n][i];
    }
    ans[n][n] = tmp;
    
    for(int i = 0; i <= n; i++)
    {
      for(int j = 0; j <= n; j++)
      {
        printf("%5d", ans[i][j]);
      }
      cout << endl;
    }
  }
  return 0;
}