/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-15 20:52:06
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-15 21:48:40
 */
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    void getNext(int *next, string s){
        // i为前缀的末尾
        // j为后缀的末尾
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++){
            while (j > 0 && s[i] != s[j]){
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }

    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0){
            return 0;
        }
        vector<int> next(needle.size());
        getNext(&next[0], needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++){
            // 直到找到相等的再重新重这个相等的开始匹配
            while (j > 0 && haystack[i] != needle[j]){
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;

    }
};
// @lc code=end

