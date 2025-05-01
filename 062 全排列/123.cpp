/**
 *
 * @File:   123.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-10
 *
 */
#include <iostream>
#include <vector>

using namespace std;

vector<bool> used; // 全局变量，标记元素是否被使用
vector<vector<int>> allPermutations; // 全局变量，存储所有全排列

void generatePermutations(vector<int>& nums, vector<int>& currentPermutation) {
    if (currentPermutation.size() == nums.size()) {
        allPermutations.push_back(currentPermutation);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
            currentPermutation.push_back(nums[i]);
            used[i] = true;
            generatePermutations(nums, currentPermutation);
            currentPermutation.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> currentPermutation;
    used.resize(nums.size(), false); // 初始化 used 向量

    generatePermutations(nums, currentPermutation);

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
