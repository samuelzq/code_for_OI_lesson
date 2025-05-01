/**
 *
 * @File:   123_swap.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-10
 *
 */
#include <iostream>
#include <vector>
#include <algorithm> // 为了使用 std::swap

using namespace std;
vector<vector<int>> allPermutations;

// 递归函数生成全排列
void generatePermutations(vector<int>& elements, int k) {
    // 基本情况：当 k 等于元素个数时，表示已经完成了一个排列
    if (k == elements.size()) {
        allPermutations.push_back(elements); // 将当前排列添加到结果中
        return;
    }

    // 遍历从 k 到最后一个元素
    for (int i = k; i < elements.size(); ++i) {
        // 将当前元素与第 k 个位置的元素交换
        swap(elements[k], elements[i]);

        // 递归地为下一个位置 (k+1) 生成排列
        generatePermutations(elements, k + 1);

        // 恢复原始顺序（回溯）
        swap(elements[k], elements[i]);
    }
}

int main() {
    vector<int> nums = {1, 2, 3};

    generatePermutations(nums, 0);

    cout << "集合 {1, 2, 3} 的全排列是:" << endl;
    for (const auto& perm : allPermutations) {
        cout << "[";
        for (size_t i = 0; i < perm.size(); ++i) {
            cout << perm[i];
            if (i < perm.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
