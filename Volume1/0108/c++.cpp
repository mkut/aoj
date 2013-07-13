#include <iostream>
using namespace std;

bool isEqual(int* seq1, int* seq2, int num)
{
  for(int i = 0; i < num; i++)
  {
    if(seq1[i] != seq2[i])
    {
      return false;
    }
  }
  return true;
}

void copy(int* from, int* to, int num)
{
  for(int i = 0; i < num; i++)
  {
    to[i] = from[i];
  }
  return;
}

void ope(int* from, int* to, int num)
{
  for(int i = 0; i < num; i++)
  {
    int count = 0;
    for(int j = 0; j < num; j++)
    {
      if(from[i] == from[j])
      {
        count++;
      }
    }
    to[i] = count;
  }
  return;
}

int main()
{
  int n;
  while(cin >> n, n != 0)
  {
    int seq[12], nextseq[12];
    int count = 0;
    for(int i = 0; i < n; i++)
    {
      cin >> seq[i];
    }
    
    while(ope(seq, nextseq, n), !isEqual(seq, nextseq, n))
    {
      copy(nextseq, seq, n);
      count++;
    }
    
    cout << count << endl;
    for(int i = 0; i < n; i++)
    {
      cout << (i == 0 ? "" : " ") << seq[i];
    }
    cout << endl;
  }
  
  return 0;
}