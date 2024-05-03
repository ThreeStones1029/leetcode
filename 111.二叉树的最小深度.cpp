// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem111.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-01 20:57:08
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-02 23:02:51
 */
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
// 层序遍历迭代法
// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         queue<TreeNode*> node_queue;
//         if (root != NULL) node_queue.push(root);
//         int depth = 0;
//         while(!node_queue.empty()){
//             int size = node_queue.size();
//             int num = 0;
//             for (int i = 0; i < size; i++){
//                 TreeNode* cur = node_queue.front();
//                 node_queue.pop();
//                 if (cur->left != NULL) node_queue.push(cur->left);
//                 if (cur->right != NULL) node_queue.push(cur->right);
//                 if (cur->right == NULL && cur->left == NULL) num++;
//             }
//             depth++;
//             if (num != 0) break;
            
//         }
//         return depth;
//     }
// };

// 后序遍历递归法
// class Solution {
// public:
//     int get_depth(TreeNode* cur){
//         if (cur == NULL) return 0; // 终止条件
//         int left_depth = get_depth(cur->left);
//         int right_depth = get_depth(cur->right);

//         if (cur->left != NULL && cur->right == NULL){
//             return 1 + left_depth;
//         }
//         if (cur->left == NULL && cur->right != NULL){
//             return 1 + right_depth;
//         }
//         int result = 1 + min(left_depth, right_depth);
//         return result;
//     }

//     int minDepth(TreeNode* root) {
//         return get_depth(root);
//     }
// };

// 前序遍历递归法
class Solution {
private:
    int result;
    void getdepth(TreeNode* node, int depth) {
        // 函数递归终止条件
        if (node == nullptr) {
            return;
        }
        // 中，处理逻辑：判断是不是叶子结点
        if (node -> left == nullptr && node->right == nullptr) {
            result = min(result, depth);
        }
        if (node->left) { // 左
            getdepth(node->left, depth + 1);
        }
        if (node->right) { // 右
            getdepth(node->right, depth + 1);
        }
        return ;
    }

public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        result = INT_MAX;
        getdepth(root, 1);
        return result;
    }
};

// @lc code=end

