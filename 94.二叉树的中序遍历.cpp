// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem94.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-30 11:06:21
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-30 17:42:06
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

// 递归法
// class Solution {
// public:
//     void traversal(vector<int>& result, TreeNode* cur){
//         if (cur != nullptr){
//             traversal(result, cur->left);
//             result.push_back(cur->val);
//             traversal(result, cur->right);
//         }
        
//     }

//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         traversal(result, root);
//         return result;

//     }
// };

// 迭代法
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         stack<TreeNode*> node_stack;
//         TreeNode* cur = root;
//         while (cur != nullptr || !node_stack.empty()){
//             if (cur != nullptr){
//                 node_stack.push(cur);
//                 cur = cur->left;
//             }
//             else{
//                 cur = node_stack.top();
//                 result.push_back(cur->val);
//                 node_stack.pop();
//                 cur = cur->right;
//             }
//         }
//         return result;
//     }
// };

// 统一迭代法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> node_stack;
        if (root != nullptr) node_stack.push(root);
        while (!node_stack.empty()){
            TreeNode* cur = node_stack.top();
            if (cur != nullptr){
                // 入栈顺序右中左,出栈顺序左中右
                node_stack.pop();
                if (cur->right != nullptr) node_stack.push(cur->right);
                node_stack.push(cur);
                node_stack.push(nullptr);
                if (cur->left != nullptr) node_stack.push(cur->left);
            }
            else{
                // 只有遇到空节点的时候，才将下一个节点放进结果集
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

