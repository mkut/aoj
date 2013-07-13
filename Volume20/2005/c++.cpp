#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n, m, s, g1, g2;
  
  while(cin >> n >> m >> s >> g1 >> g2, n != 0)
  {
    int cost[1001][1001];
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        cost[i][j] = i == j ? 0 : 10000000;
    
    while(m--){
      int tmp1, tmp2, tmp3;
      cin >> tmp1 >> tmp2 >> tmp3;
      cost[tmp1][tmp2] = tmp3;
      //cost[tmp2][tmp1] = tmp3;
    }
    
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        for(int k = 1; k <= n; k++)
          cost[j][k] = min(cost[j][i] + cost[i][k], cost[j][k]);
    
    int ans = 10000000;
    
    for(int i = 1; i <= n; i++)
      ans = min(ans, cost[s][i] + cost[i][g1] + cost[i][g2]);
    
    cout << ans << endl;
  }
  
  return 0;
}