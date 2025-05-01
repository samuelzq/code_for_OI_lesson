#include <iostream>

// 递归函数求取斐波那契数
long long int fibonacci(long long int n) {
    if (n <= 1) {
        return n; // 基本情况：0和1的斐波那契数就是它们自己
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // 递归情况：斐波那契数 = 前一个斐波那契数 + 前两个斐波那契数
    }
}

int main() {
    long long n;
    std::cout << "请输入一个整数n来求取斐波那契数F(n): ";
    std::cin >> n;

    // 检查输入是否有效（非负整数）
    if (n < 0) {
        std::cout << "输入无效，请输入一个非负整数。" << std::endl;
        return 1;
    }

    // 调用递归函数并输出结果
    std::cout << "斐波那契数F(" << n << ") = " << fibonacci(n) << std::endl;

    return 0;
}
