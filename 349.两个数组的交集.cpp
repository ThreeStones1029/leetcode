/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-08 20:49:21
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-08 21:31:17
 */
/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
// 暴力解法
// class Solution {
// public:
//     bool is_in_vector(vector<int>& nums, int val){
//         for (int i = 0; i < nums.size(); i++){
//             if (nums[i] == val){
//                 return true;
//             }
//         }
//         return false;
//     }
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> intersection_array;
//         for (int i = 0; i < nums1.size(); i++){
//             for (int j = 0; j < nums2.size(); j++){
//                 if (nums2[j] == nums1[i] && !is_in_vector(intersection_array, nums1[i])){
//                     intersection_array.push_back(nums1[i]);
//                     break;
//                 }
//             }
//         }
//         return intersection_array;
//     }
// };

// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         // 数组法
//         int result1[1001] = {0};
//         int result2[1001] = {0};
//         vector<int> result;
//         for (int i = 0; i < nums1.size(); i++){
//             result1[nums1[i]]++;
//         }
//         for (int i = 0; i < nums2.size(); i++){
//             result2[nums2[i]]++;
//         }
//         for (int i = 0; i < 1001; i++){
//             if (result1[i] != 0 && result2[i] != 0){
//                 result.push_back(i);
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // unordered_set
        unordered_set<int> result_set;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        for (int num : nums2){
            if (nums1_set.find(num) != nums1_set.end()){
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
// @lc code=end

