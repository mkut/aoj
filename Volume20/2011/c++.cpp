#include <iostream>
using namespace std;

int main()
{
  int n;
  while(cin >> n, n != 0)
  {
    //input
    bool day[50][31] = {};
    for(int i = 0; i < n; i++)
    {
      int f;
      cin >> f;
      for(int j = 0; j < f; j++)
      {
        int d;
        cin >> d;
        day[i][d] = true;
      }
    }
    
    //init
    long long piece[50] = {};
    for(int i = 0; i < n; i++)
      piece[i] = 1LL << i;
    long long ok = (1LL << n) - 1;
    int ans = 0;
    
    //main
    for(int i = 1; i <= 30; i++)
    {
      long long today = 0;
      for(int j = 0; j < n; j++)
      {
        if(day[j][i])
          today |= piece[j];
      }
      for(int j = 0; j < n; j++)
      {
        if(day[j][i])
        {
          piece[j] |= today;
          if(piece[j] == ok)
          {
            ans = i;
            break;
          }
        }
      }
      if(ans != 0)
        break;
    }
    cout << (ans != 0 ? ans : -1) << endl;
  }
  return 0;
}