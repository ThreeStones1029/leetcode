// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem108.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-11 22:48:57
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-13 22:40:14
 */
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
class Solution {
public:
    // 中序遍历递归 左闭右开
    TreeNode* transval(vector<int>& nums, int start, int end) {
        if (end - start == 0) return NULL;
        else if (end - start == 1) {
            TreeNode* cur = new TreeNode(nums[start]);
            return cur;
        }
        else{
            int mid = (start + end) / 2;
            TreeNode* cur = new TreeNode(nums[mid]);
            cur->left = transval(nums, start, mid);
            cur->right = transval(nums, mid + 1, end);
            return cur;
        }
    }

    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        root = transval(nums, 0, nums.size());
        return root;
    }
};
// @lc code=end

