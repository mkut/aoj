#include <iostream>
using namespace std;

int main()
{
  int n;
  while(cin >> n)
  {
    int ans = 0;
    if(n > 36)
    {
      cout << 0 << endl;
      continue;
    }
    if(n > 18)
    {
      n = 36 - n;
    }
    for(int i = 0; i <= 9; i++)
    {
      if(i > n)
      {
        break;
      }
      for(int j = 0; j <= 9; j++)
      {
        if(i+j > n)
        {
          break;
        }
        int nokori = n - i - j;
        ans += (nokori > 9 ? (19 - nokori > 0 ? 19 - nokori : 0) : (nokori + 1 > 0 ? nokori + 1 : 0));
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}