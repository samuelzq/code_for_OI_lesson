/**
 *
 * @File:   stack.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-12-31
 *
 */
#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;

    // 入栈
    s.push(10);
    s.push(20);
    s.push(30);

    // 查看栈顶元素
    std::cout << "Top element: " << s.top() << std::endl;

    // 出栈
    s.pop();
    std::cout << "After pop, top element: " << s.top() << std::endl;

    // 获取栈的大小
    std::cout << "Stack size: " << s.size() << std::endl;

    // 判断栈是否为空
    if (s.empty()) {
        std::cout << "Stack is empty!" << std::endl;
    } else {
        std::cout << "Stack is not empty!" << std::endl;
    }

    return 0;
}

