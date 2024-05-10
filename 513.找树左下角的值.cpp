// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem513.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-08 23:01:54
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-09 21:45:42
 */
/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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

// 层序遍历感觉可以解决
// class Solution {
// public:
//     int findBottomLeftValue(TreeNode* root) {
//         queue<TreeNode*> node_queue;
//         node_queue.push(root);
//         int result = 0;
//         while (!node_queue.empty()){
//             int size = node_queue.size();
//             for (int i = 0; i < size; i++){
//                 TreeNode* cur = node_queue.front();
//                 if (cur->left != NULL) node_queue.push(cur->left);
//                 if (cur->right != NULL) node_queue.push(cur->right);
//                 node_queue.pop();
//                 if (i == 0) result = cur->val;
//             }
//         }
//         return result;
//     }
// };


// 递归法，先求最后一个结点
class Solution {
public:
    int maxDepth = INT_MIN;   // 全局变量 记录最大深度
    int result;       // 全局变量 最大深度最左节点的数值
    void traversal(TreeNode* root, int depth){
        if (root->left == NULL && root->right == NULL){
            if (depth > maxDepth){
                maxDepth = depth;
                result = root->val; // 这里只有大于这个深度才会记录，实际上为前序遍历，在每次碰到新的叶子结点，且深度大于大于最大深度，则更新
                std::cout << result << std::endl;
            }
        }
        if (root->left){
            depth++;
            traversal(root->left, depth);
            depth--; // 回溯`
        }
        if (root->right){
            depth++;
            traversal(root->right, depth);
            depth--; // 回溯`
        }

    }

    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return result;
    }
};


// @lc code=end

