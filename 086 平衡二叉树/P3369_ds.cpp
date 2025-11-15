/**
 *
 * @File:   P3369_ds.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-08-16
 *
 */
#include <iostream>
#include <utility>

// 包含GNU Policy-Based Data Structures库的头文件
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// 使用GNU命名空间
using namespace __gnu_pbds;
using namespace std;

// 定义一个树类型，它是一个红黑树，可以根据排名和键值进行查询
// <pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
// - pair<int, int>: 存储的键值对，用于处理可重集合
// - null_type: 映射值类型，这里不需要
// - less<pair<int, int>>: 比较器，使用pair的默认比较
// - rb_tree_tag: 使用红黑树作为底层实现
// - tree_order_statistics_node_update: 允许查询排名和根据排名查询值
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    // 快速IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    ordered_set m;
    int unique_id = 0;

    for (int i = 0; i < n; ++i) {
        int opt, x;
        cin >> opt >> x;

        switch (opt) {
            case 1: {
                // 操作1：插入
                // 为了处理可重集合，我们插入一个pair，
                // 其中x是值，unique_id++是唯一的索引
                m.insert({x, unique_id++});
                break;
            }
            case 2: {
                // 操作2：删除
                // 查找第一个大于等于x的元素，然后删除它
                // 由于pair的比较机制，{x, -1}可以保证找到第一个值为x的元素
                auto it = m.lower_bound({x, -1});
                if (it != m.end()) {
                    m.erase(it);
                }
                break;
            }
            case 3: {
                // 操作3：查询排名
                // order_of_key({x, -1})返回严格小于x的元素个数
                // 题目要求的是(小于x的数的个数 + 1)
                cout << m.order_of_key({x, -1}) + 1 << "\n";
                break;
            }
            case 4: {
                // 操作4：查询第x大的数
                // find_by_order(k)返回第k+1小的元素的迭代器（0-based）
                // 题目要求的是第x大的数，因此查找第x-1个元素
                cout << m.find_by_order(x - 1)->first << "\n";
                break;
            }
            case 5: {
                // 操作5：查询x的前驱
                // 前驱是小于x的最大数
                // 我们可以找到第一个小于x的元素，这个元素的排名是order_of_key({x, -1})
                // 因此前驱就是排名为(order_of_key({x, -1}) - 1)的元素
                int rank = m.order_of_key({x, -1});
                if (rank > 0) {
                    cout << m.find_by_order(rank - 1)->first << "\n";
                }
                break;
            }
            case 6: {
                // 操作6：查询x的后继
                // 后继是大于x的最小数
                // upper_bound({x, 2000000000})返回第一个大于x的元素的迭代器
                // 这里我们给unique_id一个很大的值，确保能找到所有x之后的元素
                auto it = m.upper_bound({x, 2000000000});
                if (it != m.end()) {
                    cout << it->first << "\n";
                }
                break;
            }
        }
    }

    return 0;
}
