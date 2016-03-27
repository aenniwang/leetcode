#include<iostream>
#include<map>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
	map<int, int> minus_pos;
	int first, second;
	for(int i=0; i<nums.size(); i++){
		int sub = target - nums[i];
			if(minus_pos.find(nums[i]) != minus_pos.end()){
				first = minus_pos[nums[i]];
				second = i;
				break;
			}else{
				minus_pos[sub] = i;
			}
	}
	vector<int> result;
	result.push_back(first);
	result.push_back(second);
	return result;
}

int main(){
	int tmp[] = {-3,4,3,90};
	vector<int> nums(tmp, tmp+sizeof(tmp)/sizeof(int));
	vector<int> result = twoSum(nums, 0);
	for(int i=0; i<result.size(); i++){
		cout << result[i] << endl;
	}

	return 0;
}
