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
 * @LastEditTime: 2024-06-11 22:31:49
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
    // 我自己的迭代法
    TreeNode* deleteNode1(TreeNode* root, int key) {
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
            TreeNode* delete_node = cur; // 记录将被删除的节点
            cur = cur->right; // 从右子树中找最左边的节点
            if (cur->left == NULL) { // 如果右子树中没有左边子树
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
            else { // 如果右子树存在左边子树
                TreeNode* subpre = NULL; // 用于记录（被用来替换的节点）的父节点
                while (cur->left) {
                    subpre = cur;
                    cur = cur->left;
                }
                subpre->left = cur->right; // 将用于替换的结点的右子树给前面得到的subpre的左边子树
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


    // 代码随想录的迭代法
    TreeNode* deleteNode2(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if (root->val == key) {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } 
            else if (root->left == NULL) {
                auto retNode = root->right;
                ///! 内存释放
                delete root;
                return retNode;
            }
            else if (root->right == NULL) {
                auto retNode = root->left;
                delete root;
                return retNode;
            }
            else {
                TreeNode* cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;   // 把root节点保存一下，下面来删除
                root = root->right;     // 返回旧root的右孩子作为新root
                delete tmp;             // 释放节点内存
                return root;
            }  
        }
        if (root->val > key) root->left = deleteNode2(root->left, key);
        if (root->val < key) root->right = deleteNode2(root->right, key);
        return root;
    }


    TreeNode* deleteNode3(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val == key) {
            if (root->right == nullptr) { // 这里第二次操作目标值：最终删除的作用
                return root->left;
            }
            TreeNode *cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }
            swap(root->val, cur->val); // 这里第一次操作目标值：交换目标值其右子树最左面节点。
        }
        root->left = deleteNode3(root->left, key);
        root->right = deleteNode3(root->right, key);
        return root;
    }

    // 迭代法
    TreeNode* deleteOneNode(TreeNode* target) {
        // if (target == NULL) return target;
        if (target->right == NULL) return target->left;
        TreeNode* cur = target->right;
        while (cur->left) {
            cur = cur->left;
        }
        cur->left = target->left;
        return target->right;
    }


    TreeNode* deleteNode4(TreeNode* root, int key) {
        // 将目标节点（删除节点）的左子树放到 目标节点的右子树的最左面节点的左孩子位置上
        // 并返回目标节点右孩子为新的根节点
        if (root == NULL) return root;
        TreeNode* cur = root;
        TreeNode* pre = NULL; // 记录cur的父节点，用来删除cur
        while (cur) {
            if (cur->val == key) break;
            pre = cur;
            if (cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        if (pre == NULL) { // 如果搜索树只有头结点
            return deleteOneNode(cur);
        }
        // pre 要知道是删左孩子还是右孩子
        if (pre->left && pre->left->val == key) {
            pre->left = deleteOneNode(cur);
        }
        if (pre->right && pre->right->val == key) {
            pre->right = deleteOneNode(cur);
        }
        return root;
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        // return deleteNode1(root, key);
        // return deleteNode2(root, key);
        // return deleteNode3(root, key);
        return deleteNode4(root, key);
    }

};
// @lc code=end

