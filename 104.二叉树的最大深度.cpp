// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem104.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-01 20:50:55
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-02 22:15:08
 */
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
// 层序遍历
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         queue<TreeNode*> node_queue;
//         if (root != NULL) node_queue.push(root);
//         int depth = 0;
//         while(!node_queue.empty()){
//             int size = node_queue.size();
//             for (int i = 0; i < size; i++){
//                 TreeNode* cur = node_queue.front();
//                 node_queue.pop();
//                 if (cur->left != NULL) node_queue.push(cur->left);
//                 if (cur->right != NULL) node_queue.push(cur->right);
//             }
//             depth++;
//         }
//         return depth;
//     }
// };

// 后序遍历递归法
// class Solution {
// public:
//     int get_depth(TreeNode* cur){
//         if (cur == NULL) return 0;
//         int left_depth = get_depth(cur->left);
//         int right_depth = get_depth(cur->right);
//         return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
//     }
    
//     int maxDepth(TreeNode* root) {
//         return get_depth(root);    
//     }
// };

// 前序遍历递归法
class Solution {
public:
    int result;
    void get_depth(TreeNode*cur, int depth){
        result = depth > result ? depth : result; // 中
        if (cur->left == NULL && cur->right == NULL) return ;
        if (cur->left){
            depth++;
            get_depth(cur->left, depth);
            depth--;
        }
        if (cur->right){
            depth++;
            get_depth(cur->right, depth);
            depth--;
        }
        return ;
    }
    int maxDepth(TreeNode* root) {
        result = 0;
        if (root == NULL) return 0;
        get_depth(root, 1);
        return result;
    }
};
// @lc code=end

