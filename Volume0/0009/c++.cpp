#include <iostream>
using namespace std;

int main()
{
  int n;
  
  bool furui[1000000] = {true, true};
  int hojo[100] = {0};
  for(int i = 2; i < 1000000; i++)
  {
    if(!furui[i])
    {
      for(int j = 2; i * j < 1000000; j++)
      {
        furui[i * j] = true;
      }
    }
  }
  for(int i = 1; i < 100; i++)
  {
    int count = 0;
    for(int j = 0; j < 10000; j++)
    {
      if(!furui[(i-1)*10000+j])
      {
        count++;
      }
    }
    hojo[i] = hojo[i-1] + count;
  }
  
  while(cin >> n)
  {
    int count = 0;
    for(int i = n / 10000 * 10000; i <= n; i++)
    {
      if(!furui[i])
      {
        count++;
      }
    }
    cout << hojo[n / 10000] + count << endl;
  }
  
  return 0;
}