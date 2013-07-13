#include <iostream>
#include <stack>
using namespace std;

double calc(double cur)
{
	static stack<double> st;
	if(cur == -0.1)
	{
		double a = st.top(); st.pop();
		double b = st.top(); st.pop();
		st.push(b+a);
	}
	else if(cur == -0.2)
	{
		double a = st.top(); st.pop();
		double b = st.top(); st.pop();
		st.push(b-a);
	}
	else if(cur == -0.3)
	{
		double a = st.top(); st.pop();
		double b = st.top(); st.pop();
		st.push(b*a);
	}
	else if(cur == -0.4)
	{
		double a = st.top(); st.pop();
		double b = st.top(); st.pop();
		st.push(b/a);
	}
	else
	{
		st.push(cur);
	}
	return st.top();
}

int main()
{
	string input;
	while(getline(cin, input))
	{
		double cur = 0;
		for(int i = 0; i < input.length(); i++)
		{
			if(input[i] >= '0' && input[i] <= '9')
			{
				if(cur == -0.2) cur = -(input[i] - '0');
				else if(cur == -0.1) cur = (input[i] - '0');
				else if(cur < 0) cur = cur * 10 - input[i] + '0';
				else cur = cur * 10 + input[i] - '0';
			}
			else if(input[i] == '+') cur = -0.1;
			else if(input[i] == '-') cur = -0.2;
			else if(input[i] == '*') cur = -0.3;
			else if(input[i] == '/') cur = -0.4;
			else if(input[i] == ' ')
			{
				calc(cur);
				cur = 0;
			}
		}
		printf("%.6f\n", calc(cur));
	}
	return 0;
}