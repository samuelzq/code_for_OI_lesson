#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 4, 5};

    // 在指定位置插入元素
    vec.insert(vec.begin() + 2, 3);  // 在索引 2 处插入 3

    // 输出插入后的 vector
    for (int value : vec) {
        std::cout << value << " ";  // 输出：1 2 3 4 5
    }

    return 0;
}

