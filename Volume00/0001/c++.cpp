#include <iostream>
using namespace std;

int main()
{
  int max[4] = {0};
  
  int n = 10;
  while(n--)
  {
    cin >> max[0];
    for(int i = 0; i < 3; i++)
    {
      if(max[i] > max[i+1])
      {
        int tmp = max[i+1];
        max[i+1] = max[i];
        max[i] = tmp;
      }
      else
      {
        break;
      }
    }
  }
  
  for(int i = 3; i >= 1; i--)
  {
    cout << max[i] << endl;
  }
  
  return 0;
}