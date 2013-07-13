#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

struct Node
{
  int city;
  int prev;
  int speed;
  double time;
  static int numpath[32];
  static int pathCity[32][32];
  static int pathDistance[32][32];
  static int pathLimit[32][32];
  static bool fixed[32][32][32];
  static int numfixed[32][32];
  Node* nextNear;
  
  static void Init()
  {
    memset(numpath, 0, 32*4);
    memset(pathCity, 0, 32*32*4);
    memset(pathDistance, 0, 32*32*4);
    memset(pathLimit, 0, 32*32*4);
    memset(fixed, 0, sizeof(bool)*32*32*32);
    memset(numfixed, 0, 32*32*4);
  }
  
  Node(int city, int prev, int speed, double time, Node* nextNear)
  {
    this->city = city;
    this->prev = prev;
    this->speed = speed;
    this->time = time;
    this->nextNear = nextNear;
  }
  
  static void addNextNode(int from, int to, int dist, int limit)
  {
    pathCity[from][numpath[from]] = to;
    pathDistance[from][numpath[from]] = dist;
    pathLimit[from][numpath[from]] = limit;
    numpath[from]++;
  }
  
  Node* calcNextNode()
  {
    fixed[this->city][this->prev][this->speed] = true;
    if(++numfixed[this->city][this->speed] > 1)
    {
      for(int i = 0; i < 32; i++)
      {
        fixed[this->city][i][this->speed] = true;
      }
    }
    for(int i = 0; i < numpath[this->city]; i++)
    {
      Node* cur = this;
      for(int speed = this->speed + 1; speed >= this->speed - 1; speed--)
      {
        for(; ; cur = cur->nextNear)
        {
          if(speed <= 0 || speed > pathLimit[this->city][i])
          {
            break;
          }
          if(fixed[pathCity[this->city][i]][this->city][speed])
          {
            break;
          }
          if(pathCity[this->city][i] == this->prev)
          {
            break;
          }
          if(cur->nextNear == NULL)
          {
            cur->nextNear = new Node(pathCity[this->city][i], this->city, speed, this->time + (double)pathDistance[this->city][i] / speed, NULL);
            break;
          }
          if(fixed[cur->nextNear->city][cur->nextNear->prev][cur->nextNear->speed])
          {
            cur->nextNear = cur->nextNear->nextNear;
            if(cur->nextNear == NULL)
            {
              cur->nextNear = new Node(pathCity[this->city][i], this->city, speed, this->time + (double)pathDistance[this->city][i] / speed, NULL);
              break;
            }
          }
          if(cur->nextNear->time > this->time + (double)pathDistance[this->city][i] / speed)
          {
            cur->nextNear = new Node(pathCity[this->city][i], this->city, speed, this->time + (double)pathDistance[this->city][i] / speed, cur->nextNear);
            break;
          }
        }
      }
    }
    
    return this->nextNear;
  }
  
  static bool _isReachable(int from, int to, bool* reachable)
  {
    if(from == to)
    {
      return true;
    }
    if(reachable[from])
    {
      return false;
    }
    reachable[from] = true;
    bool ret = false;
    for(int i = 0; i < numpath[from]; i++)
    {
      ret |= _isReachable(pathCity[from][i], to, reachable);
    }
    return ret;
  }
  
  static bool isReachable(int from, int to)
  {
    bool reachable[32] = {false};
    return _isReachable(from, to, reachable);
  }
};

int Node::numpath[32];
int Node::pathCity[32][32];
int Node::pathDistance[32][32];
int Node::pathLimit[32][32];
bool Node::fixed[32][32][32];
int Node::numfixed[32][32];

int main()
{
  int n, m;
  while(true)
  {
    cin >> n >> m;
    if(n == 0)
    {
      return 0;
    }
    
    Node::Init();
    Node* current;
    int start, goal;
    cin >> start;
    current = new Node(start, 0, 0, 0, NULL);
    cin >> goal;
    
    for(int i = 0; i < m; i++)
    {
      int city1, city2, dist, lim;
      cin >> city1 >> city2 >> dist >> lim;
      Node::addNextNode(city1, city2, dist, lim);
      Node::addNextNode(city2, city1, dist, lim);
    }
    
    if(!Node::isReachable(start, goal))
    {
      cout << "unreachable" << endl;
      continue;
    }
    
    while(true)
    {
      current = current->calcNextNode();
      //  printf("time:%.5f / city:%d(%d) / speed:%d\n", current->time, current->city, current->prev, current->speed);
      
      if(current->city == goal && current->speed == 1)
      {
        printf("%.5f\n", current->time);
        break;
      }
    }
  }
  
  return 0;
}
