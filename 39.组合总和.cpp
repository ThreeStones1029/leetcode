// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem39.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-19 23:13:48
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-20 22:21:53
 */
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
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

    // 暴力解法 会超时,原因在于时间过多的用在排除重复组合
    void backtracking(vector<int>& candidates, int target) {
        if (sum > target) {
            return;
        }
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
            for (int i = 0; i < candidates.size(); i++) {
                sum += candidates[i];
                path.push_back(candidates[i]);
                backtracking(candidates, target);
                sum -= candidates[i];
                path.pop_back();
            }
        }
    }

    // 加入开始下标，每种情况表示相当于固定不同的数字个数
    void backtracking1(vector<int>& candidates, int target, int start) {
        if (sum > target) {
            return;
        }
        else if (sum == target) {
            result.push_back(path);
            return;
        }
        else {
            for (int i = start; i < candidates.size(); i++) {
                sum += candidates[i];
                path.push_back(candidates[i]);
                backtracking1(candidates, target, i);
                sum -= candidates[i];
                path.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking1(candidates, target, 0);
        return result;
    }
};
// @lc code=end

