/**
 *
 * @File:   sub_length.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-16
 *
 */
#include <stdio.h>
#include <limits.h> // 用于 INT_MAX

// 找到和大于等于目标值的最短子数组的长度
int minSubarrayLength(int* nums, int numsSize, int target) {
    int left = 0;          // 滑动窗口的左边界
    int current_sum = 0;   // 当前窗口的和
    int min_length = INT_MAX; // 最小长度，初始化为最大值

    for (int right = 0; right < numsSize; right++) {
        current_sum += nums[right]; // 扩展窗口

        // 当窗口的和大于等于目标值时，尝试收缩窗口
        while (current_sum >= target) {
            // 更新最小长度
            if (right - left + 1 < min_length) {
                min_length = right - left + 1;
            }
            current_sum -= nums[left]; // 收缩窗口
            left++;
        }
    }

    // 如果找到了满足条件的子数组，返回最小长度；否则返回 0
    return (min_length != INT_MAX) ? min_length : 0;
}

int main() {
    int nums[] = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = minSubarrayLength(nums, numsSize, target);
    printf("最短子数组的长度: %d\n", result); // 输出: 2

    return 0;
}
