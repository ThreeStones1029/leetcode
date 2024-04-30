/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-30 18:31:09
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-30 19:15:20
 */
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 队列实现
        vector<vector<int>> result;
        queue<TreeNode*> node_queue;
        if (root != nullptr) node_queue.push(root);
        while (!node_queue.empty()){
            int size = node_queue.size();
            vector<int> every_layer;
            for (int i = 0; i < size; i++){
                TreeNode* cur = node_queue.front();
                if (cur->left != nullptr) node_queue.push(cur->left);
                if (cur->right != nullptr) node_queue.push(cur->right);
                every_layer.push_back(cur->val);
                node_queue.pop();
            }
            result.push_back(every_layer);
        }
        return result;

    }
};
// @lc code=end

