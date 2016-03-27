#include<iostream>
#include<string>
#include<stack>

using namespace std;

string countAndSay(int n){
	if(n == 0)	
		return "10";
	int sub_n = n;
	stack<int> result;
	while(sub_n > 0){
		int cur_num = sub_n % 10;
		if(result.empty()){
			result.push(cur_num);
			result.push(1);
		}else{
			if(result.top() == cur_num)
				result.top()++;
			else{
				result.push(cur_num);
				result.push(1);
			}
		}
		sub_n /= 10;
	}
	string str;
	int size = result.size();
	for(int i=0; i<size; i++){
		str.push_back(result.top() + '0');
		result.pop();
	}
	return str;

}

int main(){
	int n = 0;
	cout << "count and say: " << countAndSay(n) << endl;

	return 0;
}
