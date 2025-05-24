/**
 * https://www.luogu.com.cn/problem/P4305
 *
 * @File:   p4305.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-14
 *
 */
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); // 关闭同步流，加速输入输出

    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n;
        vector<int> res;     // 保存结果（保留顺序）
        unordered_set<int> seen; // 去重检查

        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (!seen.count(x)) { // 若未出现过
                res.push_back(x);
                seen.insert(x);
            }
        }

        // 输出结果
        for (int num : res) cout << num << " ";
        cout << "\n";
    }
    return 0;
}
