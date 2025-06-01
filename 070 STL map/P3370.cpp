/**
 * https://www.luogu.com.cn/problem/P3370
 *
 * @File:   P3370.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-16
 *
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, bool> str_map;  // 也可以用 map<string, int>

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        str_map[s] = true;  // 插入到map中，自动去重
    }

    cout << str_map.size() << endl;
    return 0;
}
