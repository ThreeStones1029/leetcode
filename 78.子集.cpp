// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem78.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> results;
    std::vector<int> single_assemble;
    void backtrack(const vector<int>& nums, int start) {
        results.push_back(single_assemble);
        if (start >= nums.size()) {
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            single_assemble.push_back(nums[i]);
            backtrack(nums, i+1);
            single_assemble.pop_back();
        }
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return results;
    }
};
// @lc code=end

