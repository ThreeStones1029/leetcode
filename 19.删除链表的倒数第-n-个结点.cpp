/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-06 22:01:09
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-07 15:06:49
 */
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 暴力解法
        // 先遍历得到所有的结点数目
        // ListNode* cur = head;
        // int node_number = 0;
        // while (cur) {
        //     node_number++;
        //     cur = cur->next;
        // }
        // // 创建哑结点
        // ListNode* dummyHead = new ListNode();
        // dummyHead->next = head;
        // cur = dummyHead;
        // int i = node_number - n;
        // while (i--){
        //     cur = cur->next;
        // }
        // ListNode* temp = cur->next;
        // cur->next = cur->next->next;
        // delete temp;
        // head = dummyHead->next;
        // delete dummyHead;
        // return head;

        // 双指针
        // 先让快指针先走n步,再慢指针与快指针同时走
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        int i = n;
        while (i--){
            fast = fast->next;
        }
        while (fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return dummyHead->next;
    }
};
// @lc code=end

