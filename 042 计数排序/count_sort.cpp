#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int max_val = arr[0];
    int i;

    // 找到数组中的最大值
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }
    int *count = new int[max_val + 1];      // 初始化计数数组

    // 计算每个元素的频率
    for (i = 0; i < n; i++)
        count[arr[i]]++;

    // 更改计数数组，使得 count[i] 表示小于等于 i 的元素个数
    for (i = 1; i <= max_val; i++)
        count[i] += count[i - 1];

    // 创建一个临时数组用于存放排序后的结果
    int output[n];

    // 使用计数数组构建排序后的数组
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 为了实现稳定排序，逆序遍历将排序后的结果复制回原数组
    for (i = 0; i < n; i++)
        arr[i] = output[i];

	delete[] count;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    countingSort(arr, n);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
