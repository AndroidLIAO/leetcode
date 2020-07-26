#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //当左右子树返回的值都不为空时，说明p，q两个节点分别位于左右子树，则此时LCA就是root
        if (left!=nullptr && right!=nullptr)return root;
        //当左右子树返回值有一个为空时，说明p，q两个节点同时位于左子树（或右子树），则最先返回的那个值就是LCA
        return left == nullptr ? right : left;
    }
};