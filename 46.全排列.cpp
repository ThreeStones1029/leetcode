/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> results;
    vector<int> path;
    void backtrack(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            results.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return results;
    }
};
// @lc code=end

