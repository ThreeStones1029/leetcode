// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem404.h"
#include <stack>
using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-08 21:18:02
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-08 22:47:20
 */
/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
// 前序遍历迭代法
// class Solution {
// public:
//     int sumOfLeftLeaves(TreeNode* root) {
//          int result = 0;
//          stack<TreeNode*> node_stack;
//          node_stack.push(root);
//          while (!node_stack.empty()){
//             TreeNode* cur = node_stack.top();
//             //std::cout << cur->val << std::endl;
//             node_stack.pop();
//             if (cur->left != NULL) {
//                 node_stack.push(cur->left);
//                 if (cur->left->right == NULL && cur->left->left == NULL){
//                     result += cur->left->val;
//                 }
//             }
//             if (cur->right != NULL) node_stack.push(cur->right);
//          }
//          return result;
//     }
// };

// 中序遍历迭代法
// class Solution {
// public:
//     int sumOfLeftLeaves(TreeNode* root) {
//          int result = 0;
//          stack<TreeNode*> node_stack;
//          TreeNode* cur = root;
//          while (cur != NULL || !node_stack.empty()){
//             if (cur != NULL){
//                 node_stack.push(cur);
//                 cur = cur->left;
//             }
//             else{
//                 cur = node_stack.top();
//                 if (cur->left != NULL && cur->left->left == NULL && cur->left->right == NULL){
//                     result += cur->left->val;
//                 }
//                 node_stack.pop();
//                 cur = cur->right;
//             }
//          }
//          return result;
//     }
// };

// 后序遍历递归法
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int leftvalue = sumOfLeftLeaves(root->left);
        if (root->left && !root->left->left && !root->left->right) { // 左子树就是一个左叶子的情况
            leftvalue = root->left->val;
        }
        int rightvalue = sumOfLeftLeaves(root->right);
        int sum = leftvalue + rightvalue;
        return sum;
    }
};

// @lc code=end

