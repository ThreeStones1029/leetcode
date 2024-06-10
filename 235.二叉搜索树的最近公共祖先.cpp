// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem235.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-09 22:51:24
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-10 15:51:52
 */
/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // 解法一：正常二叉树的最近公共祖先
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor1(root->left, p, q);
        TreeNode* right = lowestCommonAncestor1(root->right, p, q);
        if (left != NULL && right != NULL) return root;
        else if (left == NULL && right != NULL) return right;
        else if (left != NULL && right == NULL) return left;
        else return NULL;
    }

    // 解法二：二叉搜索树的最近公共祖先
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 情况一
         if (root == NULL) return NULL;
         else if ((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val)) return root;
         else if (root->val == p->val || root->val == q->val) return root;
         else if (root->val > p->val && root->val > q->val) return lowestCommonAncestor2(root->left, p, q);
         else if (root->val < p->val && root->val < q->val) return lowestCommonAncestor2(root->right, p, q);
         else return NULL;
    }


    // 解法三：迭代法
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            } else if (root->val < p->val && root->val < q->val) {
                root = root->right;
            } else return root;
        }
        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return lowestCommonAncestor1(root, p, q);
        // return lowestCommonAncestor2(root, p, q);
        return lowestCommonAncestor3(root, p, q);
    }
};
// @lc code=end

