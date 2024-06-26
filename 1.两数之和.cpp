/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-08 22:21:21
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-09 20:36:52
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            // 遍历当前元素，并在map中寻找是否有匹配的key
            auto iter = map.find(target - nums[i]); 
            if(iter != map.end()) {
                return {iter->second, i};
            }
            // 如果没找到匹配对，就把访问过的元素和下标加入到map中
            map.insert(pair<int, int>(nums[i], i)); 
        }
        return {};
        // 暴力解法
        // vector<int> result;
        // for (int i = 0; i < nums.size(); i++){
        //     for (int j = i + 1; j < nums.size(); j++){
        //         if (nums[i] + nums[j] == target){
        //             result.push_back(i);
        //             result.push_back(j);
        //         }
        //     }
            
        // }
        // return result;
    }   
};
// @lc code=end

