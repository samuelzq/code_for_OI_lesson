/**
 *
 * @File:   sort.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-02
 *
 */
#include <iostream>
#include <deque>
#include <algorithm>  // 包含 std::sort
int main() {
    std::deque<int> vec = {5, 2, 8, 1, 9};
    // 使用 std::sort 对 vec 进行排序
    std::sort(vec.begin(), vec.end());
    // 输出排序后的结果
    for (int x : vec) {
        std::cout << x << " ";  // 输出：1 2 5 8 9
    }
    return 0;
}
