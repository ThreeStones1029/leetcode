// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem538.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-14 22:03:47
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-14 22:49:27
 */
/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
class Solution {
public:
    // 右根左 迭代法
    TreeNode* convertBST1(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> node_stack;
        int sum = 0;
        while (cur || !node_stack.empty()) {
            if (cur != NULL) {
                while (cur) {
                    node_stack.push(cur);
                    cur = cur->right;
                }
            }
            else {
                cur = node_stack.top();
                node_stack.pop();
                cur->val += sum;
                sum = cur->val;
                cur = cur->left;
            }
        }
        return root;
    }

    // 递归法
    void transval(TreeNode* cur, int& sum) {
        if (cur->right != NULL) transval(cur->right, sum);
        if (cur != NULL) {
            cur->val += sum;
            sum = cur->val;
        }
        if (cur->left != NULL) transval(cur->left, sum);
    }

    TreeNode* convertBST2(TreeNode* root) {
        if (root == NULL) return NULL;
        int sum = 0;
        transval(root, sum);
        return root;
    }

    // 统一迭代法
    TreeNode* convertBST3(TreeNode* root) {
        if (root == NULL) return NULL;
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        TreeNode* cur = NULL;
        int sum = 0;
        while (!node_stack.empty()) {
            TreeNode* cur = node_stack.top();
            node_stack.pop();
            if (cur != NULL){
                if (cur->left != nullptr) node_stack.push(cur->left);
                node_stack.push(cur);
                node_stack.push(nullptr);
                if (cur->right != nullptr) node_stack.push(cur->right);
            }
            else{
                // 只有遇到空节点的时候，才开始遍历
                cur = node_stack.top();
                cur->val += sum;
                sum = cur->val;
                node_stack.pop();
            }
        }
        return root;
    }


    TreeNode* convertBST(TreeNode* root) {
        // return convertBST1(root);
        // return convertBST2(root);
        return convertBST3(root);
    }
};
// @lc code=end

