// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem216.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-17 23:06:39
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-18 22:39:13
 */
/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
// 先求组合，再判断是否满足条件
// class Solution {
// private:
//     vector<vector<int>> result;
//     vector<int> path;
//     void backtracking(int k, int startIndex) {
//         if (path.size() == k) {
//             result.push_back(path);
//             return;
//         }
//         for (int i = startIndex; i <= 10 - (k - path.size()); i++) {
//             path.push_back(i);
//             backtracking(k, i+1);
//             path.pop_back();
//         }
//     }


// public:
//     vector<vector<int>> combinationSum3(int k, int n) {
//         backtracking(k, 1);
//         vector<vector<int>> consistent_result;
//         for (int i = 0; i < result.size(); i++) {
//             int sum = 0;
//             for (int j = 0; j < result[i].size(); j++) {
//                 sum += result[i][j];
//             }
//             if (sum == n) {
//                 consistent_result.push_back(result[i]);
//             }
//         }
//         return consistent_result;
//     } 
// };

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int k, int startIndex, int sum, int n) {
        if (sum > n) { // 剪枝操作
            return; 
        }
        if (path.size() == k) {
            if (sum == n) result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 10 - (k - path.size()); i++) {
            sum += i;
            path.push_back(i);
            backtracking(k, i+1, sum, n);
            path.pop_back();
            sum -= i;
        }
    }


public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, 1, 0, n);
        return result;
    } 
};
// @lc code=end

