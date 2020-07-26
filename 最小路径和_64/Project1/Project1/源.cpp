#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m, 0);
        for (int i = 0; i < m; i++) {
            if (i == 0)dp[i] = grid[0][i];
            else {
                dp[i] = dp[i-1] + grid[0][i];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0) {
                    dp[i] = dp[i] + grid[i][j];
                }
                else {
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
                }
            }
        }
        return dp[m - 1];
    }
};