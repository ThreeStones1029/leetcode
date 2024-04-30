/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-30 19:52:31
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-30 20:00:50
 */
/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> node_queue;
        if (root != nullptr) node_queue.push(root);
        while (!node_queue.empty()){
            int size = node_queue.size();
            vector<int> layer;
            for (int i = 0; i < size; i++){
                TreeNode* cur = node_queue.front();
                if (cur->left != nullptr) node_queue.push(cur->left);
                if (cur->right != nullptr) node_queue.push(cur->right);
                layer.push_back(cur->val);
                node_queue.pop();
            }
            result.push_back(layer);
        }
        vector<int> max_value_result;
        for (int i = 0; i < result.size(); i++){
            int max = result[i][0];
            for (int j = 0; j < result[i].size(); j++){
                if (result[i][j] > max){
                    max= result[i][j];
                }
            }
            max_value_result.push_back(max);
        }
        return max_value_result;

    }
};
// @lc code=end

