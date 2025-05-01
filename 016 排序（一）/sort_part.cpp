#include <algorithm>
#include <iostream>

int main() {
    int arr[9] = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // 对前5个元素进行排序
    std::sort(arr + 1, arr + 6);

    // 对接下来的3个元素进行排序（注意这里的范围是紧接着上一个排序范围之后的）
    std::sort(arr + 6, arr + 8);

    // 打印排序后的数组
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}