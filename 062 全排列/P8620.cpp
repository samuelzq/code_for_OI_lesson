/**
 * https://www.luogu.com.cn/problem/P8620
 *
 * @File:   P8620.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-11
 *
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    std::string sorted_s = s;
    std::sort(sorted_s.begin(), sorted_s.end());

    long long rank = 0;

    do {
        if (s == sorted_s) {
            std::cout << rank << std::endl;
            return 0;
        }
        rank++;
    } while (std::next_permutation(sorted_s.begin(), sorted_s.end()));

    return 0;
}
