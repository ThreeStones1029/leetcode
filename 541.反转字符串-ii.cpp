// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem541.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-11 21:49:46
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-12 21:22:41
 */
/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
// class Solution {
// public:
//     string reverseStr(string s, int k) {
//         int num = s.size() / (2* k) + 1;
//         for (int i = 0; i < num; i++){
//             if (i != num - 1){
//                 int end = i * 2 * k + k - 1;
//                 int start = i * 2 * k;
//                 for (int m = start; m < (end + 1 + start) / 2; m++){
//                     char tmp = s[m];
//                     s[m] = s[end - (m - start)];
//                     s[end - (m - start)] = tmp;
//                 }
//             }
//             else{
//                 int remain = s.size() - (num - 1) * 2 * k;
//                 int start = (num - 1) * 2 * k;
//                 if (remain < k){
//                     int end = s.size() - 1;
//                     for (int m = start; m < (end + 1 + start) / 2; m++){
//                         char tmp = s[m];
//                         s[m] = s[end - (m - start)];
//                         s[end - (m - start)] = tmp;
//                     }
//                 }
//                 if (remain >= k && remain < 2 * k){
//                     int end = (num - 1) * 2 * k + k - 1;
//                     for (int m = start; m < (end + 1 + start) / 2; m++){
//                         char tmp = s[m];
//                         s[m] = s[end - (m - start)];
//                         s[end - (m - start)] = tmp;
//                     }
//                 }
//             }
            
//         }
//     return s;
//     }
// };


class Solution {
public:
    void reverse(string &s, int start, int end){
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s, i, i + k - 1);
                continue;
            }
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            reverse(s, i, s.size() - 1);
        }
        return s;
    }
};
// @lc code=end

