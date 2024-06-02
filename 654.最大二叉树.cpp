// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem654.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-17 22:47:52
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-18 10:09:59
 */
/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         if (nums.size() == 0) return NULL;
//         int max = nums[0];
//         int max_index = 0;
//         for (int index = 0; index < nums.size(); index++){
//             if (nums[index] > max){
//                 max = nums[index];
//                 max_index = index;
//             }
//         }
//         TreeNode* root = new TreeNode(nums[max_index]);
//         vector<int> nums_left(nums.begin(), nums.begin() + max_index);
//         vector<int> nums_right(nums.begin() + max_index + 1, nums.end());
//         root->left = constructMaximumBinaryTree(nums_left);
//         root->right = constructMaximumBinaryTree(nums_right);
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* traversal(vector<int>& nums, int nums_begin, int nums_end){
        if (nums_end - nums_begin == 0) return NULL;
        int max = nums[nums_begin];
        int max_index = nums_begin;
        for (int i = nums_begin; i < nums_end; i++){
            if (nums[i] > max){
                max = nums[i];
                max_index = i;
            }
        }

        TreeNode* root = new TreeNode(nums[max_index]);
        int nums_left_begin = nums_begin;
        int nums_left_end = max_index;
        int nums_right_begin = max_index + 1;
        int nums_right_end = nums_end;
        root->left = traversal(nums, nums_left_begin, nums_left_end);
        root->right = traversal(nums, nums_right_begin, nums_right_end);
        return root;
    }


    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return traversal(nums, 0, nums.size());
    }
};
// @lc code=end

