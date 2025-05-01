/**
 *
 * @File:   access.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-11
 *
 */
#include <iostream>
#include <list>    // 包含列表容器库

using namespace std;

int main() {

    // 创建一个字符列表
    list<char> characters = {'a', 'b', 'c', 'd', 'e'};

    // 显示第一个元素
    cout << "第一个元素: " << characters.front() << endl;

    // 显示最后一个元素
    cout << "最后一个元素: " << characters.back() << endl;

    // 创建一个指向列表开始的迭代器
    auto it = characters.begin();

    // 移动迭代器到第三个位置（注意：位置是从0开始计数的）
    std::advance(it, 2); // 现在it指向'c'

    // 访问该位置的元素
    std::cout << "第三个元素: " << *it << std::endl;

    return 0;
}
