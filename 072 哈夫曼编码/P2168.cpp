/**
 * https://www.luogu.com.cn/problem/P2168
 *
 * @File:   P2168.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-01
 *
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;

    // 使用优先队列，pair的first是权值，second是深度
    // 默认按first升序排列，first相同时按second升序
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    // 输入初始权值，深度均为0
    for (int i = 0; i < n; ++i) {
        ll w;
        cin >> w;
        pq.emplace(w, 0);
    }

    // 补虚拟节点（权值0，深度0），使得合并次数满足 (n-1) % (k-1) == 0
    while (k > 2 && (pq.size() - 1) % (k - 1) != 0) {
        pq.emplace(0, 0);
    }

    ll total = 0;       // WPL 树的带权路径
    int max_depth = 0;  // 全局变量记录最大深度

    while (pq.size() > 1) {
        ll sum = 0;
        int depth = 0;

        // 取出k个最小元素
        for (int i = 0; i < k; ++i) {
            auto [w, d] = pq.top();
            pq.pop();
            sum += w;
            depth = max(depth, d);  // 更新当前合并的最大深度
        }

        total += sum;  // 累加权值
        max_depth = max(max_depth, depth + 1);  // 更新全局最大深度
        pq.emplace(sum, depth + 1);  // 新节点深度为子节点最大深度+1
    }

    cout << total << "\n" << max_depth << endl;
    return 0;
}
