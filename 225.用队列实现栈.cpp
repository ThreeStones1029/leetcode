// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem225.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-24 22:39:59
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-26 20:40:04
 */
/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
// 两个队列
// class MyStack {
// public:
//     queue<int> queue1;
//     queue<int> queue2;
//     MyStack() {}

//     void push(int x) {
//         if (queue1.empty() && !queue2.empty()) {
//             queue2.push(x);
//         } 
//         if (!queue1.empty() && queue2.empty()){
//             queue1.push(x);
//         }
//         if (queue1.empty() && queue2.empty()){
//             queue1.push(x);
//         }

//     }

//     int pop() {
//         int tmp;
//         if (!queue1.empty()) {
//             while (queue1.size() > 1) {
//                 queue2.push(queue1.front());
//                 queue1.pop();
//             }
//             tmp = queue1.front();
//             queue1.pop();
//         } else {
//             while (queue2.size() > 1) {
//                 queue1.push(queue2.front());
//                 queue2.pop();
//             }
//             tmp = queue2.front();
//             queue2.pop();
//         }
//         return tmp;
//     }

//     int top() {

//         int tmp = pop();
//         if (!queue1.empty()) {
//             queue1.push(tmp);
//         } 
//         if (!queue2.empty()){
//             queue2.push(tmp);
//         }
//         if (queue2.empty() && queue1.empty()){
//             queue1.push(tmp);
//         }
//         return tmp;
//     }

//     bool empty() {
//         return queue1.empty() && queue2.empty();
//     }
// };
// 单个队列
class MyStack {
public:
    queue<int> queue;
    MyStack() {}

    void push(int x) {
        if (queue.empty()){
            queue.push(x);
        }
        else{
            queue.push(x);
            int count = queue.size() - 1;
            while (count > 0){
                int tmp = queue.front();
                queue.pop();
                count--;
                queue.push(tmp);
            }
        }
    }

    int pop() {
        int tmp = queue.front();
        queue.pop();
        return tmp;
    }

    int top() {
        return queue.front();
    }

    bool empty() {
        return queue.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

