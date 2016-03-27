#include<iostream>
#include<vector>

using namespace std;

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


int main(){
	int tmp[] = {1,2,3,4,5,6};
	vector<int> nums(tmp, tmp+sizeof(tmp)/sizeof(int));
	NumArray na(nums);
	int i=0;
	int j=2;
	cout << "sum range " << i<<"~"<<j<<" : " << na.sumRange(i, j) << endl;

	return 0;
}
