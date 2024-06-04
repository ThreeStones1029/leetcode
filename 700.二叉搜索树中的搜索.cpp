// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem700.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-03 21:56:49
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-04 09:08:54
 */
/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
/*------------------------------------普通二叉树的搜索-------------------------------------------*/
// 递归
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if (root == NULL) return NULL;
//         if (root->val == val) return root;
//         TreeNode* left = searchBST(root->left, val);
//         if (left != NULL) return left;
//         TreeNode* right = searchBST(root->right, val);
//         if (right != NULL) return right;
//         return NULL;
//     }
// };

// 前序遍历迭代法
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if (root == NULL) return NULL;
//         stack<TreeNode*> node_stack;
//         node_stack.push(root);
//         TreeNode* cur;
//         while (!node_stack.empty()) {
//             cur = node_stack.top();
//             node_stack.pop();
//             if (cur->val == val) break;
//             if (cur->left != NULL) node_stack.push(cur->left);
//             if (cur->right != NULL) node_stack.push(cur->right);
//         }
//         if (cur->val != val) return NULL;
//         return cur;
//     }
// };

// 中序遍历迭代法
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if (root == NULL) return NULL;
//         stack<TreeNode*> node_stack;
//         TreeNode* cur = root;
//         // 当cur不为空或者队列不为空
//         while (cur != NULL || !node_stack.empty()){
//             // 加入左结点
//             if (cur != NULL) {
//                 node_stack.push(cur);
//                 cur = cur->left;
//             }
//             else{
//                 cur = node_stack.top();
//                 node_stack.pop();
//                 if (cur->val == val) break;
//                 cur = cur->right;
//             }
//         }
//         return cur;
//     }
// };


// 层序遍历迭代法
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if (root == NULL) return NULL;
//         queue<TreeNode*> node_queue;
//         node_queue.push(root);
//         TreeNode* cur;
//         while (!node_queue.empty()) { 
//             int size = node_queue.size();
//             int i = 0;
//             for (i = 0; i < size; i++) {
//                 cur = node_queue.front();
//                 node_queue.pop();
//                 if (cur->val == val) break;
//                 if (cur->left != NULL) node_queue.push(cur->left);
//                 if (cur->right != NULL) node_queue.push(cur->right);
//             }
//             // i小于size说明找到了这个值，提前退出
//             if (i < size) break;
//         }
//         // 需要判断最后的值等不等于val
//         if (cur->val != val) return NULL;
//         return cur;
//     }
// };

/*------------------------------------二叉搜索树中的搜索-------------------------------------------*/
// 递归
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if (root == NULL || root->val == val) return root;
//         if (val > root->val) return searchBST(root->right, val);
//         if (val < root->val) return searchBST(root->left, val);
//         return NULL;
//     }
// };

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        while (cur != NULL) {
            if (cur->val > val) cur = cur->left;
            else if (cur->val < val) cur = cur->right;
            else return cur;
        }
        return NULL;
    }
};


// @lc code=end

