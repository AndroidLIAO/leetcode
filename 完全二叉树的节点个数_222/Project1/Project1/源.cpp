#include<iostream>
#include<deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)return 0;
        deque<TreeNode*> d;
        int res = 0;
        d.push_back(root);
        while (!d.empty()) {
            int len = d.size();
            res += len;
            int i = 0;
            while (i++ < len) {
                TreeNode* temp = d.front();
                d.pop_front();
                if (temp->left != nullptr)d.push_back(temp->left);
                if (temp->right != nullptr)d.push_back(temp->right);
            }
        }
        return res;
    }
};