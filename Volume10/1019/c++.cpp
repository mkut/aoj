#include <iostream>
using namespace std;

int main()
{
	int N, K;
	while(cin >> N >> K, N != 0)
	{
		int blood[100];
		for(int i = 0; i < K; i++)
		{
			cin >> blood[i];
		}
		for(int k = 0; k < N; k++)
		{
			for(int i = 0; i < K; i++)
			{
				int tmp; cin >> tmp;
				blood[i] -= tmp;
			}
		}
		
		bool ok = true;
		for(int i = 0; i < K; i++)
		{
			if(blood[i] < 0) ok = false;
		}
		cout << (ok ? "Yes" : "No") << endl;
	}
	return 0;
}