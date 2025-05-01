#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40};

    // 通过索引访问元素
    std::cout << "vec[0]: " << vec[0] << std::endl;  // 输出：vec[0]: 10

    // 修改元素
    vec[1] = 25;  // 将 vec[1] 改为 25

    // 输出修改后的元素
    std::cout << "vec[1]: " << vec[1] << std::endl;  // 输出：vec[1]: 25

    return 0;
}

