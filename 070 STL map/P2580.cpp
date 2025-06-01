/**
 * https://www.luogu.com.cn/problem/P2580
 *
 * @File:   P2580.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-16
 *
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    map<string, int> name_map;

    // 读取所有学生姓名，初始化点名次数为0
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        name_map[name] = 0;
    }

    cin >> m;

    // 处理每次点名
    for (int i = 0; i < m; ++i) {
        string name;
        cin >> name;

        auto it = name_map.find(name);
        if (it == name_map.end()) {
            cout << "WRONG" << endl;
        } else {
            if (it->second == 0) {
                cout << "OK" << endl;
                it->second = 1;
            } else {
                cout << "REPEAT" << endl;
                it->second++;
            }
        }
    }

    return 0;
}
