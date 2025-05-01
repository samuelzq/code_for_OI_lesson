#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // 使用范围 for 循环遍历
    for (int value : vec) {
        std::cout << value << " ";  // 输出：10 20 30 40 50
    }

    return 0;
}

