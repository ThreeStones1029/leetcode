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
 * @LastEditTime: 2024-06-09 15:33:30
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
class Solution {
public:
    // 统一迭代中序遍历
    void unified_iteration_middle_order_traversal(TreeNode* root, vector<int>& result) {
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            TreeNode* cur = node_stack.top();
            if (cur != NULL) {
                node_stack.pop();
                if (cur->right != NULL) node_stack.push(cur->right);
                node_stack.push(cur);
                node_stack.push(NULL);
                if (cur->left != NULL) node_stack.push(cur->left);
            }
            else {
                node_stack.pop();
                cur = node_stack.top();
                node_stack.pop();
                result.push_back(cur->val);
            }
        }
    }
    
    // 递归法中序遍历
    void recursion_middle_order_traversal(TreeNode* root, vector<int>& result) {
        if (root->left != NULL) recursion_middle_order_traversal(root->left, result);
        if (root != NULL) result.push_back(root->val);
        if (root->right != NULL) recursion_middle_order_traversal(root->right, result); 
    }

    // 迭代法中序遍历
    void iteration_middle_order_traversal(TreeNode* root, vector<int>& result) {
        stack<TreeNode*> node_stack;
        TreeNode* cur = root;
        while (cur != NULL || !node_stack.empty()) {
            if (cur != NULL) {
                node_stack.push(cur);
                cur = cur->left;
            }
            else {
                cur = node_stack.top();
                node_stack.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
    }


    vector<int> findMode1(TreeNode* root) {
        vector<int> tree_vals;
        vector<int> result;
        unordered_map<int, int> result_map;
        // unified_iteration_middle_order_traversal(root, tree_vals); // 统一迭代中序遍历
        // recursion_middle_order_traversal(root, tree_vals);// 递归法中序遍历
        iteration_middle_order_traversal(root, tree_vals);
        int num = 1;
        for (int i = 0; i < tree_vals.size(); i++) {
            auto it = result_map.find(tree_vals[i]);
            if (it != result_map.end()) {
                result_map[tree_vals[i]]++;
            }
            else {
                result_map[tree_vals[i]] = 1;
            }
        }

        auto max_pair = result_map.begin();
        // 迭代映射，寻找值最大的键
        for (auto it = result_map.begin(); it != result_map.end(); ++it) {
            if (it->second > max_pair->second) {
                max_pair = it;
            }
        }
        result.push_back(max_pair->first);
        for (auto it = result_map.begin(); it != result_map.end(); ++it) {
            if (it->second == max_pair->second && it->first != max_pair->first) {
                result.push_back(it->first);
            }
        }
        return result;
    }


    vector<int> findMode2(TreeNode* root) {
        vector<int> tree_vals;
        vector<int> result;
        
        // unified_iteration_middle_order_traversal(root, tree_vals); // 统一迭代中序遍历
        // recursion_middle_order_traversal(root, tree_vals);// 递归法中序遍历
        iteration_middle_order_traversal(root, tree_vals);
        int cur_val = tree_vals[0];
        int num = 1;
        int vals_max_num = 1;
        for (int i = 1; i < tree_vals.size(); i++) {
            if (tree_vals[i] == cur_val) {
                num++;
            }
            else {
                if (num > vals_max_num) {
                    // 若大于当前结果里面的数对应的数量，则全部删除后加入
                    while (result.size() > 0)
                    {
                       result.pop_back();
                    }
                    result.push_back(cur_val);
                    vals_max_num = num;
                }else if (num == vals_max_num){
                    result.push_back(cur_val);
                }
                cur_val = tree_vals[i];
                num = 1;
            }
        }
        // 处理最后的一个元素
        if (num > vals_max_num) {
            while (result.size() > 0)
            {
                result.pop_back();
            }
            result.push_back(cur_val);
        }
        if (num == vals_max_num) {
            result.push_back(cur_val);
        }

        return result;
    }

    vector<int> findMode(TreeNode* root) {
        // return findMode1(root); // 第一种求众数
        return findMode2(root); // 第二种求众数
    }

};
// @lc code=end

