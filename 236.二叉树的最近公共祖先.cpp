// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem236.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-09 15:38:40
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-09 22:25:30
 */
/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        if (root == p || root == q) return root;
        // 后续遍历
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) return root;
        else if (left == NULL && right != NULL){
            return right;
        } else if (left != NULL && right == NULL){
            return left;
        }
        else return NULL;
    }
};
// @lc code=end

