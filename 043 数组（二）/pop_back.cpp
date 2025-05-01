#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // 删除尾部元素
    vec.pop_back();  // 删除 50

    // 输出删除后的 vector
    for (int value : vec) {
        std::cout << value << " ";  // 输出：10 20 30 40
    }

    return 0;
}

