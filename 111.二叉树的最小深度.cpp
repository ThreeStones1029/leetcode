/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-01 20:57:08
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-01 21:48:16
 */
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> node_queue;
        if (root != NULL) node_queue.push(root);
        int depth = 0;
        while(!node_queue.empty()){
            int size = node_queue.size();
            int num = 0;
            for (int i = 0; i < size; i++){
                TreeNode* cur = node_queue.front();
                node_queue.pop();
                if (cur->left != NULL) node_queue.push(cur->left);
                if (cur->right != NULL) node_queue.push(cur->right);
                if (cur->right == NULL && cur->left == NULL) num++;
            }
            depth++;
            if (num != 0) break;
            
        }
        return depth;
    }
};
// @lc code=end

