/**
 *
 * @File:   lambda_cap1.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-04
 *
 */
#include <iostream>

int main() {
	int x = 10;
	auto lambda = [x]() {
		std::cout << "内部 x: " << x << std::endl; // 输出：10
		x = 20; // 错误：按值捕获的变量默认不可修改
	};
	lambda();
	std::cout << "外部 x: " << x << std::endl; // 输出：10
	return 0;
}
