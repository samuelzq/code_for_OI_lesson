#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // 使用传统 for 循环遍历
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";  // 输出：10 20 30 40 50
    }

    return 0;
}

