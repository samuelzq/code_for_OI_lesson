#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 计数排序函数，支持负数
void countingSort(int arr[], int n) {
    // 找到数组中的最小值和最大值
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // 计算偏移量，使得所有值都是非负的
    int range = maxVal - minVal + 1;

    // 初始化计数数组和输出数组
    int *count = (int *)calloc(range, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    // 统计每个元素的出现次数
    for (int i = 0; i < n; i++) {
        count[arr[i] - minVal]++;
    }

    // 修改计数数组，使其包含小于等于当前索引的元素个数
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // 构建输出数组
    for (int i = n - 1; i >= 0; i--) { // 从后向前遍历以确保稳定性
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    // 将排序后的数组拷贝回原数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // 释放内存
    free(count);
    free(output);
}

// 测试函数
int main() {
    int arr[] = {92, 91, 94, 93, 92, 96, 94, 95, 93};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    // 输出排序后的数组
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}