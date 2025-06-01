/**
 * https://www.luogu.com.cn/problem/P3879
 *
 * @File:   P3879.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-16
 *
 */
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, set<int>> word_map;

    // 处理每篇文章
    for (int i = 1; i <= n; ++i) {
        int l;
        cin >> l;
        for (int j = 0; j < l; ++j) {
            string word;
            cin >> word;
            word_map[word].insert(i); // 将文章编号插入到单词对应的集合中
        }
    }

    int m;
    cin >> m;

    // 处理每个查询
    for (int i = 0; i < m; ++i) {
        string word;
        cin >> word;
        auto it = word_map.find(word);

        if (it != word_map.end()) {
            bool first = true;
            for (int num : it->second) {
                if (!first) cout << " ";
                cout << num;
                first = false;
            }
            cout << "\n";
        } else {
            cout << "\n"; // 单词不存在，输出空行
        }
    }

    return 0;
}
