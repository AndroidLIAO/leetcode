#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        /**int n = obstacleGrid.size();
        if (n == 0)return 0;
        int m = obstacleGrid[0].size();
        vector<int> dp(m, 0);
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[0][i] == 1)continue;
            if (i == 0)
                dp[i] = 1;
            else
                dp[i] =dp[i - 1];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i] = 0;
                    continue;
                }
                if (j == 0) { 
                    dp[j] = dp[j];
                    continue;
                }
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[m - 1];**/
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<long long> res(n, 0);
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1)
                res[j] = 0;
            else {
                if (j == 0)
                    res[j] = 1;
                else
                    res[j] = res[j - 1] + res[j];
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    res[j] = 0;
                else {
                    if (j == 0)
                        res[j] = res[j];
                    else
                        res[j] = res[j - 1] + res[j];
                }
            }
        }
        return res[n - 1];
    }
};
int main() {
    vector<vector<int>> obstacleGrid = { {1,0} };
    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;;
    return 0;
}