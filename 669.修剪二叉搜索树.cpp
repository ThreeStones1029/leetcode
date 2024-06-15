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
 * @LastEditTime: 2024-06-15 23:20:50
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
    // 自己的方法之循环删除
    pair<TreeNode*, TreeNode*> FindFirstlowNode(TreeNode* root, int low) {
        if (root == NULL) {
            NULL;
        }
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur) {
            if (cur->val < low) break;
            else cur = cur->left;
        }
        return cur;
    }

    TreeNode* FindFirsthighNode(TreeNode* root, int high) {
        if (root == NULL) return NULL;
        TreeNode* cur = root;
        while (cur) {
            if (cur->val > high) break;
            else cur = cur->right;
        }
        return cur;
    }

    
    TreeNode* trimBST1(TreeNode* root, int low, int high) {
        if (root == NULL) return root;
        // 先找到第一个比low小的结点，这个结点的左子树都需要删除
        // 找到第一个比high大的结点，这个结点的右子树都需要删除
        TreeNode* first_low = FindFirstlowNode(root, low);
        TreeNode* first_high = FindFirsthighNode(root, high);
        if (first_low == NULL) 

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

