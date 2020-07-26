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
        //�������������ص�ֵ����Ϊ��ʱ��˵��p��q�����ڵ�ֱ�λ���������������ʱLCA����root
        if (left!=nullptr && right!=nullptr)return root;
        //��������������ֵ��һ��Ϊ��ʱ��˵��p��q�����ڵ�ͬʱλ���������������������������ȷ��ص��Ǹ�ֵ����LCA
        return left == nullptr ? right : left;
    }
};