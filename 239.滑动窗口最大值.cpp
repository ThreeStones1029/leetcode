// @before-stub-for-debug-begin
#include <vector>
#include <string>


using namespace std;
// @before-stub-for-debug-end

/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-27 09:58:54
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-29 22:27:58
 */
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=star
// 暴力解法 会超时
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> result;
//         int n = nums.size();
//         int max_value;
//         for (int i = 0; i < n - k + 1; i++){
//             max_value = nums[i];
//             for (int j = i; j < i + k; j++){
//                 if (nums[j] > max_value){
//                     max_value = nums[j];
//                 }

//             }
//             result.push_back(max_value);
//         }
//         return result;
//     }
// };

// 单调队列
class Solution {
private:
    class MyQueue {
    public:
        deque<int> que;
        // 当队列不空且比较当前要弹出的数值是否等于队列出口元素的数值,因为较小的数会在push的时候pop
        void pop(int value){
            if (!que.empty() && que.front() == value){
                que.pop_front();
            }
        }

        void push(int value){
            // 主要用于保证pop后还是最大的数字在开头
            while (!que.empty() && que.back() < value){
                que.pop_back();
            }
            que.push_back(value);
        }

        int front(){
            return que.front();
        }

    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQueue que;
        for (int i = 0; i < k; i++){
            que.push(nums[i]);
        }
        result.push_back(que.front()); // result 记录前k的元素的最大值
        for (int i = k; i < nums.size(); i++){
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
// @lc code=end

