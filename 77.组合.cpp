// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem77.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description:
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-16 16:02:41
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-17 23:03:22
 */
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { // 优化的地方
            path.push_back(i); // 处理节点
            backtracking(n, k, i + 1);
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }

    void backtracking2(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);
            backtracking2(n, k, i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtracking2(n, k, 1);
        return result;
    }
};
// @lc code=end

