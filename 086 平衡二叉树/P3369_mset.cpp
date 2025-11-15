/**
 *
 * @File:   P3369_mset.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-08-16
 *
 */
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

multiset<int> ms;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        int op, x;
        cin >> op >> x;

        switch (op) {
            case 1: // 插入x
                ms.insert(x);
                break;
            case 2: // 删除x
                ms.erase(ms.find(x)); // ms.erase(x) 删除所有等于x的元素 
                break;
            case 3: // 查询x的排名
                cout << distance(ms.begin(), ms.lower_bound(x)) + 1 << '\n';
                break;
            case 4: // 查询排名为x的数
            {
                auto it = ms.begin();
                advance(it, x - 1);
                cout << *it << '\n';
                break;
            }
            case 5: // 查询x的前驱
                cout << *(--ms.lower_bound(x)) << '\n';
                break;
            case 6: // 查询x的后继
                cout << *ms.upper_bound(x) << '\n';
                break;
        }
    }

    return 0;
}
