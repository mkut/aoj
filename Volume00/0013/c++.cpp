#include <iostream>
using namespace std;

int main()
{
  int n;
  int stack[10];
  int numStack = 0;
  
  while(cin >> n)
  {
    if(n != 0)
    {
      stack[numStack++] = n;
    }
    else
    {
      cout << stack[--numStack] << endl;
    }
  }
  
  return 0;
}