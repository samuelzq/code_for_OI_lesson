/**
 * https://www.luogu.com.cn/problem/B3623
 *
 * @File:   B3623.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-11
 *
 */
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int n, k;
vector<int> students;
vector<int> currentArrangement;
vector<bool> used;

void generateArrangements() {
    if (currentArrangement.size() == k) {
        for (int i = 0; i < k - 1; ++i) {
            cout << currentArrangement[i] << ' ';
        }
        cout <<  currentArrangement[k - 1] << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            used[i] = true;
            currentArrangement.push_back(students[i]);
            generateArrangements();
            currentArrangement.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    cin >> n >> k;

    students.resize(n);
    for (int i = 0; i < n; ++i) {
        students[i] = i + 1; // 学生编号为 1 到 n
    }

    used.resize(n, false);
    currentArrangement.clear();

    generateArrangements();

    return 0;
}
