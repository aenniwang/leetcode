
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

