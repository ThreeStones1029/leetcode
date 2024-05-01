// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem116.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-30 20:03:15
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-05-01 20:38:02
 */
/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> result;
        queue<Node*> node_queue;
        if (root == NULL) return root;
        node_queue.push(root);
        while (!node_queue.empty()){
            int size = node_queue.size();
            vector<Node*> layer;
            for (int i = 0; i < size; i++){
                Node* cur = node_queue.front();
                layer.push_back(cur);
                node_queue.pop();
                if (cur->left != NULL) node_queue.push(cur->left);
                if (cur->right != NULL) node_queue.push(cur->right);
            }
            result.push_back(layer);
        }
        for (int i = 0; i < result.size(); i++){
            for (int j = 0; j < result[i].size(); j++){
                if ( j != result[i].size() - 1){
                    result[i][j]->next = result[i][j + 1];
                }
                else{
                    result[i][j]->next = NULL;
                }
            }
        }
        return result[0][0];
    }
};
// @lc code=end

