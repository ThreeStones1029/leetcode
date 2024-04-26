/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-04 21:33:23
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-04 23:37:55
 */
/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //暴力解法 会超时
        // int min_length = nums.size() + 1;
        // for (int i = 0; i < nums.size(); i++){
        //     int sum = 0;
        //     for (int j = i; j < nums.size(); j++){
        //         sum += nums[j];
        //         while (sum >= target){
        //         min_length = j - i + 1 < min_length ? (j - i + 1) : min_length;
        //         break;
        //         }
        //     }
            
        // }
        // return min_length == nums.size() + 1 ? 0 : min_length;

        // 滑动窗口解法
        int left= 0;
        int sum = 0;
        int min_length = __INT32_MAX__;
        for (int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                min_length = (right - left + 1) < min_length ? (right - left + 1) : min_length;
                sum -= nums[left++];
            }
        }
        return min_length == __INT32_MAX__? 0 : min_length;

    }
};
// @lc code=end

