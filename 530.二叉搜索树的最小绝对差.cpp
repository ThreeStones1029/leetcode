// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem530.h"
#include <stack>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
// 中序遍历迭代法
// class Solution {
// public:
//     int getMinimumDifference(TreeNode* root) {
//         TreeNode* cur = root;
//         int pre_val = root->val;
//         int i = 1;
//         int different = INT32_MAX;
//         stack<TreeNode*> node_stack;
//         while (cur != NULL || !node_stack.empty()) {
//             if (cur != NULL) {
//                 node_stack.push(cur);
//                 cur = cur->left;
//             }
//             else {
//                 cur = node_stack.top();
//                 node_stack.pop();
//                 if (i != 1) {
//                     if (cur->val - pre_val < different) different = cur->val - pre_val;
//                 }
//                 i += 1;
//                 pre_val = cur->val;
//                 cur = cur->right;
//             }
//         }
//         return different;
//     }
// };

// 中序遍历递归法
// class Solution {
// public:
//     void middle_order_traversal(TreeNode* root, vector<int>& result) {
//         if (root->left != NULL) middle_order_traversal(root->left, result);
//         if (root != NULL) result.push_back(root->val);
//         if (root->right != NULL) middle_order_traversal(root->right, result);
//     }

//     int getMinimumDifference(TreeNode* root) {
//         vector<int> result;
//         middle_order_traversal(root, result);
//         int different = result[1] - result[0];
//         for (int i = 1; i < result.size(); i++) {
//             if (result[i] - result[i - 1] < different) different = result[i] - result[i - 1];
//         }
//         return different;
//     }
// };

// 中序遍历统一迭代法
class Solution {
public:
    void middle_order_traversal(TreeNode* root, vector<int>& result) {
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            TreeNode* cur = node_stack.top();
            if (cur != NULL) {
                node_stack.pop();
                if (cur->right != nullptr) node_stack.push(cur->right);
                node_stack.push(cur);
                node_stack.push(nullptr);
                if (cur->left != nullptr) node_stack.push(cur->left);
            }
            else {
                // 只有遇到空节点的时候，才将下一个节点放进结果集
                node_stack.pop();
                cur = node_stack.top();
                result.push_back(cur->val);
                node_stack.pop();
            }
        }
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> result;
        middle_order_traversal(root, result);
        int different = result[1] - result[0];
        for (int i = 1; i < result.size(); i++) {
            if (result[i] - result[i - 1] < different) different = result[i] - result[i - 1];
        }
        return different;
    }
};
// @lc code=end

