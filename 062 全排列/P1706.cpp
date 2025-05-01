/**
 * https://www.luogu.com.cn/problem/P1706
 *
 * @File:   P1706.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-10
 *
 */
#include <iostream>
#include <vector>
#include <iomanip> // 用于设置输出场宽

using namespace std;

vector<int> currentPermutation;
vector<bool> used;
int n;

void generatePermutations() {
    if (currentPermutation.size() == n) {
        for (int num : currentPermutation) {
            cout << setw(5) << num;
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            currentPermutation.push_back(i);
            used[i] = true;
            generatePermutations();
            used[i] = false; // 回溯
            currentPermutation.pop_back(); // 回溯
        }
    }
}

int main() {
    cin >> n;
    used.resize(n + 1, false); // 注意索引从 1 开始

    generatePermutations();

    return 0;
}
