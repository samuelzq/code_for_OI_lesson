/**
 *
 * @File:   combination.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-13
 *
 */
#include <iostream>
#include <vector>

using namespace std;

int n; // 全局变量：集合的大小
int k; // 全局变量：要选择的元素个数
vector<int> currentCombination; // 全局变量：存储当前正在构建的组合
vector<vector<int>> allCombinations; // 全局变量：存储所有生成的组合

// 回溯函数：递归地生成组合
void backtrack(int start) {
    // 基本情况：当当前组合的大小等于 k_global 时，说明找到了一个有效的组合
    if (currentCombination.size() == k) {
        allCombinations.push_back(currentCombination); // 将该组合添加到结果列表中
        return;
    }

    // 递归步骤：从 start 开始遍历可能的数字
    for (int i = start; i <= n; ++i) {
        // 做出选择：将当前数字 i 添加到当前组合中
        currentCombination.push_back(i);

        // 递归调用：继续从下一个数字 (i + 1) 开始选择剩余的 k - currentCombination.size() 个数字
        backtrack(i + 1) ;

   // 撤销选择：将当前数字 i 从当前组合中移除，以便尝试其他可能的组合
        currentCombination.pop_back(); // 这是回溯的关键步骤
    }
}

int main() {
    cout << "请输入 n (集合的大小): ";
    cin >> n;

    cout << "请输入 k (要选择的元素个数): ";
    cin >> k;

    if (k > n || k < 0) {
        cout << "无效的输入：k 必须在 0 到 n 之间。" << endl;
        return 1;
    }

    backtrack(1); // 从数字 1 开始回溯

    cout << n << " 选 " << k << " 的组合如下:" << endl;
    for (const auto& combination : allCombinations) {
        cout << "[ ";
        for (int val : combination) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
        // 撤销选择：将当前数字 i 从当前组合中移除，以便尝试其他可能的组合
