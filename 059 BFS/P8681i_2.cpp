/**
 * https://www.luogu.com.cn/problem/P8681
 *
 * @File:   P8681i_2.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-03-22
 *
 */
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> weights(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> weights[i];
    }

    long long maxSum = LLONG_MIN;
    int maxDepthIndex = 0;

    int currentLevelStart = 1;     // 当前层的起始索引
    int currentLevelSize = 1;      // 当前层的节点数
    int currentLevel = 0;          // 当前层数
    long long currentLevelSum = 0; // 当前层的权值和

    for (int i = 1; i <= n; ++i) {
        currentLevelSum += weights[i];
        if (i == currentLevelStart + currentLevelSize - 1 || i == n) {  // 当到达当前层的最后一个节点
            if (currentLevelSum > maxSum) {
                maxSum = currentLevelSum;
                maxDepthIndex = currentLevel + 1;
            }
            currentLevel++;
            currentLevelStart = i + 1;
            currentLevelSize *= 2;
            currentLevelSum = 0;
        }
    }

    cout << maxDepthIndex << endl;
    return 0;
}
