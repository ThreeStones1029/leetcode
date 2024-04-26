/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-05 20:08:48
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-06 21:02:07
 */
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverse(ListNode* pre, ListNode* cur){
        if (cur==nullptr){
            return pre;
        }
        ListNode* temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);

    }
    ListNode* reverseList(ListNode* head) {
        // 头插法 空间复杂度O(n),时间复杂度O(1)
        // if (head == nullptr || head->next == nullptr){
        //     return head;
        // }
        // ListNode* cur = head; // 用于遍历原始链表
        // ListNode* dummyHead = new ListNode(); // 创建新链表哑节点
        // while(cur){
        //     ListNode* new_node = new ListNode();
        //     new_node->val = cur->val;
        //     new_node->next = dummyHead->next;
        //     dummyHead->next = new_node;
        //     cur = cur->next;
        // }
        // return dummyHead->next;

        // 双指针法 时间复杂度是为O(n),空间复杂度为O(1)
        // if (head == nullptr || head->next == nullptr){
        //     return head;
        // }
        // ListNode* dummyHead = new ListNode(); // 创建哑节点
        // dummyHead->next = head;
        // ListNode* pre = dummyHead;
        // ListNode* cur = head;
        // while (cur){
        //     ListNode* temp = new ListNode();
        //     temp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = temp;
        // }
        // head->next = nullptr;
        // return pre;
        // 递归法
        return reverse(nullptr, head);

        
    }
};
// @lc code=end

