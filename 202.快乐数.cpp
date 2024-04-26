/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-08 21:37:17
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-08 22:15:10
 */
/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int sum_of_each_degree(int n){
        int sum = 0;
        int end_number = 0; // 最后一位数字
        int other_number = n; // 除最后一位数字的其余位
        while (other_number){
            end_number = other_number % 10;
            other_number = other_number / 10;
            sum += end_number* end_number;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> result;
        int sum = n;
        while (result.find(sum) == result.end()){
            if (sum == 1){
                return true;
            }
            result.insert(sum);
            sum = sum_of_each_degree(sum); 
        }
        return false;
    }
};
// @lc code=end

