#include <iostream>
#include <vector>
#include <algorithm>

void countingSortDescending(std::vector<int>& arr) {
    // 找到数组中的最大值和最小值
    int minVal = *std::min_element(arr.begin(), arr.end());
    int maxVal = *std::max_element(arr.begin(), arr.end());

    // 初始化计数数组
    std::vector<int> count(maxVal - minVal + 1, 0);

    // 统计每个元素的出现次数
    for (int num : arr) {
        count[num - minVal]++;
    }

    // 修改计数数组，使其包含小于等于当前索引的元素个数
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    // 临时数组，用于存储排序后的结果
    std::vector<int> output(arr.size());

    // 从前往后遍历输入数组，构建降序输出数组
    for (int i = 0; i < arr.size(); i++) {
        // 注意这里是从count的末尾开始减少
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    // 将输出数组拷贝回原数组
    arr = output;
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSortDescending(arr);

    // 输出排序后的数组
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}