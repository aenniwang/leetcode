
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
