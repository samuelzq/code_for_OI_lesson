/**
 *
 * @File:   permutation.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-11
 *
 */
#include <iostream>
#include <vector>
#include <algorithm> // 包含 std::next_permutation 和 std::sort

int main() {
    std::vector<int> nums = {1, 2, 3};

    // 为了生成所有排列，我们需要先对序列进行排序，
    // 这样 std::next_permutation 才能从最小的排列开始生成。
    std::sort(nums.begin(), nums.end());

    std::cout << "集合 {1, 2, 3} 的全排列是:" << std::endl;

    do {
        std::cout << "[";
        for (size_t i = 0; i < nums.size(); ++i) {
            std::cout << nums[i];
            if (i < nums.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    } while (std::next_permutation(nums.begin(), nums.end()));

    return 0;
}
