// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem257.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-08 15:14:33
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-09 22:31:04
 */
/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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

// 递归回溯法
// class Solution {
// public:
//     void subTreepath(TreeNode* cur, vector<int>& path, vector<string>& result){
//         path.push_back(cur->val); // 中
//         if (cur->left == NULL && cur->right==NULL){
//             string spath;
//             for (int i = 0; i < path.size() - 1; i++){
//                 spath += to_string(path[i]);
//                 spath += "->";
//             }
//             spath += to_string(path[path.size() - 1]);
//             result.push_back(spath);
//         }
//         if (cur->left){
//             subTreepath(cur->left, path, result);
//             path.pop_back(); // 回溯
//         }
//         if (cur->right){
//             subTreepath(cur->right, path, result);
//             path.pop_back(); // 回溯
//         }
//     }

//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> result;
//         vector<int> path;
//         if (root == NULL) return result;
//         subTreepath(root, path, result);
//         return result;
//     }
// };
// 迭代法 两个栈，一个栈用来遍历，一个栈用来记录结果
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        stack<TreeNode*> node_stack;
        stack<string> spath;
        if (root == NULL) return result;
        node_stack.push(root);
        spath.push(to_string(root->val));
        while(!node_stack.empty()){
            TreeNode* cur = node_stack.top();
            node_stack.pop();
            string path = spath.top();
            spath.pop();
            if (cur->left != NULL) {
                node_stack.push(cur->left);
                spath.push(path + "->" + to_string(cur->left->val));
            }
            if (cur->right != NULL) {
                node_stack.push(cur->right);
                spath.push(path + "->" + to_string(cur->right->val));
            }
            if (cur->left == NULL && cur->right == NULL) {
                result.push_back(path);
            }
        }
        
        return result;
    }
};
// @lc code=end

