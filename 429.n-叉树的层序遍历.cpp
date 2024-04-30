/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-30 19:32:06
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-30 19:48:55
 */
/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> node_queue;
        if (root != nullptr) node_queue.push(root);
        while (!node_queue.empty()){
            int size = node_queue.size();
            vector<int> layer;
            for (int i = 0; i < size; i++){
                Node* cur = node_queue.front();
                for (int j = 0; j < cur->children.size(); j++){
                    node_queue.push(cur->children[j]);
                }
                layer.push_back(cur->val);
                node_queue.pop();
            } 
            result.push_back(layer);
        }
        return result;
    }
};
// @lc code=end

