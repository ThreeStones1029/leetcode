// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem222.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-02 23:06:28
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-07 21:01:45
 */
/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
//     int countNodes(TreeNode* root) {
//         stack<TreeNode*> node_stack;
//         if (root == NULL) return 0;
//         node_stack.push(root);
//         int num = 0;
//         while (!node_stack.empty()){
//             TreeNode* cur = node_stack.top();
//             num += 1;
//             node_stack.pop();
//             if (cur->left != NULL) node_stack.push(cur->left);
//             if (cur->right != NULL) node_stack.push(cur->right);
//         }
//         return num;
//     }
// };

// 中序遍历迭代法 左中右
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         stack<TreeNode*> node_stack;
//         if (root == NULL) return 0;
//         TreeNode* cur = root;
//         int num = 0;
//         while (cur != NULL || !node_stack.empty()){
//             if (cur != NULL){
//                 node_stack.push(cur);
//                 cur = cur->left;
//             }
//             else{
//                 cur = node_stack.top();
//                 node_stack.pop();
//                 cur = cur->right;
//                 num += 1;
//             }
//         }
//         return num;
//     }
// };

// 后序遍历迭代法
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         stack<TreeNode*> node_stack;
//         if (root == NULL) return 0;
//         node_stack.push(root);
//         int num = 0;
//         while (!node_stack.empty()){
//             TreeNode* cur = node_stack.top();
//             num += 1;
//             node_stack.pop();
//             if (cur->right != NULL) node_stack.push(cur->right);
//             if (cur->left != NULL) node_stack.push(cur->left);  
//         }
//         return num;
//     }
// };

// 后序遍历递归法
// class Solution {
// public:
//     int getNodesNum(TreeNode* cur) {
//         if (cur == NULL) return 0;
//         int leftNum = getNodesNum(cur->left);      // 左
//         int rightNum = getNodesNum(cur->right);    // 右
//         int treeNum = leftNum + rightNum + 1;      // 中
//         return treeNum;
//     }


//     int countNodes(TreeNode* root) {
//         return getNodesNum(root);
//     }
// };

// 层序遍历迭代法
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         int num = 0;
//         if (root == NULL) return num;
//         queue<TreeNode*> node_queue;
//         node_queue.push(root);
//         while (!node_queue.empty()){
//             int size = node_queue.size();
//             for (int i = 0; i < size; i++){
//                 TreeNode* cur = node_queue.front();
//                 if (cur->left != NULL) node_queue.push(cur->left);
//                 if (cur->right != NULL) node_queue.push(cur->right);
//                 node_queue.pop(); 
//             }
//             num += size;
//         }
//         return num;
//     }
// };

// 前序遍历统一迭代法
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         int num = 0;
//         stack<TreeNode*> node_stack;
//         if (root != NULL) node_stack.push(root);
//         while (!node_stack.empty()){
//             TreeNode* cur = node_stack.top();
//             if (cur != NULL){
//                 // 入栈顺序右左中,出栈顺序中左右
//                 node_stack.pop();
//                 if (cur->right != nullptr) node_stack.push(cur->right);
//                 if (cur->left != nullptr) node_stack.push(cur->left);
//                 node_stack.push(cur);
//                 node_stack.push(nullptr);
//             }
//             else{
//                 // 只有遇到空节点的时候，才将下一个节点放进结果集
//                 node_stack.pop();
//                 cur = node_stack.top();
//                 num += 1;
//                 node_stack.pop();
//             }
//         }
//         return num;
//     }
// };

// 中序遍历统一迭代法
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         int num = 0;
//         stack<TreeNode*> node_stack;
//         if (root != NULL) node_stack.push(root);
//         while (!node_stack.empty()){
//             TreeNode* cur = node_stack.top();
//             if (cur != NULL){
//                 // 入栈顺序右中左,出栈顺序左中右
//                 node_stack.pop();
//                 if (cur->right != nullptr) node_stack.push(cur->right);
//                 node_stack.push(cur);
//                 node_stack.push(nullptr);
//                 if (cur->left != nullptr) node_stack.push(cur->left);
//             }
//             else{
//                 // 只有遇到空节点的时候，才将下一个节点放进结果集
//                 node_stack.pop();
//                 cur = node_stack.top();
//                 num += 1;
//                 node_stack.pop();

//             }
//         }
//         return num;
//     }
// };

// 后序遍历统一迭代法
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         int num = 0;
//         stack<TreeNode*> node_stack;
//         if (root != NULL) node_stack.push(root);
//         while (!node_stack.empty()){
//             TreeNode* cur = node_stack.top();
//             if (cur != NULL){
//                 // 入栈顺序中右左,出栈顺序左右中
//                 node_stack.pop();
//                 node_stack.push(cur);
//                 node_stack.push(nullptr);
//                 if (cur->right != nullptr) node_stack.push(cur->right);
//                 if (cur->left != nullptr) node_stack.push(cur->left);
//             }
//             else{
//                 // 只有遇到空节点的时候，才将下一个节点放进结果集
//                 node_stack.pop();
//                 cur = node_stack.top();
//                 num += 1;
//                 node_stack.pop();
//             }
//         }
//         return num;
//     }
// };

// 后序遍历统一迭代法
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_depth = 0;
        int right_depth = 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while (left){
            left = left->left;
            left_depth++;
        }
        while (right){
            right = right->right;
            right_depth++;
        }
        if (left_depth == right_depth) {
            return (2 << left_depth) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end

