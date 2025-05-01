#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 删除特定位置的元素
    vec.erase(vec.begin() + 2);  // 删除索引为 2 的元素（值为 3）

    // 输出删除后的 vector
    for (int value : vec) {
        std::cout << value << " ";  // 输出：1 2 4 5
    }

    return 0;
}

