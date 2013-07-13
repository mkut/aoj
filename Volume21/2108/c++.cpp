#include <iostream>
#include <map>
#include <list>
using namespace std;

// -- milib begin --
struct Node{
  private:
	
  public:
	list<Node*> connectedNodes;
	Node(){}
	void addEdge(Node* node){
		connectedNodes.push_back(node);
	}
};

typedef pair<Node*, Node*> Edge;
typedef void (*hoge)(Node);

class DirectedGraph{
  private:
	list<Node> nodes;
	
  public:
	void addNode(Node node){
		nodes.push_back(node);
	}
	void addEdge(Edge edge){
		edge.first->addEdge(edge.second);
	}
};

class NonDirectedGraph : DirectedGraph{
  public:
	void addEdge(Edge edge){
		edge.first->addEdge(edge.second);
		edge.second->addEdge(edge.first);
	}
  public:
	list<NonDirectedGraph*> divideGraph(){
		map<Node*,bool> already;
		
	}
  private:
	void _divideGraph(NonDirectedGraph* graph, Edge move, map<Node*,bool>& already){
		if(already[move.second]) return;
		already[move.second] = true;
		graph->addNode(*move.second);
		for(list<Node*>::iterator it = move.second->connectedNodes.begin(); it != move.second->connectedNodes.end(); it++){
			if(*it != move.first){
				_divideGraph(graph, Edge(move.second, *it), already);
			}
		}
		return;
	}
  public:
	bool haveLoop(){
		
	}
  private:
	bool _haveLoop(Edge move, map<Node*,bool>& already){
		if(already[move.second]) return true;
		already[move.second] = true;
		for(list<Node*>::iterator it = move.second->connectedNodes.begin(); it != move.second->connectedNodes.end(); it++){
			if(*it != move.first){
				if(_haveLoop(Edge(move.second, *it), already)) return true;
			}
		}
		return false;
	}
};

// -- milib end --

int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		int M;
		cin >> M;
		map<pair<int,int>,bool> connected;
		for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < M; j++)
			{
				int tmp;
				cin >> tmp;
				connected[pair<int,int>(i,j)] = tmp == 1;
			}
		}
		
	}
	return 0;
}