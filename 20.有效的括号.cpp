/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
// 碰到左括号,左括号入栈
// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> left_symbol;
//         for (int i = 0; i < s.size(); i++){
//             if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
//                 left_symbol.push(s[i]);
//             }
//             else{
//                 if (!left_symbol.empty()){
//                     char right_symbol = left_symbol.top();
//                     left_symbol.pop();
//                     if ((s[i] == ']' && right_symbol != '[') || (s[i] == '}' && right_symbol != '{') || (s[i] == ')' && right_symbol != '(')){
//                         return false;
//                     }
//                 }
//                 else{
//                     return false;
//                 }
                
//             }
//         }
//         return left_symbol.empty();
//     }
// };
// 来自代码随想录,遇到左括号,将对应右括号入栈,然后碰到右括号,比较栈顶元素与当前元素是否相等.
class Solution {
public:
    bool isValid(string s) {
        stack<char> right_symbol;
        if (s.size() % 2 != 0) return false;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                right_symbol.push(')');
            }
            else if (s[i] == '['){
                right_symbol.push(']');
            }
            else if (s[i] == '{'){
                right_symbol.push('}');
            }
            else if (!right_symbol.empty() && s[i] == right_symbol.top()){
                right_symbol.pop();
            }
            else{
                return false;
            }
        }
        return right_symbol.empty();
    }
};
// @lc code=end

