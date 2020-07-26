#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        if (n == 0)return res;
        dfs("", n, 0, 0);
        return res;

    }
    void dfs(string str, int n,int left,int right) {
        if (left > n || right > n || right > left)return;
        if (left == n) {
            res.push_back(str);
            return;
        }
        dfs(str+'(', n, left + 1, right);
        dfs(str+')', n, left, right + 1);
    }
};