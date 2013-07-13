#include <iostream>
using namespace std;

int main()
{
  int a, b;
  while(cin >> a >> b)
  {
    int count = 0;
    for(int sum = a + b; sum != 0; sum /= 10)
    {
      count++;
    }
    cout << (count > 1 ? count : 1) << endl;
  }
  
  return 0;
}