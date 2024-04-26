/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-11 21:38:53
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-11 21:41:02
 */
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size() - 1;
        for (int i = 0; i < s.size() / 2; i++){
            char temp = s[i];
            s[i] = s[n - i];
            s[n - i] = temp;
        }
        
    }
};
// @lc code=end

