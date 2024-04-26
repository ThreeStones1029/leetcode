/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-05 15:05:40
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-05 22:36:08
 */
/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        // 解法一 设置哑结点
        // ListNode* dummyHead = new ListNode(0);
        // dummyHead->next = head;
        // ListNode* cur = dummyHead;
        // while(cur->next){
        //     if (cur->next->val == val){
        //         ListNode* tmp = cur->next;
        //         cur->next = cur->next->next; 
        //         delete tmp;
        //     }
        //     else{
        //         cur = cur->next;
        //     } 
        // }
        // head = dummyHead->next;
        // delete dummyHead;
        // return head;
        // 解法二 不设置哑结点
        // 删除头结点
        while (head && head->val == val){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        // 删除非头结点
        ListNode* cur = head;
        while (cur && cur->next){
            if (cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else{
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end

