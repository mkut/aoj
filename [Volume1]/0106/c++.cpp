#include <iostream>
using namespace std;

int shopA(int x)
{
  return x / 5 * 1520 + x % 5 * 380;
}
int shopB(int x)
{
  return x / 4 * 1870 + x % 4 * 550;
}
int shopC(int x)
{
  return x / 3 * 2244 + x % 3 * 850;
}

int main()
{
  int x;
  while(cin >> x, x != 0)
  {
    int min = 9500;
    for(int a = 0; a <= 25; a++)
    {
      if(a * 200 >= x)
      {
        if(a * 200 > x)
        {
          break;
        }
        int tmp = shopA(a);
        if(min > tmp)
        {
          min = tmp;
        }
        break;
      }
      for(int b = 0; b <= 17; b++)
      {
        if(a * 200 + b * 300 >= x)
        {
          if(a * 200 + b * 300 > x)
          {
            break;
          }
          int tmp = shopA(a) + shopB(b);
          if(min > tmp)
          {
            min = tmp;
          }
          break;
        }
        for(int c = 0; c <= 10; c++)
        {
          if(a * 200 + b * 300 + c * 500 >= x)
          {
            if(a * 200 + b * 300 + c * 500 > x)
            {
              break;
            }
            int tmp = shopA(a) + shopB(b) + shopC(c);
            if(min > tmp)
            {
              min = tmp;
            }
            break;
          }
        }
      }
    }
    
    cout << min << endl;
  }
  
  return 0;
}