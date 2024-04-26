/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-04 20:33:45
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-04 21:32:42
 */
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 双指针法
        // int left = 0;
        // int right = nums.size() - 1;
        // int index = right;
        // vector<int> new_nums(nums);
        // while (left <= right){
        //     if (nums[left] * nums [left] > nums[right] * nums[right]){
        //         new_nums[index--] = nums[left] * nums [left];
        //         left++;
        //     }
        //     else {
        //         new_nums[index--] = nums[right] * nums[right];
        //         right--;
        //     }
        // }
        // return new_nums;
        //暴力法
        for (int i = 0; i < nums.size(); i++){
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
    
};
// @lc code=end

