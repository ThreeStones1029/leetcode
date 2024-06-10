// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem450.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-10 16:25:25
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-10 22:44:27
 */
/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 找到需要删除的节点
        TreeNode* dummy = new TreeNode(1000001); // 构造一个哑结点用来处理删除根节点的情况
        dummy->left = root;
        dummy->right = NULL;
        TreeNode* cur = dummy;
        TreeNode* pre = dummy;
        while (cur) {
            if (cur->val > key) {
                pre = cur;
                cur = cur->left;
            }
            else if (cur->val < key) {
                pre = cur;
                cur = cur->right;
            }
            else break;
        }
        if (cur == NULL) return dummy->left;
        // 以下为当删除的不是根结点时候的处理
        if (cur->left == NULL && cur->right == NULL) {
            if (pre->left != NULL && pre->left->val == key) pre->left = NULL;
            if (pre->right != NULL && pre->right->val == key) pre->right = NULL;
        } else if (cur->left == NULL && cur->right != NULL) {
            if (pre->left != NULL && pre->left->val == key) pre->left = cur->right;
            if (pre->right != NULL && pre->right->val == key) pre->right = cur->right;
        } else if (cur->left != NULL && cur->right == NULL) {
            if (pre->left != NULL && pre->left->val == key) pre->left = cur->left;
            if (pre->right != NULL && pre->right->val == key) pre->right = cur->left;
        } else {
            // 找到以key为根节点的右子树的最左下的结点
            TreeNode* delete_node = cur;
            cur = cur->right;
            if (cur->left == NULL) {
                TreeNode* subright = cur->right;
                if (pre->left != NULL && pre->left->val == key) {
                    pre->left = cur;
                }
                if (pre->right != NULL && pre->right->val == key) {
                    pre->right = cur;
                }
                cur->left = delete_node->left;
                cur->right = subright;
            }
            else {
                TreeNode* subpre = NULL;
                while (cur->left) {
                    subpre = cur;
                    cur = cur->left;
                }
                subpre->left = NULL;
                if (pre->left != NULL && pre->left->val == key) {
                    pre->left = cur;
                }
                if (pre->right != NULL && pre->right->val == key) {
                    pre->right = cur;
                }
                cur->left = delete_node->left;
                cur->right = delete_node->right;
            }
            
        }
        return dummy->left;
    }
};
// @lc code=end

