// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem151.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-12 22:03:15
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-15 16:47:13
 */
/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
// class Solution {
// public:
//     void reverse(string &s, int start, int end){
//         for (int left = start, right = end; left < right; left++, right--){
//             int temp = s[left];
//             s[left] = s[right];
//             s[right] = temp;
//         } 
//     }


//     string reverseWords(string s) {
//         // 统计单词数量以及字母个数确定新长度
//         int word_size = 0;
//         int words_num = 0;
//         for (int i = 0; i < s.size(); i++){
//             if (s[i] != ' '){
//                 for (int j = i; j < s.size(); j++){
//                     if (s[j] != ' '){
//                         word_size++;
//                         i = j;
//                     }
//                     else{
//                         i = j;
//                         break;
//                     }
//                 }
//                 words_num++;
                
//             }
//         }
//         int new_length = word_size + words_num - 1;
//         std:: cout << new_length << std::endl;
//         std:: cout << "word_size:" << word_size << std::endl;
//         std:: cout << "words_num:" << words_num << std::endl;
//         // 移除多余空字符
//         int space_size = 0;
//         for (int i = 0; i < s.size(); i++){
//             space_size = 0;
//             if (s[i] == ' '){
//                 for (int j = i; j < s.size(); j++){
//                     if (s[j] == ' '){
//                         space_size++;
//                         i = j;
//                     }
//                     else{
//                         i = j;
//                         break;
//                     }
//                 }
//                 std::cout << "space_size:" << space_size << std::endl;
//                 if (space_size > 1){
//                     for (int k = i; k < s.size(); k++){
//                         s[k - (space_size - 1)] = s[k];
//                     }
//                 }
//                 std::cout << s[i] << std::endl;
//                 std::cout << i << std::endl;
//                 i = i - (space_size - 1);
//             }
            
//         }
//         if (s[0] == ' '){
//             for (int k = 1; k < s.size(); k++){
//                 s[k - 1] = s[k];
//             }
//         }
//         s.resize(new_length);
//         for (int m = 0; m < s.size(); m++){
//             std::cout << s[m];
//         }
//         std::cout << std::endl;
//         // 整体反转翻转
//         reverse(s, 0, s.size() - 1);
//         // 局部翻转
//         int start = 0;
//         while (start < s.size() -1){
//             for (int end = start; end < s.size(); end++){
//                 if (s[end] == ' '){
//                     reverse(s, start, end - 1);
//                     start = end + 1;
//                     break;
//                 }
//                 if (end == s.size() - 1){
//                     reverse(s, start, end);
//                     start = end;
//                     break;
//                 }
//             }
//         }
//         return s;
//     }
// };

class Solution {
public:
    void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
        for (int i = 0; i < s.size(); ++i) { //
            if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
                if (slow != 0) 
                    s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); //slow的大小即为去除多余空格后的大小。
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
        reverse(s, 0, s.size() - 1);
        int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
            }
        }
        return s;
    }
};

// @lc code=end

