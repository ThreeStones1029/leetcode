// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem131.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-20 23:07:42
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-23 23:20:44
 */
/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;

    
    bool is_palindromic_string(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) return false;
        }
        return true;
    }

    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    // 回溯
    void backtracking1(string s, int start) {
        // 结束当前切割方法
        if (start == s.size()) {
            bool is_path = true;
            for (int i = 0; i < path.size(); i++) {
                if (!is_palindromic_string(path[i])) is_path = false;
            }
            if (is_path) result.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            string cur(s.begin() + start, s.begin() + i + 1);
            path.push_back(cur);
            backtracking1(s, i + 1);
            path.pop_back();
        }
    }

    // 
    void backtracking2(string s, int start) {
        if (start == s.size()) {
            result.push_back(path);
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                string cur = s.substr(start, i - start + 1);
                path.push_back(cur);
            }
            else continue;
            backtracking2(s, i + 1);
            path.pop_back();
        }
    }

    
public:
    vector<vector<string>> partition(string s) {
        // 方法一
        // backtracking1(s, 0);

        // 方法二
        backtracking2(s, 0);
        return result;
    }
};
// @lc code=end

