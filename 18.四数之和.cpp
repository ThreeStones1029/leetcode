/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-10 22:18:22
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-11 12:29:09
 */
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 双指针法
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++){
            if (nums[k] > target && nums[k] >= 0) 
                break;
            // 对nums[k]去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++){
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                    break;
                }
                // 对nums[i]去重
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right){
                    if ((long)nums[right] + nums[left] + nums[i] + nums[k] > target){
                        right--;
                    }
                    else if ((long)nums[right] + nums[left] + nums[i] + nums[k] < target){
                        left++;
                    }
                    else{
                        result.push_back({nums[k], nums[i], nums[left], nums[right]});
                        while (right > left && nums[right] == nums[right - 1]){
                            right--;
                        }
                        while (right > left && nums[left] == nums[left + 1]){
                            left++;
                        }
                        right--;
                        left++;
                    }
                }
            }
            
        }
        
        return result;
    }
};


// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> result;
//         sort(nums.begin(), nums.end());
//         for (int k = 0; k < nums.size(); k++) {
//             // 剪枝处理
//             if (nums[k] > target && nums[k] >= 0) {
//             	break; // 这里使用break，统一通过最后的return返回
//             }
//             // 对nums[k]去重
//             if (k > 0 && nums[k] == nums[k - 1]) {
//                 continue;
//             }
//             for (int i = k + 1; i < nums.size(); i++) {
//                 // 2级剪枝处理
//                 if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
//                     break;
//                 }

//                 // 对nums[i]去重
//                 if (i > k + 1 && nums[i] == nums[i - 1]) {
//                     continue;
//                 }
//                 int left = i + 1;
//                 int right = nums.size() - 1;
//                 while (right > left) {
//                     // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
//                     if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
//                         right--;
//                     // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
//                     } else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target) {
//                         left++;
//                     } else {
//                         result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
//                         // 对nums[left]和nums[right]去重
//                         while (right > left && nums[right] == nums[right - 1]) right--;
//                         while (right > left && nums[left] == nums[left + 1]) left++;

//                         // 找到答案时，双指针同时收缩
//                         right--;
//                         left++;
//                     }
//                 }

//             }
//         }
//         return result;
//     }
// };

// @lc code=end

