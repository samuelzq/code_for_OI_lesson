#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3};
    auto it = vec.begin(); // 指向第一个元素

    vec.push_back(4); // 可能触发重新分配
    // 此时 it 可能已经失效
    std::cout << *it << std::endl; // 未定义行为

    it = vec.begin();
    std::cout << *it << std::endl;
    return 0;
}