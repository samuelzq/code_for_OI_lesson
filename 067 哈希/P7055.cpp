/**
 * https://www.luogu.com.cn/problem/P7055
 *
 * @File:   P7055.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-05
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// 计算 Java 中的字符串 hashCode 规则
int javaStringHashCode(const string& s) {
    int h = 0;
    for (char c : s) {
        h = 31 * h + (unsigned char)c; // 注意要unsigned，防止char负值
    }
    return h;
}

// 生成k个hashCode相同的字符串
vector<string> generateCollisions(int k) {
    string block1 = "Aa";
    string block2 = "BB";
    vector<string> result;

    int n = ceil(log2(k)); // 至少需要n块，使得2^n >= k

    for (int i = 0; (i < (1 << n)) && (result.size() < k); ++i) {
        string s;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                s += block2;
            } else {
                s += block1;
            }
        }
        result.push_back(s);
    }

    return result;
}

int main() {
    int k = 10; // 需要生成的字符串数量
	cin >> k;
    vector<string> collisions = generateCollisions(k);

    for (const string& s : collisions) {
        //cout << s << " -> hash: " << javaStringHashCode(s) << endl;
        cout << s << endl;
    }

    return 0;
}
