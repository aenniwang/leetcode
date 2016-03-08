class Solution{

public:
void subLevelOrderBottom(TreeNode* cur, int cur_level, vector<vector<int> > &result){
	if(cur==NULL)
		return;	
	if(cur_level > result.size())
		result.push_back(vector<int>());
	result[cur_level-1].push_back(cur->val);
	subLevelOrderBottom(cur->left, cur_level+1, result);
	subLevelOrderBottom(cur->right, cur_level+1, result);
	
}

vector<vector<int> > levelOrderBottom(TreeNode* root){
	vector<vector<int> > result;
	subLevelOrderBottom(root, 1, result);
	std::reverse(result.begin(), result.end());
	return result;
}

};
