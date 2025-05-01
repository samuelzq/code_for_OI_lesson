/**
 *
 * @File:   sort_partial.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-04
 *
 */
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {5, 3, 1, 4, 2};

    // 对前 3 个元素排序
    std::sort(vec.begin(), vec.begin() + 3);

    // 输出结果
    for (int x : vec) {
        std::cout << x << " "; // 输出：1 3 5 4 2
    }
    return 0;
}
