/**
 *
 * @File:   binary_search_cmp.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-07
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {9, 7, 5, 3, 1};  // 降序排列的数组
    int target = 5;

    // 自定义比较器（降序比较规则）
    auto comp = [](int a, int b) {
        return a > b;
    };

    // 使用 binary_search 查找目标值
    bool found = std::binary_search(vec.begin(), vec.end(), target, comp);

    if (found) {
        std::cout << "Found " << target << " in the array." << std::endl;
    } else {
        std::cout << "Did not find " << target << " in the array." << std::endl;
    }

    return 0;
}
