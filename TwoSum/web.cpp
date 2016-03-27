
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

