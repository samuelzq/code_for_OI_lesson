/**
 * https://www.luogu.com.cn/problem/P1090
 *
 * @File:   P1090.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-25
 *
 */
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 使用小顶堆，priority_queue默认是大顶堆，所以要指定greater
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < n; ++i) {
        int weight;
        cin >> weight;
        min_heap.push(weight);
    }

    int total_energy = 0;

    // 当堆中不止一个元素时继续合并
    while (min_heap.size() > 1) {
        // 取出最小的两个元素
        int a, b;
		a = min_heap.top();
		min_heap.pop();
        b = min_heap.top();
		min_heap.pop();

        // 合并消耗的体力
        int sum = a + b;
        total_energy += sum;

        // 将合并后的新堆放回堆中
        min_heap.push(sum);
    }

    cout << total_energy << endl;
    return 0;
}
