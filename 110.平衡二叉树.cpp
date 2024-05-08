// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem110.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-07 22:16:16
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-08 15:11:24
 */
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
// 后序遍历求高度
// 前序遍历求深度
// 本题是平衡二叉树是指每个结点的子树高度差小于等于1
// 递归法
// class Solution {
// public:
//     int getHeight(TreeNode* cur){
//         if (cur == NULL) return 0;
//         int left_height = getHeight(cur->left);
//         // 在左子树不平衡的时候提前返回
//         if (left_height == -1) return -1;
//         int right_height = getHeight(cur->right);
//         // 在右子树不平衡的时候提前返回
//         if (right_height == -1) return -1;
//         return abs(left_height - right_height) > 1 ? -1 : 1 + max(left_height, right_height);
//     }

//     bool isBalanced(TreeNode* root) {
//         return getHeight(root) == -1 ? false : true;
//     }
// };

// 迭代法 用栈后序遍历求以当前结点为根结点的最大深度，也即当前结点的高度
// 再使用或许遍历来判断左右结点高度是否符合要求
class Solution {
private:
    int getDepth(TreeNode* cur){
        stack<TreeNode*> node_stack;
        if (cur !=NULL) node_stack.push(cur);
        int height = 0;
        int depth = 0;
        while(!node_stack.empty()){
            TreeNode* tmp = node_stack.top();
            if (tmp != NULL){
                node_stack.pop();
                node_stack.push(tmp);
                node_stack.push(NULL);
                if (tmp->right) node_stack.push(tmp->right);
                if (tmp->left) node_stack.push(tmp->left);
                depth++;
            }
            else{
                node_stack.pop();
                tmp = node_stack.top();
                node_stack.pop();
                depth--;
            }
            height = height > depth ? height : depth;
        }
        return height;
    }

public:
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == NULL) return true;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            if (abs(getDepth(node->left) - getDepth(node->right)) > 1) {
                return false;
            }
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return true;
    }
};
// @lc code=end

