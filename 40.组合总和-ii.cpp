// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem40.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;

    // 比较两个数组是否一样
    bool issame_vector(vector<int> array1, vector<int> array2) {
        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());
        if (array1.size() == array2.size()) {
            int i;
            for (i = 0; i < array1.size(); i++) {
                if (array1[i] != array2[i]) break;
            }
            if (i == array1.size()) return true;
            else return false;
        }
        else return false;
    }

    void backtracking(vector<int>& candidates, int target, int start) {
        if (sum > target) return;
        else if (sum == target) {
            // 判断是否有一样的数组，没有则加入
            bool is_exist = false;
            for (int i = 0; i < result.size(); i++) {
                if (issame_vector(path, result[i])) is_exist = true;
            }
            if (!is_exist) result.push_back(path);
            return;
        }
        else {
            for (int i = start; i < candidates.size(); i++) {
                sum += candidates[i];
                path.push_back(candidates[i]);
                backtracking(candidates, target, i + 1);
                sum -= candidates[i];
                path.pop_back();
            }
        }
    }

    void backtracking1(vector<int>& candidates, int target, int start) {
        if (sum > target) return;
        else if (sum == target) {
            result.push_back(path);
        }
        else {
            for (int i = start; i < candidates.size(); i++) {
                // 要对同一树层使用过的元素进行跳过
                if (i > start && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                sum += candidates[i];
                path.push_back(candidates[i]);
                backtracking1(candidates, target, i + 1);
                sum -= candidates[i];
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // backtracking(candidates, target, 0);
        sort(candidates.begin(), candidates.end());
        backtracking1(candidates, target, 0);
        return result;
    }
};
// @lc code=end

