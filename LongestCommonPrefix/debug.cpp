#include<iostream>
#include<vector>
#include<string>

using namespace std;

string longestCommonPrefix(vector<string>& strs){
	string prefix;
	if(strs.size() != 0){
		prefix=strs[0];
		for(int i=1; i<strs.size(); i++){
			int compare_time = strs[i].size() > prefix.size() ? prefix.size() : strs[i].size();
			int j=0;
			for(; j<compare_time; j++){
				if(strs[i][j] != prefix[j])
					break;
			}
		
			prefix = prefix.substr(0, j);
		}
	}
	return prefix;
	

}

int main(){
	string a = "ab";
	string b = "abc";
	vector<string> strs;
	strs.push_back(a);
	strs.push_back(b);
	cout << "longestCommonPrefix is: " << longestCommonPrefix(strs) << endl;
	return 0;
}
