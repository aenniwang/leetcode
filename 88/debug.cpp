#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
	if(nums2.size() != 0){
		vector<int> move_len;
		vector<int> insert_pos;
		int cur_move=0;
		for(int i=0; i<m;){
			if(nums1[i] >= nums2[cur_move] && cur_move < n){
				++cur_move;
				insert_pos.push_back(i+cur_move-1);
			}else{
				++i;
				move_len.push_back(cur_move);
			}
		}

		if(insert_pos.size() < n){
			for(int i=1; i<=(n-insert_pos.size()); i++){
				nums1[m+n-i] = nums2[n-i];
			}
		}
		for(int i=m-1; i>=0; i--){
			nums1[i+move_len[i]] = nums1[i];
		}
		for(int i=0; i<insert_pos.size(); i++){
			nums1[insert_pos[i]] = nums2[i]; 
		}

	}
}

int main(){
		
	vector<int> v_nums1(20);
	v_nums1[0] = 0; 	
	v_nums1[1] = 1; 	
	v_nums1[2] = 1; 	
	v_nums1[3] = 2; 	
	v_nums1[4] = 2; 	
	int nums2[] = {0, 3, 3};
	vector<int> v_nums2(nums2, nums2 + sizeof(nums2) / sizeof(int)); 	
	int m=5;
	int n=3;
	merge(v_nums1, m, v_nums2, n);
	for(int i=0; i<m+n; i++){
		cout << v_nums1[i] << endl;
	}
	return 0;
}
