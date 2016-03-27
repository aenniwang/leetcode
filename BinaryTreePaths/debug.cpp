#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

int main(){
	TreeNode* root = new TreeNode(1);	
	TreeNode* node1 = new TreeNode(2);	
	TreeNode* node2 = new TreeNode(3);	
	TreeNode* node3 = new TreeNode(5);
	root->left = node1;
	root->right = node2;
	node1->right = node3;
	vector<string> result = binaryTreePaths(root);
	for(int i=0; i<result.size(); i++){
		cout << result[i] << endl;
	}
	return 0;
}
