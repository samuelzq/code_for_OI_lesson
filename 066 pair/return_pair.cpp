/**
 *
 * @File:   return_pair.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-02
 *
 */
#include <utility>
#include <iostream> // 为了使用 cout
#include <string>   // 为了使用 string


std::pair<int, double> process_data(int input) {
    // 一些处理逻辑
    int result_int = input * 2;
    double result_double = input / 3.0;

    return std::make_pair(result_int, result_double);
}

int main() {
    auto results = process_data(10);
    std::cout << "Integer result: " << results.first << std::endl;   // 输出: Integer result: 20
    std::cout << "Double result: " << results.second << std::endl;    // 输出: Double result: 3.33333
    return 0;
}
