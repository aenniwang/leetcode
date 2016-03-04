#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

bool subIsHappy(int n, vector<int>& computed_num){
	if(n == 1)
		return true;

	int square = 0;
	if(n < 10)
		square += n*n;
	else{
		int m = n;
		while(m%10 == 0 || (m==1)){
			if(m == 1)
				return true;
			else if(m >= 10)
				m /= 10;
			else
				break;
		}

		int i = 1;
		while(n > pow(10, i-1)){
			long long int tmp = pow(10, i);
			square += pow((n % tmp)/(tmp/10), 2);
			i++;
		}
	}

	for(int j=0; j<computed_num.size(); j++){
		if(square == computed_num[j])
			return false;
	}

	computed_num.push_back(square);
	subIsHappy(square, computed_num);
}

bool isHappy(int n) {
	if(n == 0)
		return false;
	vector<int> computed_num;
	return subIsHappy(n, computed_num);
}

int main(){
	cout << "is happy: " << isHappy(1012321673) << endl;
	cout << "hello" << endl;
	return 0;
}
