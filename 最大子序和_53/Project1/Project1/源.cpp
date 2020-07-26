#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int result = nums[0];
        int Max = 0;
        for (int i = 0; i < len; i++) {
            Max = max(Max + nums[i], nums[i]);
            result = max(Max, result);
        }
        return result;
    }
};