// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem242.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-07 22:09:56
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-09 21:34:23
 */
/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    string choose_sort(string s){
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            int min_index = i;
            for (int j = i + 1; j < n; ++j) {
                if (s[j] < s[min_index]) {
                    min_index = j;
                }
            }
            // 将未排序部分的最小元素与已排序部分的末尾交换位置
            int temp = s[i];
            s[i] = s[min_index];
            s[min_index] = temp;
        }
        return s;
    }
    bool isAnagram(string s, string t) {
        // 直接调用库版本
        // if (s.size() != t.size()){
        //     return false;
        // }
        // multiset<int> s_multi_set;
        // multiset<int> t_multi_set;
        // for (int i = 0; i < s.size(); i++){
        //     s_multi_set.insert(s[i]);
        //     t_multi_set.insert(t[i]);
        // }
        // for (auto  m = s_multi_set.begin(), n = t_multi_set.begin(); m != s_multi_set.end() && n != t_multi_set.end(); m++, n++){
        //     if (*m != *n){
        //         return false;
        //     }
        // }
        // return true;
        // 数组法
        // int record[26] = {0};
        // for (int i = 0; i < s.size(); i++){
        //     record[s[i] - 'a'] += 1;
        // }
        // for (int i = 0; i < t.size(); i++){
        //     record[t[i] - 'a'] -= 1;
        // }
        // for (int i = 0; i < 26; i++){
        //     if (record[i] != 0){
        //         return false;
        //     }
        // }
        // return true;
        // 暴力解法
        // 先排序
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s==t;

        // 暴力解法2
        // 选择排序

        s = choose_sort(s);
        t = choose_sort(t);
        return s==t;
    }
        
};
// @lc code=end

