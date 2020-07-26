#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)return 0;
        vector<int> dp(m, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0) {
                    dp[j] = dp[j];
                    continue;
                }
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[m - 1];
    }
};