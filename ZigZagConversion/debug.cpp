#include<iostream>
#include<string>

using namespace std;

string convert(string s, int numRows){
	if(s=="")
		return "";
	if(s.size() <= numRows || numRows == 1)
		return s;
	string result;
	for(int i=0; i<numRows; i++){
		int cur_pos = i;
		int cur_step; 
		if(i==numRows-1)
			cur_step = 2*i;
		else
			cur_step = 2*(numRows-i-1);
		while(cur_pos < s.length()){
			result.push_back(s[cur_pos]);
			cur_pos += cur_step;
			if(i != numRows-1 && i != 0){
				if(cur_step == 2*(numRows-i-1))
					cur_step = 2*i;
				else if(cur_step == 2*i)
					cur_step = 2*(numRows-i-1);
			}
		}
	}
	return result;
}

int main(){
//	string test = "PAYPALISHIRING";
	string test = "A";
	cout << "zig zag convert " << test << " to " << convert(test, 1) << endl;
	return 0;
}
