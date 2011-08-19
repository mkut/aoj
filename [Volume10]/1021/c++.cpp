#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> text;
	string input;
	while(getline(cin, input))
	{
		if(input == "END_OF_TEXT") break;
		text.push_back(input);
	}
	
	int curw = 0, curl = 0;
	string buf = "";
	bool finished = false;
	while(!finished)
	{
		cin >> input;
		switch(input[0])
		{
		  case 'a':
			curw = 0;
			break;
		  case 'e':
			curw = text[curl].length();
			break;
		  case 'p':
			curw = 0;
			curl = max(0, curl-1);
			break;
		  case 'n':
			curw = 0;
			curl = min((int)text.size()-1, curl+1);
			break;
		  case 'f':
			if(curw < text[curl].length()) curw++;
			else if(curl < text.size()-1){ curl++; curw = 0; }
			break;
		  case 'b':
			if(curw > 0) curw--;
			else if(curl > 0){ curl--; curw = text[curl].length(); }
			break;
		  case 'd':
			if(curw < text[curl].length()) text[curl] = text[curl].substr(0,curw) + text[curl].substr(curw+1);
			else if(curl < text.size()-1)
			{
				text[curl] += text[curl+1]; 
				for(int l = curl+1; l < text.size()-1; l++)
				{
					text[l] = text[l+1];
				}
				text.pop_back();
			}
			break;
		  case 'k':
			if(curw >= text[curl].length() && curl < text.size()-1)
			{
				text[curl] += text[curl+1]; 
				text.erase(text.begin()+curl+1);
				buf = "\n";
			}
			else if(curw < text[curl].length()){ buf = text[curl].substr(curw); text[curl] = text[curl].substr(0, curw); }
			break;
		  case 'y':
			if(buf == "\n")
			{
				text.insert(text.begin()+curl+1, text[curl].substr(curw));
				text[curl] = text[curl].substr(0,curw);
				curl++;
				curw = 0;
			}
			else
			{
				text[curl] = text[curl].substr(0,curw) + buf + text[curl].substr(curw);
				curw += buf.length();
			}
			break;
		  case '-':
			finished = true;
			break;
		}
		/*
		for(int i = 0; i < text.size(); i++)
		{
			if(i != curl) cout << text[i] << endl;
			else{
				cout << text[i].substr(0, curw) << '(';
				if(curw < text[i].length()) cout << text[i][curw] << ')' << text[i].substr(curw+1);
				cout << endl;
			}
		}
		*/
	}
	for(int i = 0; i < text.size(); i++)
	{
		cout << text[i] << endl;
	}
	return 0;
}