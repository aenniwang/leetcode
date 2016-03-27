
vector<string> summaryRanges(vector<int>& nums){
	vector<string> result;
	if(nums.size()!=0){
		int start = nums[0];
		int cur = nums[0];
		for(int i=1; i<nums.size(); ++i){
			if(nums[i] != cur + 1){
				string str;
				str += to_string(start);
				if(start != cur){
					str += "->";
					str += to_string(cur);
				}
				result.push_back(str);
				start = nums[i];
			}
			cur = nums[i];
		}
		string str;
		str += to_string(start);
		if(start != cur){
			str += "->";
			str += to_string(cur);
		}
		result.push_back(str);
	}
	return result;
}

