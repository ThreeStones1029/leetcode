/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-30 11:06:21
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-30 11:49:46
 */
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void traversal(vector<int>& result, TreeNode* cur){
        if (cur != nullptr){
            traversal(result, cur->left);
            result.push_back(cur->val);
            traversal(result, cur->right);
        }
        
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(result, root);
        return result;

    }
};
// @lc code=end

