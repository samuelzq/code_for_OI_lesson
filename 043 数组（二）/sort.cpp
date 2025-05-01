#include <iostream>
#include <vector>
#include <algorithm>  // std::sort

int main() {
    std::vector<int> vec = {4, 2, 5, 1, 3};

    // 使用 std::sort 排序
    std::sort(vec.begin(), vec.end());  // a[n]   sort(a, a + n)

    // 输出排序后的 vector
    for (int value : vec) {
        std::cout << value << " ";  // 输出：1 2 3 4 5
    }

    return 0;
}

