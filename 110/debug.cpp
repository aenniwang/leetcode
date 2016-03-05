#include<iostream>

using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool subIsBalanced(TreeNode* cur, int& cur_depth){
	if(cur == NULL)
		return true;
	int left_depth = cur_depth+1; 
	int right_depth = cur_depth+1;
	bool isLeftBalanced = subIsBalanced(cur->left, left_depth);
	bool isRightBalanced = subIsBalanced(cur->right, right_depth);
	cur_depth = (left_depth > right_depth) ? left_depth : right_depth;
	if(!isLeftBalanced || !isRightBalanced)
		return false;
	if((left_depth-right_depth) > 1 || (left_depth-right_depth) < -1)
		return false;
	else
		return true;
}

bool isBalanced(TreeNode* root){
	if(root == NULL){
		return true;
	}else{
		int cur_depth = 0;
		return subIsBalanced(root, cur_depth);
	}
}

int main(){
	TreeNode* root = new TreeNode(1);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(3);
	root->left = NULL;
	root->right = node1;
	node1->left = NULL;
	node1->right = node2;
	cout << "Is balanced? " << isBalanced(root) << endl;
	return 0;
}
