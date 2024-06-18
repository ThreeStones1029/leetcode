// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-06-18 22:42:41
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-06-18 23:27:47
 */
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    vector<string> result;
    string path;
    void backtracking(vector<string> letters, int startIndex) {
        if (path.size() == letters.size()) {
            result.push_back(path);
        }
        for (int i = 0; i < letters.size(); i++) {
            
        }

    }


public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> number2letter;
        number2letter['2'] = "abc";
        number2letter['3'] = "def";
        number2letter['4'] = "ghi";
        number2letter['5'] = "jkl";
        number2letter['6'] = "mno";
        number2letter['7'] = "pqrs";
        number2letter['8'] = "tuv";
        number2letter['9'] = "wxyz";
        vector<string> letters;
        for (int i = 0; i < digits.size(); i++){
            string letter = number2letter[digits[i]];
            letters.push_back(letter);
        }
        backtracking();
        return result;
    }
};
// @lc code=end

