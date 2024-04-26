/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-03 23:46:03
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-04 00:25:21
 */
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 暴力解法
        // int n = nums.size();
        // for (int i = 0; i < n; i++){
        //     if (nums[i] == val){
        //         for (int j = i + 1; j < n; j++){
        //             nums[j - 1] = nums[j];
        //         }
        //         i--;
        //         n--;
        //     }
            
        // }
        // return n;

        // 双指针法
        int n = nums.size();
        int right = 0;
        int left = 0;
        for (int right = 0; right < n; right++){
            // 找第一个不等于的值放到数组前
            if (nums[right] != val){
                nums[left++] = nums[right];
            }
        }
        return left;
    }
};
// @lc code=end

