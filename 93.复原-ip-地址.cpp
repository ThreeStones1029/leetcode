/*
 * @Description:    
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-26 22:40:02
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-28 21:06:18
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
    std::string path;
    void backtracking(std::string s, int start) {
        if (start == s.size()) {
            result.push_back(path);
        }
        for (int i = start; i < s.size(); i++) {
            std::string cur(s.begin() + start, s.begin() + i + 1);
            path += cur;
            path += ".";
            backtracking(s, i + 1);
            path = path.substr(0, path.size() - (i + 2 - start));
        }

    }
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        backtracking(s, 0);
        return result;
    }
};
// @lc code=end

