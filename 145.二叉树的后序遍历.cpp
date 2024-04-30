// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem145.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-30 11:07:08
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-30 18:20:38
 */
/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
//     void traversal(vector<int>& result, TreeNode* cur){
//         if (cur != nullptr){
//             traversal(result, cur->left);
//             traversal(result, cur->right);
//             result.push_back(cur->val);
//         }
        
//     }

//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         traversal(result, root);
//         return result;

//     }
// };

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         stack<TreeNode*> node_stack;
//         TreeNode* cur = root;
//         if (root == nullptr){
//             return result;
//         }
//         node_stack.push(cur);
//         while (!node_stack.empty()){
//             cur = node_stack.top();
//             result.push_back(cur->val);
//             node_stack.pop();
//             if (cur->left != nullptr){
//                 node_stack.push(cur->left);
//             }
//             if (cur->right != nullptr){
//                 node_stack.push(cur->right);
//             }
//         }
//         reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
//         return result;

//     }
// };

// 统一迭代法
class Solution {
public:
    // 迭代法
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> node_stack;
        if (root != nullptr) node_stack.push(root);
        while (!node_stack.empty()){
            TreeNode* cur = node_stack.top();
            if (cur != nullptr){
                // 入栈中右左, 出栈左右中
                node_stack.pop();
                node_stack.push(cur);
                node_stack.push(nullptr);
                if (cur->right != nullptr) node_stack.push(cur->right);
                if (cur->left != nullptr) node_stack.push(cur->left);
                
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

