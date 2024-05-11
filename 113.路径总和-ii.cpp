/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-11 22:05:02
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-11 22:37:53
 */
/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
//     // 递归法
//     void subPathSum(TreeNode* cur, vector<int>& single_path,vector<vector<int>>& result, int value){
//         single_path.push_back(cur->val);
//         if (cur->left == NULL && cur->right == NULL && value == 0) result.push_back(single_path);
//         if (cur->left) {
//             subPathSum(cur->left, single_path, result, value - cur->left->val);
//             single_path.pop_back();  // 回溯
//         }
//         if (cur->right) {
//             subPathSum(cur->right, single_path, result, value - cur->right->val);
//             single_path.pop_back();  // 回溯
//         }
//     }
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         vector<vector<int>> result;
//         vector<int> single_path;
//         if (root == NULL) return result;
//         subPathSum(root, single_path, result, targetSum - root->val);
//         return result;
//     }
// };

// 迭代法
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        stack<vector<int>> vector_st;
        if (root == NULL) return result;
        stack<TreeNode*> node_st;
        node_st.push(root);
        vector_st.push({root->val});
        while (!node_st.empty()){
            TreeNode* cur = node_st.top();
            node_st.pop();
            vector<int> single_path = vector_st.top();
            vector_st.pop();
            if (cur->left == NULL && cur->right == NULL){
                int sum = 0;
                for (int i = 0; i < single_path.size(); i++){
                    sum += single_path[i];
                }
                if (sum == targetSum){
                    result.push_back(single_path);
                }
            }
            if (cur->left){
                node_st.push(cur->left);
                single_path.push_back(cur->left->val);
                vector_st.push(single_path);
                single_path.pop_back();  // 回溯
            }
            if (cur->right){
                node_st.push(cur->right);
                single_path.push_back(cur->right->val);
                vector_st.push(single_path);
                single_path.pop_back();  // 回溯
            }

        }
        return result;
    }
};
// @lc code=end

