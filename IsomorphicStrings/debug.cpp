#include<iostream>
#include<map>

using namespace std;

bool isIsomorphic(string s, string t){
	if(s.size() != t.size())	
		return false;
	map<char, char> s_t;
	map<char, char> t_s;
	for(int i=0; i<s.size(); i++){
		if(s_t.find(s[i]) == s_t.end()){
			s_t[s[i]] = t[i];
		}else{
			if(s_t[s[i]] != t[i])
				return false;
		}
		if(t_s.find(t[i]) == t_s.end()){
			t_s[t[i]] = s[i];
		}else{
			if(t_s[t[i]] != s[i])
				return false;
		}
	}
	return true;
}

int main(){
	string s ="ab";
	string t = "aa";
	cout << "is isomorphic? " << isIsomorphic(s, t) << endl;
	return 0;
}
