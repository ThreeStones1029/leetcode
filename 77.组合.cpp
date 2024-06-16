/*
 * @Description:
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-16 16:02:41
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-16 23:20:33
 */
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> sub_result;
        int m = 1;
        for (int i = 1; i <= n;) {
            sub_result.push_back(i);
            while (m < k && i + k <= n + 1) {
                for (int j = i + m; j <= n; j++) {
                    sub_result.push_back(j);
                    break;
                }
                if (m == k - 1) {
                    results.push_back(sub_result);
                    // 回溯
                    sub_result.pop_back();
                    // sub_result.clear();
                }
                m++;
            }
            // 回溯
            m = 1;
            i++;
        }
        return results;
    }
};
// @lc code=end

