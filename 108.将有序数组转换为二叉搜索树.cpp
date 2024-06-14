// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem108.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-11 22:48:57
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-14 21:28:41
 */
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    // 中序遍历递归 左闭右开
    TreeNode* transval(vector<int>& nums, int start, int end) {
        if (end - start == 0) return NULL;
        else if (end - start == 1) {
            TreeNode* cur = new TreeNode(nums[start]);
            return cur;
        }
        else{
            int mid = (start + end) / 2;
            TreeNode* cur = new TreeNode(nums[mid]);
            cur->left = transval(nums, start, mid);
            cur->right = transval(nums, mid + 1, end);
            return cur;
        }
    }

    
    TreeNode* sortedArrayToBST1(vector<int>& nums) {
        TreeNode* root = NULL;
        root = transval(nums, 0, nums.size());
        return root;
    }

    // 代码随想录，迭代法，三个队列 左闭右闭
    TreeNode* sortedArrayToBST2(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;

        TreeNode* root = new TreeNode(0);   // 初始根节点
        queue<TreeNode*> nodeQue;           // 放遍历的节点
        queue<int> leftQue;                 // 保存左区间下标
        queue<int> rightQue;                // 保存右区间下标
        nodeQue.push(root);                 // 根节点入队列
        leftQue.push(0);                    // 0为左区间下标初始位置
        rightQue.push(nums.size() - 1);     // nums.size() - 1为右区间下标初始位置

        while (!nodeQue.empty()) {
            TreeNode* curNode = nodeQue.front();
            nodeQue.pop();
            int left = leftQue.front(); 
            leftQue.pop();
            int right = rightQue.front(); 
            rightQue.pop();
            int mid = left + ((right - left) / 2);

            curNode->val = nums[mid];       // 将mid对应的元素给中间节点

            if (left <= mid - 1) {          // 处理左区间
                curNode->left = new TreeNode(0);
                nodeQue.push(curNode->left);
                leftQue.push(left);
                rightQue.push(mid - 1);
            }

            if (right >= mid + 1) {         // 处理右区间
                curNode->right = new TreeNode(0);
                nodeQue.push(curNode->right);
                leftQue.push(mid + 1);
                rightQue.push(right);
            }
        }
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // return sortedArrayToBST1(nums);
        return sortedArrayToBST2(nums);
    }
};
// @lc code=end

