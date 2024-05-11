// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem112.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-09 21:46:43
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-11 22:01:26
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

// 递归法1
// class Solution {
// public:
//     void subPathSum(TreeNode* cur, vector<int>& path, vector<vector<int>>& result){
//         path.push_back(cur->val);
//         if (cur->left == NULL && cur->right == NULL){
//             result.push_back(path);
//         }
//         if (cur->left){
//             subPathSum(cur->left, path, result);
//             path.pop_back();  // 回溯
//         }
//         if (cur->right){
//             subPathSum(cur->right, path, result);
//             path.pop_back();  // 回溯
//         }

//     }

//     bool hasPathSum(TreeNode* root, int targetSum) {
//         vector<vector<int>> result;
//         vector<int> path;
//         if (root == NULL) return false;
//         subPathSum(root, path, result);
//         for (int i = 0; i < result.size(); i++){
//             int sum = 0;
//             for (int j = 0; j < result[i].size(); j++){
//                 sum += result[i][j];
//             }
//             std::cout << sum << std::endl;
//             if (sum == targetSum) return true;
//         }
//         return false;
//     }
// };


//递归法2来自代码随想录
// class Solution {
// public:
//     bool subPathSum(TreeNode* cur, int sum){
//         if (cur->left == NULL && cur->right == NULL && sum == 0) return true;
//         if (cur->left == NULL && cur->right == NULL) return false;
//         if (cur->left){
//             if (subPathSum(cur->left, sum - cur->left->val)) return true;
//         }
//         if (cur->right){
//             if (subPathSum(cur->right, sum - cur->right->val)) return true;
//         }
//         return false;
//     }

//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if (root == NULL) return false;
//         return subPathSum(root, targetSum - root->val);
//     }
// };

// 迭代法2来自代码随想录
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        stack<pair<TreeNode*, int>> node_val_st;
        node_val_st.push(pair<TreeNode*, int>(root, root->val));
        while (!node_val_st.empty()){
            pair<TreeNode*, int> cur = node_val_st.top();
            node_val_st.pop();
            if (cur.first->left == NULL && cur.first->right == NULL && cur.second == targetSum) return true;
            if (cur.first->right){
                node_val_st.push(pair<TreeNode*, int>(cur.first->right, cur.first->right->val + cur.second));
            }
            if (cur.first->left){
                node_val_st.push(pair<TreeNode*, int>(cur.first->left, cur.first->left->val + cur.second));
            }
        }
        return false;
    }
};
// @lc code=end

