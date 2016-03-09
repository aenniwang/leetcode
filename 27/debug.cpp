#include<iostream>
#include<vector>

using namespace std;

int removeElement(vector<int>& nums, int val){
	if(nums.size() == 0)
		return 0;
	int i=0, j=nums.size()-1;
	while(i<=j){
		if(nums[i] == val){
			nums[i] = nums[j];
			--j;
		}else{
			++i;
		}
	}   
	return j+1;		
}

int main(){
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(3);
	cout << "after remove number: " << removeElement(nums,3) << endl;
	return 0;
}
