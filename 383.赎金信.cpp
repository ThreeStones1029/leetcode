// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem383.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-09 22:02:02
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-09 22:21:14
 */
/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int num1[26] = {0};
        int num2[26] = {0};
        for (int i = 0; i < ransomNote.size(); i++){
            num1[ransomNote[i] - 'a']++;
        }
        for (int i = 0; i < magazine.size(); i++){
            num2[magazine[i] - 'a']++;
        }
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < 26; i++){
            if (num1[i] != 0){
                count1++;
            }
            if (num1[i] != 0 && num1[i] <= num2[i]){
                count2++;
            }
        }
        if (count1 == count2){
            return true;
        }
        else{
            return false;
        }
        return false;
    }
};
// @lc code=end

