// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem160.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-06 22:19:12
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-07 14:48:49
 */
/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 计算链表长度
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0;
        int lenB = 0;
        while(curA){
            curA = curA->next;
            lenA++;
        }
        while(curB){
            curB = curB->next;
            lenB++;
        }
        curA = headA;
        curB = headB;
        if (lenA > lenB){
            int i = lenA - lenB;
            while (i--){
                curA = curA->next;
            }
        }
        else{
            int i = lenB - lenA;
            while (i--){
                curB = curB->next;
            }
        }
        while (curA && curB){
            if (curA != curB){
                curA = curA->next;
                curB = curB->next;
            }
            else{
                return curA;
            }
        }
        return nullptr;
    }
};
// @lc code=end

