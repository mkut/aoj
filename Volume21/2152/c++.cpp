#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class solver
{
	vector<int> partition, id;
public:
	solver()
	{
		partition.push_back(0);
		id.push_back(-1);
	}
	
	void write(int ID, int length)
	{
		for(int i = 1; i < partition.size(); i++)
		{
			if(length == 0)
				return;
			if(id[i] == -1)
			{
				if(partition[i] - partition[i-1] > length)
				{
					partition.insert(partition.begin() + i, partition[i-1] + length);
					id.insert(id.begin() + i, ID);
					return;
				}
				else
				{
					id[i] = ID;
					length -= partition[i] - partition[i-1];
				}
			}
			if(length == 0)
				return;
		}
		partition.push_back(partition.back() + length);
		id.push_back(ID);
	}
	
	void del(int ID)
	{
		for(int i = 0; i < id.size(); i++)
			if(id[i] == ID)
				id[i] = -1;
	}
	
	int read(int pos)
	{
		for(int i = 1; i < partition.size(); i++)
		{
			if(pos < partition[i])
			{
				return id[i];
			}
		}
		return -1;
	}
	
	void d()
	{
		int pos = 0;
		for(int i = 0; i < partition.back(); i++)
		{
			while(i >= partition[pos])
				pos++;
			cout << id[pos] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int N;
	bool first = true;
	while(cin >> N, N != 0)
	{
		solver prob;
		for(int i = 0; i < N; i++)
		{
			char command;
			cin >> command;
			if(command == 'W')
			{
				int I, S;
				cin >> I >> S;
				prob.write(I, S);
			}
			else if(command == 'D')
			{
				int I;
				cin >> I;
				prob.del(I);
			}
			else if(command == 'R')
			{
				int P;
				cin >> P;
				cout << prob.read(P) << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
