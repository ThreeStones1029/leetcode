/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-10 15:55:38
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-10 16:23:11
 */
/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    // 迭代法
    TreeNode* insertIntoBST1(TreeNode* root, int val) {
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur) {
            pre = cur;
            if (val > cur->val) cur = cur->right;
            else cur = cur->left;
        }
        TreeNode* node = new TreeNode(val);
        if (pre == NULL) return node;
        if (pre->val > val) pre->left = node;
        else pre->right = node;
        return root;
    }

    // 递归法
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};
// @lc code=end

