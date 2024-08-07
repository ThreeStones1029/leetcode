/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-08-07 11:11:50
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-08-07 11:27:16
 */
#include <vector>
#include <iostream>
#include <unordered_map>


std::vector<int> find_max_number_vector(std::vector<int> array){
    std::vector<int> result;
    std::unordered_map<int, int> number_and_count_map;
    for (auto number : array) {
        number_and_count_map[number]++;
    }
    int max_count = 0;
    int max_count_number = 0;
    for (auto number_and_count : number_and_count_map) {
        if (number_and_count.second > max_count) {
            max_count = number_and_count.second;
            max_count_number = number_and_count.first;
        }
    }
    result.push_back(max_count_number);
    return result;
}

int main() {
    std::vector<int> result;
    std::vector<int> nums = {1, 2, 3, 2, 2, 3, 4, 5, 2};
    result = find_max_number_vector(nums);
    for (auto number: result){
        std::cout << number << std::endl;
    }
    return 0;
}