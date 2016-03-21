#include<iostream>
#include<stack>

using namespace std;

bool isValid(string s){
	stack<char> left;

	for(int i=0; i<s.length(); i++){
		if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
			left.push(s[i]);
		}else if(s[i] == ')'){
			if(left.size() == 0 || left.top() != '(')
				return false;
			else 
				left.pop();
		}else if(s[i] == ']'){
			if(left.size() == 0 || left.top() != '[')
				return false;
			else 
				left.pop();
		}else if(s[i] == '}'){
			if(left.size() == 0 || left.top() != '{')
				return false;
			else 
				left.pop();
		}
		
	}
	if(left.size() == 0)
		return true;
	else
		return false;
}

int main(){
	string s = "()";
	cout << "is " << s << " valid? " << isValid(s) << endl;
	return 0;
}
