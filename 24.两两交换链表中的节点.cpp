// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem24.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-06 21:07:06
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-07 14:09:45
 */
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        // 双指针
        // ListNode* dummyHead = new ListNode();
        // dummyHead->next = head;
        // ListNode* pre = dummyHead;
        // ListNode* cur = head;
        // while (cur && cur->next){
        //     ListNode* temp = cur->next->next;
        //     pre->next = cur->next;
        //     cur->next->next = cur;
        //     cur->next = temp;
        //     pre = cur;
        //     cur = temp;
        // }
        // return dummyHead->next;

        // 单指针
        // ListNode* dummyHead = new ListNode();
        // dummyHead->next = head;
        // ListNode* cur = dummyHead;
        // while (cur->next && cur->next->next){
        //     // 记录临时结点
        //     ListNode* temp = cur->next;
        //     ListNode* temp2 = cur->next->next->next;
        //     cur->next = cur->next->next;
        //     cur->next->next = temp;
        //     temp->next = temp2;
        //     cur = cur->next->next;
        // }
        // return dummyHead->next;

        // 生成奇偶链表
        ListNode* odd_dummyHead = new ListNode();
        ListNode* even_dummyHead = new ListNode();
        ListNode* odd_cur = odd_dummyHead;
        ListNode* even_cur = even_dummyHead;
        ListNode* cur = head;
        int i = 0;
        while (cur){
            i += 1;
            if (i % 2 == 1){
                odd_cur->next = cur;
                odd_cur = odd_cur->next;
            }
            else{
                even_cur->next = cur;
                even_cur = even_cur->next;
            }
            cur = cur->next;    
        }
        odd_cur->next = nullptr;
        even_cur->next = nullptr;
        
        // 依次合并奇偶链表,先偶数再奇数
        odd_cur = odd_dummyHead->next;
        even_cur = even_dummyHead->next;
        // debug
        // while (odd_cur){
        //     std::cout << odd_cur->val << std::endl;
        //     odd_cur = odd_cur->next;
        // }
        // while (even_cur){
        //     std::cout << even_cur->val << std::endl;
        //     even_cur = even_cur->next;
        // }
        ListNode *new_dummyHead = new ListNode();
        ListNode *new_cur = new_dummyHead;
        while (odd_cur && even_cur){
            std::cout << even_cur->val << std::endl;
            std::cout << odd_cur->val << std::endl;
            new_cur->next = even_cur;
            ListNode* even_tmp = even_cur->next;
            new_cur = even_cur;
            new_cur->next = odd_cur;
            ListNode* odd_tmp = odd_cur->next;
            new_cur = new_cur->next;
            odd_cur = odd_tmp;
            even_cur = even_tmp;
        }
        if (odd_cur){
            new_cur->next = odd_cur;
        }
        return new_dummyHead->next;
    }
};
// @lc code=end

