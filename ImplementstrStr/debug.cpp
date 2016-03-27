#include<iostream>
#include<string>

using namespace std;

int strStr(string haystack, string needle){
	if(haystack.size() < needle.size())
		return -1;
	if(needle == "")
		return 0;
	int i=0;
	int j;
	for(; i<=haystack.size()-needle.size(); i++){
		if(haystack[i] == needle[0]){
			j = 1;
			for(; j<needle.size(); j++){
				if(needle[j] != haystack[i+j])
					break;
			}
			if(j == needle.size())
				break;
		}
	}
	if(j < needle.size())
		return -1;
	return i;
}

int main(){
	string a = "missassippa";
	string b = "a";
	cout << "first substr appear pos: " << strStr(a, b)<< endl;
	return 0;
}
