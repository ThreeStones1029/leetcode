/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-04-04 22:08:38
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-04-05 11:13:33
 */
/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 左闭右闭
        // vector<vector<int>> matrix(n, vector<int>(n, 0));
        // int loop = 1; //loop表示圈数
        // int x = 0; // x起始坐标
        // int y = 0; // y起始坐标
        // int k = 1;
        // int length = n - 1; // 圈边的长度
        // while (loop <= n / 2){
        //     // 从左到右
        //     for (int i = x, j = y; j <= y + length - 1; j++){
        //         matrix[i][j] = k++;
        //     }
        //     //从上到下
        //     for (int i = x, j = y + length; i <= x + length - 1; i++){
        //         matrix[i][j] = k++;
        //     }
        //     // 从右到左
        //     for (int i = x + length, j = y + length; j >= y + 1; j--){
        //         matrix[i][j] = k++;
        //     }
        //     // 从下到上
        //     for (int i = x + length , j = y; i >= x + 1; i--){
        //         matrix[i][j] = k++;
        //     }
        //     x++;
        //     y++;
        //     length -= 2;
        //     loop++;
        // }
        // if ((n % 2) != 0){
        //     matrix[n / 2][n / 2] = k;
        // }
        // return matrix;

        // 左闭右开
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int x = 0;
        int y = 0;
        int loop = n / 2;
        int count = 1;
        int offset = 1;
        int i, j;
        while (loop--){
            i = x;
            j = y;
            for (j = y; j < n - offset; j++){
                matrix[i][j] = count++;
            }
            for (i = x; i < n - offset; i++){
                matrix[i][j] = count++;
            }
            for (; j > y; j--){
                matrix[i][j] = count++;
            }
            for (; i > x; i--){
                matrix[i][j] = count++;
            } 
            x++;
            y++;
            offset++;
        }
        if ( n % 2 != 0){
                matrix[n / 2][n / 2] = count;
            }
            
        return matrix;
    }
};
// @lc code=end

