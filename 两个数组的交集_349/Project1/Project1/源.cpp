#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (!nums1.size() || !nums2.size())return res;
        unordered_set<int> set1;
        unordered_set<int> set2;
        for (auto num : nums1)
            set1.insert(num);
        for (auto num : nums2) {
            if (set1.find(num) != set1.end())
                set2.insert(num);
        }
        res.assign(set2.begin(), set2.end());
        return res;
        
    }
};