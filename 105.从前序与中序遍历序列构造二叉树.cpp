// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem105.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-13 22:07:34
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-13 23:18:42
 */
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder){
        // 第一步: 当preorder长度为0,返回空结点
        if (inorder.size() == 0) return NULL;
        // 第二步: preorder第一个结点为根结点
        int rootvalue = preorder[0];
        TreeNode* root = new TreeNode(rootvalue);
        if (preorder.size() == 1) return root;
        // 第三步,找到分割点
        int delimiterIndex;
        for (int delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++){
            if (inorder[delimiterIndex] == rootvalue) {
                cout << delimiterIndex << endl;
                break;
            }
        }
        // 第四步,划分中序为左子树与右子树
        vector<int> inorder_left(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> inorder_right(inorder.begin() + delimiterIndex + 1, inorder.end());
        // 第五步,划分前序为左子树与右子树
        for (int i = 0; i < preorder.size() - 1; i++){
            preorder[i] = preorder[i + 1];
        }
        preorder.resize(preorder.size() - 1);

        vector<int> preorder_left(preorder.begin(), preorder.begin() + inorder_left.size());
        vector<int> preorder_right(preorder.begin() + inorder_left.size(), preorder.end());

        // 第六步
        root->left = traversal(preorder_left, inorder_left);
        root->right = traversal(preorder_right, inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return NULL;
        return traversal(preorder, inorder);
    }
};
// @lc code=end

