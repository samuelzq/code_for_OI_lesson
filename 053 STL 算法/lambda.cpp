/**
 *
 * @File:   lambda.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-04
 *
 */
#include <iostream>

int main() {
	auto hello = []() { std::cout << "Hello, Lambda!\n"; };
	hello(); // 输出: Hello, Lambda!
	return 0;
}
