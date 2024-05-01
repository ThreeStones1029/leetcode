/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-01 21:51:52
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-01 22:53:14
 */
/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
// 前序遍历递归
// class Solution {
// public:
//     void invert(TreeNode* cur){
//         if (cur != NULL){
//             TreeNode* tmp = cur->right;
//             cur->right = cur->left;
//             cur->left = tmp;
//             invert(cur->left);
//             invert(cur->right);
//         }
//     }
//     TreeNode* invertTree(TreeNode* root) {
//         invert(root);
//         return root;

//     }
// };

// 中序遍历递归
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (root == NULL) return root;
//         invertTree(root->left);
//         swap(root->left, root->right);
//         // 重复翻转左子树,因为交换了
//         invertTree(root->left);
//         return root;
//     }
// };

// 前序遍历迭代
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (root == NULL) return root;
//         stack<TreeNode*> node_stack;
//         node_stack.push(root);
//         while(!node_stack.empty()){
//             TreeNode* cur = node_stack.top();
//             node_stack.pop();
//             swap(cur->left, cur->right);
//             if (cur->left != NULL) node_stack.push(cur->left);
//             if (cur->right != NULL) node_stack.push(cur->right);
//         }
//         return root;

//     }
// };

// 层序遍历
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (root == NULL) return root;
//         queue<TreeNode*> node_queue;
//         node_queue.push(root);
//         while (!node_queue.empty()){
//             int size = node_queue.size();
//             for (int i = 0; i < size; i++){
//                 TreeNode* cur = node_queue.front();
//                 swap(cur->left, cur->right);
//                 if (cur->left != NULL) node_queue.push(cur->left);
//                 if (cur->right != NULL) node_queue.push(cur->right);
//                 node_queue.pop();
//             }
//         }
//         return root;

//     }
// };

// 前序遍历统一迭代法
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (root == NULL) return root;
//         stack<TreeNode*> node_stack;
//         node_stack.push(root);
//         while (!node_stack.empty()){
//             TreeNode* cur = node_stack.top();
//             if (cur != NULL){
//                 node_stack.pop();
//                 if (cur->right != NULL) node_stack.push(cur->right); // 右
//                 if (cur->left != NULL) node_stack.push(cur->left); // 左
//                 node_stack.push(cur);                                     // 中
//                 node_stack.push(NULL);
//             }
//             else{
//                 node_stack.pop();
//                 cur = node_stack.top();
//                 swap(cur->right, cur->left);
//                 node_stack.pop();
//             }
//         }
//         return root;
//     }
// };

// 中序遍历统一迭代法
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()){
            TreeNode* cur = node_stack.top();
            if (cur != NULL){
                node_stack.pop();
                if (cur->right != NULL) node_stack.push(cur->right); // 右
                node_stack.push(cur);                              // 中
                node_stack.push(NULL);
                if (cur->left != NULL) node_stack.push(cur->left); // 左
            }
            else{
                node_stack.pop();
                cur = node_stack.top();
                swap(cur->right, cur->left);
                node_stack.pop();
            }
        }
        return root;
    }
};
// @lc code=end

