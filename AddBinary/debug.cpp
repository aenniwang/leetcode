#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string addBinary(string a, string b){
	if(a.empty())
		return b;
	if(b.empty())
		return a;
	string result;
	int size = a.size()>b.size() ? a.size() : b.size();
	int outsider = 0;
	for(int i=size-1, j=a.size()-1, k=b.size()-1; i>=0; i--, j--, k--){
		int cur_a = 0;
		int cur_b = 0;
		
		if(j<a.size())
			cur_a = a[j] - '0';
		if(k<b.size())
			cur_b = b[k] - '0';
		int judge = cur_a + cur_b + outsider;
		if(judge <= 1){
			result += to_string(judge);
			outsider = 0;
		}else if(judge == 2){
			result += "0";
			outsider = 1;
		}else if(judge == 3){
			result += "1";
			outsider = 1;
		}
	}
	if(outsider == 1)
		result += "1";
	reverse(result.begin(), result.end());
	return result;
}

int main(){
	string a = "111";
	string b = "1";
	cout << "add binary:  " << a << "+" << b << " = " << addBinary(a, b) << endl;
	return 0;
}
