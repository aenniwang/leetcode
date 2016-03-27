
void rotate(vector<int>& nums, int k) {
	map<int, int> pos_value;

	for(int i=0; i<nums.size(); i++){
		pos_value[(i+k)%nums.size()] = nums[i];
	}
	for(int i=0; i<nums.size(); i++){
		nums[i] = pos_value[i];
	}
}

