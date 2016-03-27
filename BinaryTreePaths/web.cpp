
void subbinaryTreePaths(TreeNode* cur, vector<string> &result, vector<int> path){
	path.push_back(cur->val);
	if(cur->right != NULL)
		subbinaryTreePaths(cur->right, result, path);
	if(cur->left  != NULL)
		subbinaryTreePaths(cur->left, result, path);
	if(cur->left == NULL && cur->right == NULL){
		string str;
		for(int i=0; i<path.size(); i++){
			str += to_string(path[i]);
			if(i!=path.size()-1)
				str += "->";
		}
		result.push_back(str);
	}
}

vector<string> binaryTreePaths(TreeNode* root){
	vector<string> result;
	vector<int> path;
	if(root == NULL)
		subbinaryTreePaths(root, result, path);
	return result;
}

