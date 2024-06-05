// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem98.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-04 10:25:55
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-05 14:49:10
 */
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
//     // 判断子树的值是否都小于上一层的结点的值
//     bool is_max(TreeNode* root, int val) {
//         if (root == NULL) return true;
//         if (root != NULL && root->val >= val) return false;
//         return is_max(root->left, val) && is_max(root->right, val);
//     }
//     // 判断子树的值是否都大于上一层的结点的值
//     bool is_min(TreeNode* root, int val) {
//         if (root == NULL) return true;
//         if (root != NULL && root->val <= val) return false;
//         return is_min(root->left, val) && is_min(root->right, val);
//     }


//     bool isValidBST(TreeNode* root) {
//         if (root == NULL) return true;
//         bool left_is_validbst = false;
//         bool right_is_validbst = false;
//         // 对于左边子树在不为空的情况下
//         if (root->left != NULL) {
//             // 在当前结点的值大于左结点的值，同时下一个作子树需要符合要求
//             if (root->val > root->left->val && isValidBST(root->left)) 
//                 // 判断当前结点是否大于左子树的下面的所有结点的值
//                 left_is_validbst = is_max(root->left, root->val);
//         }
//         else {
//             left_is_validbst = true;
//         }
//         // 对于右边子树在不为空的情况下
//         if (root->right != NULL) {
//             if (root->val < root->right->val && isValidBST(root->right)) 
//                 // 判断当前结点是否大于左子树的下面的所有结点的值
//                 right_is_validbst = is_min(root->right, root->val);
//         }
//         else {
//             right_is_validbst = true;
//         }
//         return right_is_validbst && left_is_validbst;
//     }
// };

// 代码随想录递归法
// class Solution {
// public:
//     long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
//     bool isValidBST(TreeNode* root) {
//         if (root == NULL) return true;

//         bool left = isValidBST(root->left);
//         // 中序遍历，验证遍历的元素是不是从小到大
//         // 相当于在一直判断当前的结点是否一直在变大，如果没有变大证明不是二叉搜索树
//         if (maxVal < root->val) maxVal = root->val;
//         else return false;
//         bool right = isValidBST(root->right);

//         return left && right;
//     }
// };

// 迭代法
class Solution {
public:
    long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
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
                if (cur->val > maxVal) maxVal = cur->val;
                else return false;
                cur = cur->right;
            }
        }
        return true;
    }
};

// @lc code=end

