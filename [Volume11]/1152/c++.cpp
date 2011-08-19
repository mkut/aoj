#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

template<class T>
class basic_symbols;

template<class T>
class basic_symbol{
private:
	basic_symbols<T>* symbols;
	public:
	int num;
public:
	basic_symbol(){
		symbols = NULL;
		num = 0;
	}
	basic_symbol(basic_symbols<T>* symbols, int num){
		this->symbols = symbols;
		this->num = num;
	}
	bool isNull(){
		return symbols == NULL;
	}
	T& operator*(){
		return symbols->getVal(num);
	}
	bool operator==(basic_symbol<T>& s){
		return num == s.num && symbols == s.symbols;
	}
	friend bool operator<(const basic_symbol<T>& a, const basic_symbol<T>& b){
		return a.num < b.num;
	}
};

template<class T>
class basic_symbols{
private:
	vector<T> symbols;
public:
	basic_symbols(){}
	basic_symbol<T> getSymbol(T val){
		for(int i = 0; i < symbols.size(); i++){
			if(symbols[i] == val){
				return basic_symbol<T>(this, i);
			}
		}
		symbols.push_back(val);
		return basic_symbol<T>(this, symbols.size()-1);
	}
	T& getVal(int i){
		return symbols[i];
	}
};

class BinaryTree
{
private:
	basic_symbol<BinaryTree> left;
	basic_symbol<BinaryTree> right;
	double similarity;
	bool similarity_left;
	vector<basic_symbol<BinaryTree> > types;
	
public:
	BinaryTree(string str, basic_symbols<BinaryTree>* stock)
	{
		if(str[0] == 'x')
		{
			similarity = 0;
		}
		else
		{
			//parse
			int pos = 1;
			int nest = 0;
			for(; pos < str.length(); pos++)
			{
				if(str[pos] == '(')
					nest++;
				else if(str[pos] == ')')
					nest--;
				else if(str[pos] == ' ' && nest == 0)
					break;
			}
			
			//new
			BinaryTree bt = BinaryTree(str.substr(1, pos-1), stock);
			left = stock->getSymbol(bt);
			right = stock->getSymbol(BinaryTree(str.substr(pos+1, str.length() - pos - 2), stock));
			(*left).types.push_back(left);
			(*right).types.push_back(right);
			sort((*left).types.begin(), (*left).types.end());
			(*left).types.erase(unique((*left).types.begin(), (*left).types.end()), (*left).types.end());
			sort((*right).types.begin(), (*right).types.end());
			(*right).types.erase(unique((*right).types.begin(), (*right).types.end()), (*right).types.end());
			
			similarity = sim();
			similarity_left = *left < *right;
			
			//cout <<(*this) << endl;
			//cout << similarity << "," << similarity_s << "," << similarity_b << endl;
		}
	}
	
	double sim()
	{
		types = (*left).types;
		for(int i = 0; i < (*right).types.size(); i++)
			types.push_back((*right).types[i]);
		sort(types.begin(), types.end());
		types.erase(unique(types.begin(), types.end()), types.end());
		return (double)((*left).types.size() +(*right).types.size() - types.size()) / types.size();
	}
	
	string str(bool typeL)
	{
		if(left.isNull())
			return "x";
		else
		{
			return "(" + (typeL == *left < *right ? (*left).str(true) : (*right).str(true)) +
					" " + (typeL == *left < *right ? (*right).str(false) : (*left).str(false)) + ")";
		}
	}
	
	friend ostream& operator<<(ostream& os, BinaryTree& bt)
	{
		os << bt.str(true);
		return os;
	}
	bool operator==(BinaryTree& b)
	{
		if(left.isNull() && b.left.isNull())
			return true;
		if(left.isNull() || b.left.isNull())
			return false;
		return (left == b.left && right == b.right) || (left == b.right && right == b.left);
	}
	bool operator<(BinaryTree& b)
	{
		if(this->similarity < b.similarity)
			return true;
		if(this->similarity > b.similarity)
			return false;
		if((*this) == b)
			return false;
		if((this->similarity_left ? *(this->left) : *(this->right)) < (b.similarity_left ? *(b.left) : *(b.right)))
			return true;
		if((b.similarity_left ? *(b.left) : *(b.right)) < (this->similarity_left ? *(this->left) : *(this->right)))
			return false;
		if((!(this->similarity_left) ? *(this->left) : *(this->right)) < (!(b.similarity_left) ? *(b.left) : *(b.right)))
			return true;
		if((!(b.similarity_left) ? *(b.left) : *(b.right)) < (!(this->similarity_left) ? *(this->left) : *(this->right)))
			return false;
		return false;
	}
};

int main()
{
	string input;
	while(getline(cin, input), input != "0")
	{
		basic_symbols<BinaryTree> stock;
		BinaryTree* root = new BinaryTree(input, &stock);
		
		cout << *root << endl;
		
		delete root;
	}
	return 0;
}
