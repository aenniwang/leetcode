#include<iostream>
#include<vector>
#include<map>

using namespace std;

void rotate(vector<int>& nums, int k) {
	map<int, int> pos_value;

	for(int i=0; i<nums.size(); i++){
		pos_value[(i+k)%nums.size()] = nums[i];
	}
	for(int i=0; i<nums.size(); i++){
		nums[i] = pos_value[i];
	}
}

int main(){
	int tmp[] = {1,2,3,4,5,6};
	int k=2;
	vector<int> nums(tmp, tmp+sizeof(tmp)/sizeof(int));

	rotate(nums, k);
	for(int i=0; i<nums.size(); i++){
		cout << nums[i] << endl;
	}

	return 0;
}
