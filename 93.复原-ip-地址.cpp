/*
 * @Description:    
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-26 22:40:02
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-08-29 16:10:12
 */
/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include <iostream>
#include <vector>
#include <string>

// @lc code=start
class Solution {
private:
    std::vector<std::string> result;
    
    bool is_valid(const std::string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        // 0开头的数字不合法
        if (s[start] == '0' && start != end) {
            return false;
        }
        // 排除掉不合法的字符以及大于255的部分
        int sum = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
            sum = sum * 10 + (s[i] - '0');
            if (sum > 255) {
                return false;
            }
        }
        return true;
    }

    void backtracking(std::string s, int start, int points_num) {
        if (points_num == 3) {
            if (is_valid(s, start, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (is_valid(s, start, i)) {
                s.insert(s.begin() + i + 1, '.');
                points_num++;
                backtracking(s, i+2, points_num);
                points_num--;                         // 回溯
                s.erase(s.begin() + i + 1);         // 回溯删掉逗点
            }
            else break;
        } 
    }


public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        // 初步减枝
        result.clear();
        if (s.size() < 4 || s.size() > 12) return result;
        backtracking(s, 0, 0);
        return result;
    }
};

// @lc code=end

