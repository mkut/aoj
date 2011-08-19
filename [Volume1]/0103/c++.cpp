#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  n *= 3;
  
  int runner = 0, score = 0;
  while(n != 0)
  {
    char input[8];
    cin >> input;
    
    if(input[0] == 'O') //OUT
    {
      if(--n % 3 == 0)
      {
        cout << score << endl;
        runner = 0;
        score = 0;
      }
      continue;
    }
    if(input[1] == 'I') //HIT
    {
      if(runner & 4)
      {
        score++;
      }
      runner = ((runner << 1) & 7) + 1;
      continue;
    }
    if(input[1] == 'O') //HOMERUN
    {
      if(runner & 1)
      {
        score++;
      }
      if(runner & 2)
      {
        score++;
      }
      if(runner & 4)
      {
        score++;
      }
      score++;
      runner = 0;
    }
    
  }
  return 0;
}