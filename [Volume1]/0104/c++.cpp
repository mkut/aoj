#include <iostream>
using namespace std;

int move(char* map, int pos)
{
  if(map[pos] == '.')
  {
    return pos;
  }
  if(map[pos] == '@')
  {
    return -1;
  }
  if(map[pos] == '>')
  {
    map[pos] = '@';
    return move(map, pos+1);
  }
  if(map[pos] == '<')
  {
    map[pos] = '@';
    return move(map, pos-1);
  }
  if(map[pos] == 'v')
  {
    map[pos] = '@';
    return move(map, pos+100);
  }
  if(map[pos] == '^')
  {
    map[pos] = '@';
    return move(map, pos-100);
  }
}

int main()
{
  int h, w;
  while(cin >> h >> w, h != 0 || w != 0)
  {
    char map[101][100];
    for(int i = 0; i < h; i++)
    {
      cin >> map[i];
    }
    
    int result = move(map[0], 0);
    if(result == -1)
    {
      cout << "LOOP" << endl;
    }
    else
    {
      printf("%d %d\n", result%100, result/100);
    }
  }
  
  return 0;
}