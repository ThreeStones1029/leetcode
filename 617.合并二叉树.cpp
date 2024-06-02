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
        TreeNode* root = new TreeNode(root1->val + root2->val);
        queue<TreeNode*> node_queue1;
        queue<TreeNode*> node_queue2;
        node_queue1.push_back(root1);
        node_queue2.push_back(root2);
        while (node_queue1.empty() && node_queue2.empty()){
            int size1 = node_queue1.size();
            int size2 = node_queue2.size();
            
        }
        return root;
    }
};
// @lc code=end

