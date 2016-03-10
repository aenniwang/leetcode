
int removeDuplicates(vector<int>& nums){

	if(nums.size() == 0)
		return 0;
	else if(nums.size() == 1)
		return 1;
	vector<int> move_pos;
	move_pos.push_back(0);
	for(int i=1; i<nums.size(); i++){
		if(nums[i] == nums[i-1])
			move_pos.push_back(move_pos.back()+1);
		else
			move_pos.push_back(move_pos.back());
	}
	for(int i=1; i<nums.size(); i++){
		nums[i-move_pos[i]] = nums[i];
	}
	return nums.size()-move_pos.back();
}
