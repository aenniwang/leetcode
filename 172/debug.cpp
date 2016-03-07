#include<iostream>
#include<string>

using namespace std;

int trailingZeroes(int n){
	int num_zeros = 0;
	long long tmp=5;
	while(n >= tmp){
		num_zeros += n/tmp;
		tmp *= 5;
	}
	return num_zeros;
}

int main(){
	cout << "The number of trailing zeros is: "<< trailingZeroes(2147483647) << endl;
	return 0;
}
