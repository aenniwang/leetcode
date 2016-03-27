
class NumArray {
	public:
		NumArray(vector<int> &nums) {
			if(nums.size() > 0){
				_nums_sum.push_back(nums[0]);
				for(int i=1; i<nums.size(); i++){
					_nums_sum.push_back(nums[i] + _nums_sum[i-1]);
				}
			}
		}

		int sumRange(int i, int j) {
			return _nums_sum[j] - _nums_sum[i-1];
		}
	private:
		vector<int> _nums_sum;
};


