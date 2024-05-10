/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-09 21:46:43
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-09 22:54:00
 */
/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
// 感觉有点像前面的求所有路径
// 迭代法
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if (root == NULL) return false;
//         stack<TreeNode*> node_stack;
//         stack<vector<int>> all_path;
//         node_stack.push(root);
//         vector<int> path = {root->val};
//         all_path.push(path);
//         while (!node_stack.empty()){
//             TreeNode* cur = node_stack.top();
//             node_stack.pop();
//             vector<int> path = all_path.top();
//             all_path.pop();
//             if (cur->left == NULL && cur->right == NULL){
//                 int sum = 0;
//                 for (int i = 0; i < path.size(); i++){
//                     sum += path[i];
//                 }
//                 std::cout << sum << std::endl;
//                 if (sum == targetSum) return true;
//             }
//             if (cur->left) {
//                 path.push_back(cur->left->val);
//                 all_path.push(path);
//                 node_stack.push(cur->left);
//                 path.pop_back(); // 回溯
//             }
//             if (cur->right) {
//                 path.push_back(cur->right->val);
//                 all_path.push(path);
//                 node_stack.push(cur->right);
//                 path.pop_back();  // 回溯
//             } 
//         }
//         return false;
//     }
// };

// 递归法
class Solution {
public:
    void subPathSum(TreeNode* cur, vector<int> path, vector<vector<int>> result){
        if (cur->left == NULL && cur->right == NULL){
            result.push_back(path);
        }
        if (cur->left){
            path.push_back(cur->left->val);
            subPathSum(cur->left, path, result);
            path.pop_back;  // 回溯
        }

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        return false;
    }
};
// @lc code=end

