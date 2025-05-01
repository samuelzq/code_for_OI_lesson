/**
 *
 * @File:   size.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-25
 *
 */
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 创建string类型队列
    deque<string> languages;

    // 往队列中插入三个元素
    languages.push_back("Python");
    languages.push_back("C++");
    languages.push_back("Java");

    // 获取当前队列中元素个数
    int size = languages.size();
    cout << "Size of the deque: " << size << endl;
    cout << "Deque is " << (languages.empty() ? "empty." : "not empty.") << endl;
    return 0;
}

