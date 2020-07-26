#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> res;
    string path;
    vector<string> table{ "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    vector<string> letterCombinations(string digits) {
        if (digits.size() < 1)return res;
        dfs(digits, 0);
        return res;
    }

    void dfs(string digits,  int depth) {
        if (depth == digits.size()) {
            res.push_back(path);
            return;
        }
        for (unsigned int i = 0; i < table[digits[depth] - '2'].size(); i++) {
            path.push_back(table[digits[depth] - '2'][i]);
            dfs(digits, depth + 1);
            path.pop_back();
        }
    }
};