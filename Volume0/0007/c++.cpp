#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int amount = 100000;
  
  while(n--)
  {
    amount = ((amount * 105 / 100) + 999) / 1000 * 1000;
  }
  
  cout << amount << endl;
  
  return 0;
}