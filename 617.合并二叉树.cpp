// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem617.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//         if (root1 == NULL) return root2;
//         if (root2 == NULL) return root1;
//         TreeNode* root = new TreeNode(root1->val + root2->val);
//         root->left = mergeTrees(root1->left, root2->left);
//         root->right = mergeTrees(root1->right, root2->right);
//         return root;
//     }
// };
// 层序遍历迭代法
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL) return root2;
        if (root2 == NULL) return root1;
        queue<TreeNode*> node_queue;
        node_queue.push(root1);
        node_queue.push(root2);
        while (!node_queue.empty()){
            TreeNode* node1 = node_queue.front();
            node_queue.pop();
            TreeNode* node2 = node_queue.front();
            node_queue.pop();
            node1->val += node2->val;
            if (node1->left != NULL && node2->left != NULL){
                node_queue.push(node1->left);
                node_queue.push(node2->left);
            }
            if (node1->right != NULL && node2->right != NULL){
                node_queue.push(node1->right);
                node_queue.push(node2->right);
            }
            if (node1->left == NULL && node2->left != NULL) {
                node1->left = node2->left;
            }
            if (node1->right == NULL && node2->right != NULL) {
                node1->right = node2->right;
            }
        }
        return root1;
    }
};
// @lc code=end

