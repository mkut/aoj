#include <iostream>
using namespace std;

int main()
{
  int w;
  int n;
  cin >> w >> n;
  
  int ans[32];
  
  for(int i = 1; i <= w; i++)
  {
    ans[i] = i;
  }
  for(int i = 0; i < n; i++)
  {
    int tmp1 = 0;
    int tmp2 = 0;
    char str[6];
    cin >> str;
    for(int i = 0; i < 6; i++)
    {
      if(str[i] == ',')
      {
        tmp1 = tmp2;
        tmp2 = 0;
      }
      else if(str[i] >= '0' && str[i] <= '9')
      {
        tmp2 = tmp2 * 10 + str[i] - '0';
      }
      else
      {
        break;
      }
    }
    int tmp = ans[tmp1];
    ans[tmp1] = ans[tmp2];
    ans[tmp2] = tmp;
  }
  
  for(int i = 1; i <= w; i++)
  {
    cout << ans[i] << endl;
  }
  return 0;
}