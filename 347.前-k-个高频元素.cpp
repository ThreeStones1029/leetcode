/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-29 22:34:27
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-29 23:11:26
 */
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
private:
    class mycomparison{
    public:
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计元素出现频率
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 结果数组, 倒序输出数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }

        return result;
    }
};
// @lc code=end

