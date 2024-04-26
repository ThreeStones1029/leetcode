// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1047.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-26 21:39:36
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-26 22:39:25
 */
/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
// class Solution {
// public:
//     string removeDuplicates(string s) {
//         stack<char> char_stack;
//         stack<char> result;
//         string result_string(s);
//         char_stack.push(s[0]);
//         for (int i = 1; i < s.size();i++){
//             if (!char_stack.empty() && char_stack.top() == s[i]){
//                 char_stack.pop();
//             }
//             else{
//                 char_stack.push(s[i]);
//             }
//         }
//         while (!char_stack.empty()){
//             result.push(char_stack.top());
//             char_stack.pop();
//         }
//         int n = result.size();
//         int i = 0;
//         while (i < n){
//             result_string[i] = result.top();
//             result.pop();
//             i++;
//         }
//         result_string.resize(n);
//         return result_string;
//     }
// };

// 暴力原地删除
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        int i = 1;
        while (i < n){
            if (i - 1 >= 0 && s[i] == s[i - 1]){
                // 当有相等的字符,则向前移动两个字符
                for (int j = i; j < n - 1; j++){
                    s[j - 1] = s[j + 1];
                }
                n -= 2;
                i -= 2;
            }
            else{
                i += 1;
            }
        }
        s.resize(n);
        return s;
    }
};
// @lc code=end

