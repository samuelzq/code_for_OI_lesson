/**
 *
 * @File:   lambda_cap2.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-04
 *
 */
#include <iostream>

int main() {
	int x = 10;
	auto lambda = [&x]() {
		x = 20; // 修改外部变量
		std::cout << "内部 x: " << x << std::endl; // 输出：20
	};
	lambda();
	std::cout << "外部 x: " << x << std::endl; // 输出：20
	return 0;
}
