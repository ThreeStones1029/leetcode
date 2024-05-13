// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem106.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-11 22:43:17
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-13 22:04:49
 */
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
// 定义数组
// class Solution {
// public:
//     TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
//         // 第一步：如果数组大小为零的话，说明是空节点
//         if (inorder.size() == 0) return NULL;
//         // 第二步：如果不为空，那么取后序数组最后一个元素作为节点元素
//         int rootvalue = postorder[postorder.size() - 1];
//         TreeNode* root = new TreeNode(rootvalue);
//         if (postorder.size() == 1) return root;
//         // 第三步：找到后序数组最后一个元素在中序数组的位置，作为切割点
//         int delimiterIndex;
//         for (delimiterIndex = 0; delimiterIndex < inorder.size() - 1; delimiterIndex++){
//             if (inorder[delimiterIndex] == rootvalue) break;
//         }
//         // 第四步：切割中序数组，切成中序左数组和中序右数组 （顺序别搞反了，一定是先切中序数组）
//         // 坚持左闭右开
//         vector<int> inorder_left(inorder.begin(), inorder.begin() + delimiterIndex);
//         vector<int> inorder_right(inorder.begin() + delimiterIndex + 1, inorder.end());
//         // 第五步：切割后序数组，切成后序左数组和后序右数组
//         // 去除末尾元素,已经作为root
//         postorder.resize(postorder.size() - 1); 
//         vector<int> postorder_left(postorder.begin(), postorder.begin() + inorder_left.size());
//         vector<int> postorder_right(postorder.begin() + inorder_left.size(), postorder.end());

//         // 第六步：递归处理左区间和右区间
//         root->left = traversal(inorder_left, postorder_left);
//         root->right = traversal(inorder_right, postorder_right);
//         return root;
//     }


//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         if (inorder.size() == 0 || postorder.size() == 0) return NULL;
//         return traversal(inorder, postorder);
//     }
// };

// 利用下标
class Solution {
public:
    TreeNode* traversal(vector<int>& inorder, int inorder_begin, int inorder_end, vector<int>& postorder, int postorder_begin, int postorder_end) {
        // 第一步：如果数组大小为零的话，说明是空节点
        if (inorder_end - inorder_begin == 0) return NULL;
        // 第二步：如果不为空，那么取后序数组最后一个元素作为节点元素
        int rootvalue = postorder[postorder_end - 1];
        TreeNode* root = new TreeNode(rootvalue);
        if (postorder_end - postorder_begin == 1) return root;
        // 第三步：找到后序数组最后一个元素在中序数组的位置，作为切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder_end - 1; delimiterIndex++){
            if (inorder[delimiterIndex] == rootvalue) break;
        }
        // 第四步：切割中序数组，切成中序左数组和中序右数组 （顺序别搞反了，一定是先切中序数组）
        // 坚持左闭右开
        int left_inorder_begin = inorder_begin;
        int left_inorder_end = delimiterIndex;
        int right_inorder_begin = delimiterIndex + 1;
        int right_inorder_end = inorder_end;
        // 第五步：切割后序数组，切成后序左数组和后序右数组
        // 去除末尾元素,已经作为root
        int left_postorder_begin = postorder_begin;
        int left_postorder_end = postorder_begin + left_inorder_end - left_inorder_begin;
        int right_postorder_begin = left_postorder_end;
        int right_postorder_end = postorder_end - 1;
        // 第六步：递归处理左区间和右区间
        root->left = traversal(inorder, left_inorder_begin, left_inorder_end, postorder, left_postorder_begin, left_postorder_end);
        root->right = traversal(inorder, right_inorder_begin, right_inorder_end, postorder, right_postorder_begin, right_postorder_end);
        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
// @lc code=end

