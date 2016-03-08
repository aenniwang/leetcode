#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

int main(){
	TreeNode* root = new TreeNode(3);
	TreeNode* node1 = new TreeNode(9);
	TreeNode* node2 = new TreeNode(20);
	TreeNode* node3 = new TreeNode(15);
	TreeNode* node4 = new TreeNode(7);
	root->left = node1;
	root->right = node2;
	node2->left = node3;
	node2->right = node4;
	vector<vector<int> > order = levelOrderBottom(root);
	for(int i=0; i<order.size(); i++){
		for(int j=0; j<order[i].size(); j++)
			cout << order[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
