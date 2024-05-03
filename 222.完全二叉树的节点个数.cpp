/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-02 23:06:28
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-03 22:41:50
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

// 中序遍历迭代法
class Solution {
public:
    int countNodes(TreeNode* root) {
        stack<TreeNode*> node_stack;
        if (root == NULL) return 0;
        node_stack.push(root);
        int num = 0;
        while (!node_stack.empty()){
            TreeNode* cur = node_stack.top();
            
            if (cur->left != NULL){
                node_stack.push(cur->left);
                cur = cur->left;
            }
            else{
                num += 1;
                node_stack.pop();
            }
        }
        return num;
    }
};

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

// 层序遍历迭代法
// @lc code=end

