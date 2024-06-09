// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem501.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-05 16:33:00
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-09 16:31:31
 */
/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
private:
    int maxCount = 0; // 最大频率
    int count = 0; // 统计频率
    TreeNode* pre = NULL;
    vector<int> result;
    void searchBST(TreeNode* cur) {
        if (cur == NULL) return ;

        searchBST(cur->left);       // 左
                                    // 中
        if (pre == NULL) { // 第一个节点
            count = 1;
        } else if (pre->val == cur->val) { // 与前一个节点数值相同
            count++;
        } else { // 与前一个节点数值不同
            count = 1;
        }
        pre = cur; // 更新上一个节点

        if (count == maxCount) { // 如果和最大值相同，放进result中
            result.push_back(cur->val);
        }

        if (count > maxCount) { // 如果计数大于最大值频率
            maxCount = count;   // 更新最大频率
            result.clear();     // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
            result.push_back(cur->val);
        }

        searchBST(cur->right);      // 右
        return ;
    }

public:
    // 统一迭代中序遍历
    void unified_iteration_middle_order_traversal(TreeNode* root, vector<int>& result) {
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            TreeNode* cur = node_stack.top();
            if (cur != NULL) {
                node_stack.pop();
                if (cur->right != NULL) node_stack.push(cur->right);
                node_stack.push(cur);
                node_stack.push(NULL);
                if (cur->left != NULL) node_stack.push(cur->left);
            }
            else {
                node_stack.pop();
                cur = node_stack.top();
                node_stack.pop();
                result.push_back(cur->val);
            }
        }
    }
    
    // 递归法中序遍历
    void recursion_middle_order_traversal(TreeNode* root, vector<int>& result) {
        if (root->left != NULL) recursion_middle_order_traversal(root->left, result);
        if (root != NULL) result.push_back(root->val);
        if (root->right != NULL) recursion_middle_order_traversal(root->right, result); 
    }

    // 迭代法中序遍历
    void iteration_middle_order_traversal(TreeNode* root, vector<int>& result) {
        stack<TreeNode*> node_stack;
        TreeNode* cur = root;
        while (cur != NULL || !node_stack.empty()) {
            if (cur != NULL) {
                node_stack.push(cur);
                cur = cur->left;
            }
            else {
                cur = node_stack.top();
                node_stack.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
    }


    vector<int> findMode1(TreeNode* root) {
        vector<int> tree_vals;
        vector<int> result;
        unordered_map<int, int> result_map;
        // unified_iteration_middle_order_traversal(root, tree_vals); // 统一迭代中序遍历
        // recursion_middle_order_traversal(root, tree_vals);// 递归法中序遍历
        iteration_middle_order_traversal(root, tree_vals);
        int num = 1;
        for (int i = 0; i < tree_vals.size(); i++) {
            auto it = result_map.find(tree_vals[i]);
            if (it != result_map.end()) {
                result_map[tree_vals[i]]++;
            }
            else {
                result_map[tree_vals[i]] = 1;
            }
        }

        auto max_pair = result_map.begin();
        // 迭代映射，寻找值最大的键
        for (auto it = result_map.begin(); it != result_map.end(); ++it) {
            if (it->second > max_pair->second) {
                max_pair = it;
            }
        }
        result.push_back(max_pair->first);
        for (auto it = result_map.begin(); it != result_map.end(); ++it) {
            if (it->second == max_pair->second && it->first != max_pair->first) {
                result.push_back(it->first);
            }
        }
        return result;
    }


    vector<int> findMode2(TreeNode* root) {
        vector<int> tree_vals;
        vector<int> result;
        
        // unified_iteration_middle_order_traversal(root, tree_vals); // 统一迭代中序遍历
        // recursion_middle_order_traversal(root, tree_vals);// 递归法中序遍历
        iteration_middle_order_traversal(root, tree_vals);
        int cur_val = tree_vals[0];
        int num = 1;
        int vals_max_num = 1;
        for (int i = 1; i < tree_vals.size(); i++) {
            if (tree_vals[i] == cur_val) {
                num++;
            }
            else {
                if (num > vals_max_num) {
                    // 若大于当前结果里面的数对应的数量，则全部删除后加入
                    while (result.size() > 0)
                    {
                       result.pop_back();
                    }
                    result.push_back(cur_val);
                    vals_max_num = num;
                }else if (num == vals_max_num){
                    result.push_back(cur_val);
                }
                cur_val = tree_vals[i];
                num = 1;
            }
        }
        // 处理最后的一个元素
        if (num > vals_max_num) {
            while (result.size() > 0)
            {
                result.pop_back();
            }
            result.push_back(cur_val);
        }
        if (num == vals_max_num) {
            result.push_back(cur_val);
        }

        return result;
    }

    // 递归法在遍历树的的时候操作
    vector<int> findMode3(TreeNode* root) {
        count = 0;
        maxCount = 0;
        pre = NULL; // 记录前一个节点
        result.clear();
        searchBST(root);
        return result;
    }

    // 迭代法在遍历树的时候操作
    vector<int> findMode4(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> node_stack;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        int vals_max_num = 0;
        int num = 0;
        while (cur != NULL || !node_stack.empty()) {
            if (cur != NULL) {
                node_stack.push(cur);
                cur = cur->left;
            }
            else {
                cur = node_stack.top();
                node_stack.pop();
                if (pre == NULL) {
                    num = 1;
                }
                else if (pre->val == cur->val) {
                    num++;
                }
                else {
                    num = 1;
                }
                if (num == vals_max_num) {
                    result.push_back(cur->val);
                }
                if (num > vals_max_num) { // 如果计数大于最大值频率
                    vals_max_num = num;   // 更新最大频率
                    result.clear();     // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
                    result.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        
        return result;
    }
    

    vector<int> findMode(TreeNode* root) {
        // return findMode1(root); // 得到数组后第一种求众数
        // return findMode2(root); // 得到数组后第二种求众数
        return findMode3(root); // 递归法在遍历树的的时候操作
        // return findMode4(root); // 迭代法在遍历树的时候操作
    }
};
// @lc code=end

