#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>>res;
	vector<int>path;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.size() < 1)return res;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, 0, 0, target);
		return res;
	}

	void dfs(vector<int>& candidates, int start, int add, int target) {
		if (add >= target) {
			if (target == add)
				res.push_back(path);
			return;
		}
		for (int j = start; j < candidates.size(); j++) {
			if (j>start&&candidates[j] == candidates[j-1])continue;
			if (candidates[j] > target)continue;
			path.push_back(candidates[j]);
			dfs(candidates, j + 1, add + candidates[j], target);
			path.pop_back();
		}
	}
};