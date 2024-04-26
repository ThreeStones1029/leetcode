/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-26 22:39:59
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-26 23:01:35
 */
/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> number;
        for (int i = 0; i < tokens.size(); i++){
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                std::cout << "hello world" << std::endl;
                int int_number = (int) tokens[i];
                number.push(int_number);
            }
            else{
                int second = number.top();
                number.pop();
                int first = number.top();
                number.pop();
                if (tokens[i] == "+"){
                    number.push(first + second);
                }
                if (tokens[i] == "-"){
                    number.push(first - second);
                }
                if (tokens[i] == "*"){
                    number.push(first * second);
                }
                if (tokens[i] == "/"){
                    number.push(first / second);
                }
            }
        }
        return number.top();
    }
};
// @lc code=end

