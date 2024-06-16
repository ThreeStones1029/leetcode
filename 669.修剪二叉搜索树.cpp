// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem669.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-11 22:47:39
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-16 11:05:45
 */
/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode* trimBST1(TreeNode* root, int low, int high) {
        if (root == NULL) return root;
        // 处理头结点，让root移动到[L, R] 范围内，注意是左闭右闭
        while (root != NULL && (root->val < low || root->val > high)) {
            if (root->val < low) root = root->right;
            else root = root->left;
        }
        TreeNode *cur = root;
        while (cur != NULL) {
            while (cur->left && cur->left->val < low) {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        cur = root;
        while (cur != NULL) {
            while (cur->right && cur->right->val > high) {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }

    // 递归法
    TreeNode* trimBST2(TreeNode* root, int low, int high) {
        if (root == NULL) return NULL;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trimBST1(root, low, high);
        // return trimBST2(root, low, high);
    }
};
// @lc code=end

