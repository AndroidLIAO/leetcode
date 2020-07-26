#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/**
	µÝ¹é·½·¨£º³¬Ê±
	int rob(TreeNode* root) {
		return tryrob(root);
	}
	int tryrob(TreeNode* root) {
		if (root == nullptr)return 0;
		int val = 0;
		if (root->left != nullptr)val += rob(root->left->left) + rob(root->left->right);
		if (root->right != nullptr)val += rob(root->right->left) + rob(root->right->right);
		int res = max(rob(root->left) + rob(root->right), root->val + val);
		return res;
	}**/
	pair<int, int> dfs(TreeNode* root) {
		if (root == nullptr) {
			return { 0, 0 };
		}
		auto left_pair = dfs(root->left);
		auto right_pair = dfs(root->right);
		return { root->val + left_pair.second + right_pair.second,
				max(left_pair.first, left_pair.second) + max(right_pair.first, right_pair.second) };
	}

	int rob(TreeNode* root) {
		auto p = dfs(root);
		return max(p.first, p.second);
	}

};