#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = vec.begin() + 2;  // 指向 3

    it = vec.erase(it);  // 删除 3，后续元素前移

    std::cout << *it;  // ❌ 未定义行为（迭代器失效）
}
