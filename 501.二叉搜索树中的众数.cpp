// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem501.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-05 16:33:00
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-05 17:18:35
 */
/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
                if (node->right != NULL) node_stack.push(root->right);
                node_stack.push(cur);
                node_stack.push(NULL);
                if (node->left != NULL) node_stack.push(root->left);
            }
            else {
                node_stack.pop();
                cur = node_stack.top();
                node_stack.pop();
                result.push_back(cur->val);
            }
        }
    }


    vector<int> findMode(TreeNode* root) {
        vector<int> tree_vals;
        vector<int> result;
        unordered_map<int, int> result_map;
        middle_order_traversal(root, tree_vals);
        int num = 1;
        if (tree_vals.size() == 1) return tree_vals[0];
        for (int i = 1; i < tree_vals.size(); i++) {
            if (tree_vals[i] != tree_vals[i - 1]) {
                unordered_map[tree_vals[i - 1]] = num;
                num = 1;
            }
            else {
                num += 1;
            }
        }
        // 先找到最大众数
        int max = result[0];
        for (int i = 0; i < result.size(); i++) {
            if (result[i] > max) max = result[i];
        }
        //判断是否有其余众数
        for (int i = 0; i < result.size(); i++) {

        }
        return num;

    }
};
// @lc code=end

