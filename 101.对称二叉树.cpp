/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-05-01 22:55:51
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-02 17:05:12
 */
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
// 后序遍历迭代法双栈
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)) return false;
//         // 分别左右中以及右左中遍历
//         if (root->left != NULL && root->right != NULL){
//             stack<TreeNode*> left_stack;
//             stack<TreeNode*> right_stack;
//             left_stack.push(root->left);
//             right_stack.push(root->right);
//             while (!left_stack.empty() && !right_stack.empty()){
//                 TreeNode* left_cur = left_stack.top();
//                 TreeNode* right_cur = right_stack.top();
//                 if (left_cur->val != right_cur->val) return false;
//                 left_stack.pop();
//                 right_stack.pop();
//                 // 当左边栈顶元素的右结点与右边栈顶元素的左结点不空时分别入栈
//                 if (left_cur->right != NULL && right_cur->left != NULL) {
//                     left_stack.push(left_cur->right);
//                     right_stack.push(right_cur->left);
//                 }
//                 // 当左边栈顶元素的右结点与右边栈顶元素的左结点有一个为空则说明不对称
//                 if (left_cur->right != NULL && right_cur->left == NULL) return false;
//                 if (left_cur->right == NULL && right_cur->left != NULL) return false;
//                 // 当左边栈顶元素的左结点与右边栈顶元素的右结点不空时分别入栈
//                 if (left_cur->left != NULL && right_cur->right != NULL) {
//                     left_stack.push(left_cur->left);
//                     right_stack.push(right_cur->right);
//                 }
//                 // 当左边栈顶元素的左结点与右边栈顶元素的右结点有一个为空则说明不对称
//                 if (left_cur->left != NULL && right_cur->right == NULL) return false;
//                 if (left_cur->left == NULL && right_cur->right != NULL) return false;  
//             }
//             // 当有一个栈为空后,判断另外一个栈是否为空,不为空表示元素更多,不是对称二叉树
//             if (!left_stack.empty() || !right_stack.empty()){
//                 return false;
//             }
//         }
//         return true;
//     }
// };


// 后序遍历递归法
// class Solution {
// public:
//     bool  compare(TreeNode* left, TreeNode* right){
//         // 首先排除空节点的情况
//         if (left == NULL && right != NULL) return false;
//         else if (left != NULL && right == NULL) return false;
//         else if (left == NULL && right == NULL) return true;
//         else if (left->val != right->val) return false;

//         // 下面为：左右节点都不为空，且数值相同的情况
//         bool outside = compare(left->left, right->right);   // 左子树：左、 右子树：右
//         bool inside = compare(left->right, right->left);    // 左子树：右、 右子树：左
//         bool isSame = outside && inside;                    // 左子树：中、 右子树：中 （逻辑处理）
//         return isSame;
//     }

//     bool isSymmetric(TreeNode* root) {
//         if (root == NULL) return true;
//         return compare(root->left, root->right);
//     }
// };

// 后序遍历迭代法单栈
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        stack<TreeNode*> result;
        result.push(root->left);
        result.push(root->right);
        while (!result.empty()){
            TreeNode* leftNode = result.top(); 
            result.pop();
            TreeNode* rightNode = result.top(); 
            result.pop();
            if (!leftNode && !rightNode) continue;
            if (!leftNode || !rightNode || (leftNode->val != rightNode->val)) return false;
            result.push(leftNode->left);   // 加入左节点左孩子
            result.push(rightNode->right); // 加入右节点右孩子
            result.push(leftNode->right);  // 加入左节点右孩子
            result.push(rightNode->left);  // 加入右节点左孩子
        }
        return true;
    }
};

// 后序遍历迭代法单队列
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode*> result;
        result.push(root->left);
        result.push(root->right);
        while (!result.empty()){
            TreeNode* leftNode = result.front(); 
            result.pop();
            TreeNode* rightNode = result.front(); 
            result.pop();
            if (!leftNode && !rightNode) continue;
            if (!leftNode || !rightNode || (leftNode->val != rightNode->val)) return false;
            result.push(leftNode->left);   // 加入左节点左孩子
            result.push(rightNode->right); // 加入右节点右孩子
            result.push(leftNode->right);  // 加入左节点右孩子
            result.push(rightNode->left);  // 加入右节点左孩子
        }
        return true;
    }
};
// @lc code=end

