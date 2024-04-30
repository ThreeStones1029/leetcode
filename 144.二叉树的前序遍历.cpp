// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem144.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-30 11:03:44
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-30 18:15:23
 */
/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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

// 递归法
// class Solution {
// public:
//     void traversal(vector<int> &result, TreeNode* cur){
//         if (cur != nullptr){
//             result.push_back(cur->val);
//             traversal(result, cur->left);
//             traversal(result, cur->right);
//         }
//     }
    
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         traversal(result, root);
//         return result;

//     }
// };

// class Solution {
// public:
//     // 迭代法
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         if (root == nullptr){
//             return result;
//         }
//         stack<TreeNode*> result_stack;
//         result_stack.push(root);
//         while (!result_stack.empty()){
//             TreeNode* cur = result_stack.top();
//             result.push_back(cur->val);
//             result_stack.pop();
//             if (cur->right != nullptr){
//                 result_stack.push(cur->right);
//             }
//             if (cur->left != nullptr){
//                 result_stack.push(cur->left);
//             }
//         }
//         return result;

//     }
// };

// 统一迭代法
class Solution {
public:
    // 迭代法
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> node_stack;
        if (root != nullptr) node_stack.push(root);
        while (!node_stack.empty()){
            TreeNode* cur = node_stack.top();
            if (cur != nullptr){
                // 入栈右左中, 出栈中左右
                node_stack.pop();
                if (cur->right != nullptr) node_stack.push(cur->right);
                if (cur->left != nullptr) node_stack.push(cur->left);
                node_stack.push(cur);
                node_stack.push(nullptr);
            }
            else{
                node_stack.pop();
                cur = node_stack.top();
                result.push_back(cur->val);
                node_stack.pop();
            }
        }
        return result;

    }
};
// @lc code=end

