// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem15.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-09 22:40:35
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-10 22:24:29
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
// class Solution {
// public:
//     bool comparison_of_triples(vector<int> &first, vector<int> &second){
//         if ((first[0] == second[0] && first[1] == second[1] && first[2] == second[2])){
//             return true;
//         }
//         if ((first[0] == second[0] && first[1] == second[2] && first[2] == second[1])){
//             return true;
//         }
//         if ((first[0] == second[1] && first[1] == second[0] && first[2] == second[2])){
//             return true;
//         }
//         if ((first[0] == second[1] && first[1] == second[2] && first[2] == second[0])){
//             return true;
//         }
//         if ((first[0] == second[2] && first[1] == second[0] && first[2] == second[1])){
//             return true;
//         }
//         if ((first[0] == second[2] && first[1] == second[1] && first[2] == second[0])){
//             return true;
//         }
//         return false;
//     }
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> result;
//         for (int i = 0; i < nums.size(); i++){
//             for (int j = i + 1; j < nums.size(); j++){
//                 for (int k = j + 1; k < nums.size(); k++){
//                     if (nums[i] + nums[j] + nums[k] == 0){
//                         vector<int> sub_result = {nums[i], nums[j], nums[k]};
//                         bool same = false;
//                         for (int row = 0; row < result.size(); row++){
//                             vector<int> row_result = {result[row][0], result[row][1], result[row][2]};
//                             if (comparison_of_triples(sub_result, row_result)){
//                                 same = true;
//                                 break;
//                             }
//                         }
//                         if (same == false){
//                             result.push_back(sub_result);
//                         }
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         // 双指针法
//         vector<vector<int>> result;
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size(); i++){
//             if (nums[i] > 0){
//                 return result;
//             }
//             if (i > 0 && nums[i] == nums[i-1]){
//                 continue;
//             }
//             int left = i + 1;
//             int right = nums.size() - 1;
//             while(left < right){
//                 if (nums[i] + nums[left] + nums[right] > 0){
//                     right--;
//                 }
//                 else if (nums[i] + nums[left] + nums[right] < 0){
//                     left++;
//                 }
//                 else{
//                     result.push_back({nums[i], nums[left], nums[right]});
//                     while (right > left && nums[left] == nums[left + 1]){
//                     left++;
//                     }
//                     while (right > left && nums[right] == nums[right - 1]){
//                         right--;
//                     }
//                     left++;
//                     right--;
//                 }
//             }
//         }
//         return result;
//     }
// };


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 哈希法
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0){
                return result;
            }
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if (nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }
                else{
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (right > left && nums[left] == nums[left + 1]){
                    left++;
                    }
                    while (right > left && nums[right] == nums[right - 1]){
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};

// @lc code=end

