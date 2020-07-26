#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        int result = 0;
        /*while (true) {
            fast = ((fast+2)>n)?(fast+1-n):(fast+2);
            slow = ((slow+1)>n)?0:(slow+1);
            if (fast==slow) {//第一次相遇
                while (true) {
                    fast = ((fast + 2) > n) ? (fast+1-n) : (fast + 2);
                    slow = ((slow + 1) > n) ? 0 : (slow + 1);
                    if (fast==slow) {
                        result = nums[slow];
                        break;
                    }
                }
            }
            if (result != 0)break;
        }*/
        while (true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            while (slow == fast) {
                fast = 0;
                if (nums[fast] != nums[slow]) {
                    fast = nums[fast];
                    slow = nums[slow];
                }
                result = nums[slow];
                break;
            }
        }
        return result;
    }
};
int main() {
    vector<int> nums{ 1,3,4,2,2 };
    Solution s;
    cout << s.findDuplicate(nums) << endl;
    return 0;
}