/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-03 22:17:53
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-03 22:40:55
 */
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 第一种左闭右开
        int size = nums.size();
        int right = size;
        int left = 0;
        while (left < right){
            int mid = (right + left) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] > target){
                right = mid;  
            }
            else{
                left = mid + 1;
            }
            
        }
        return -1;

        // 第二种左闭右闭
        // int size = nums.size();
        // int right = size - 1;
        // int left = 0;
        // while (left <= right){
        //     int mid = (left + right) / 2;
        //     if (nums[mid] == target){
        //         return mid;
        //     }
        //     else if (nums[mid] > target){
        //         right = mid - 1;
        //     }
        //     else{
        //         left = mid + 1;
        //     }
            
        // }
        // return -1;

    }
};
// @lc code=end

