// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem669.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-11 22:47:39
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-15 10:06:46
 */
/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    // 自己的方法之循环删除
    pair<TreeNode*, TreeNode*> FindNode(TreeNode* root, int val) {
        pair<TreeNode*, TreeNode*> pre_cur;
        if (root == NULL) {
            pre_cur.first = NULL;
            pre_cur.second = NULL;
            return pre_cur;
        }
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur) {
            if (cur->val > val) {
                pre = cur;
                cur = cur->left;
            }
            else if (cur->val < val) {
                pre = cur;
                cur = cur->right;
            }
            else break;
        }
        pre_cur.first = pre;
        pre_cur.second = cur;
        return pre_cur;
    }

    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL) return root;
        // 找到最小的low结点以及high结点删除low以及low的左边结点，删除high以及high的右
        pair<TreeNode*, TreeNode*> low_pre_cur = FindNode(root, low);
        pair<TreeNode*, TreeNode*> high_pre_cur = FindNode(root, high);
        // 第一种情况找到这个结点且这个结点为根结点，pre为空，cur不为空，则需要删除的小的结点是根结点
        if (low_pre_cur.first == NULL && low_pre_cur.second != NULL) {
            root = root->right;
        }
        // 第二种情况，找到这个结点，pre不空，cur不空
        else if (low_pre_cur.first != NULL && low_pre_cur.second != NULL) {
            low_pre_cur.first->left = low_pre_cur.second->right;
        }
        // 第三种情况，没有找到这个结点，pre为空，cur为空
        else
        {
            root = root;
        }

        // 第一种情况找到这个结点且这个结点为根结点，pre为空，cur不为空，则需要删除的大的结点是根结点
        if (high_pre_cur.first == NULL && high_pre_cur.second != NULL) {
            root = root->left;
        }
        // 第二种情况，找到这个结点，pre不空，cur不空
        else if (high_pre_cur.first != NULL && high_pre_cur.second != NULL) {
            high_pre_cur.first->right = high_pre_cur.second->left;
        }
        // 第三种情况，没有找到这个结点，pre为空，cur为空
        else
        {
            root = root;
        }
        return root;

    }
};
// @lc code=end

