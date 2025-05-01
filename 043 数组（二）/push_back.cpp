#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    // 使用 push_back 向 vector 添加元素
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // 输出 vector 元素
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";  // 输出：10 20 30
    }

    return 0;
}

