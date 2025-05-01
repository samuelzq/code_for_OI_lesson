/**
 *
 * @File:   sub_str.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-16
 *
 */
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_CHAR 256 // ASCII 字符集大小

// 判断窗口是否包含目标字符串的所有字符
int isValid(int window[], int target[]) {
    for (int i = 0; i < MAX_CHAR; ++i) {
        if (window[i] < target[i]) {
            return 0; // 窗口中的字符不足
        }
    }
    return 1; // 窗口满足条件
}

// 找到最小覆盖子串
void min_window_substring(char *s, char *t, char *result) {
    int target[MAX_CHAR] = {0}; // 目标字符串 T 的字符频率
    int window[MAX_CHAR] = {0}; // 当前窗口的字符频率

    int t_len = strlen(t);
    int s_len = strlen(s);

    // 初始化目标字符串的字符频率
    for (int i = 0; i < t_len; ++i) {
        target[t[i]]++;
    }

    int left = 0, right = 0; // 滑动窗口的左右指针
    int min_len = INT_MAX;   // 最小子串长度
    int start_idx = -1;      // 最小子串的起始位置

    // 开始滑动窗口
    while (right < s_len) {
        // 扩展窗口：将右指针指向的字符加入窗口
        window[s[right]]++;
        right++;

        // 收缩窗口：当窗口满足条件时，尝试收缩
        while (isValid(window, target)) {
            // 更新最小子串信息
            if (right - left < min_len) {
                min_len = right - left;
                start_idx = left;
            }

            // 收缩窗口：移除左指针指向的字符
            window[s[left]]--;
            left++;
        }
    }

    // 如果找到最小子串，将其复制到结果中
    if (start_idx != -1) {
        strncpy(result, s + start_idx, min_len);
        result[min_len] = '\0'; // 添加字符串结束符
    } else {
        result[0] = '\0'; // 如果没有找到，返回空字符串
    }
}

int main() {
    char S[] = "ADOBECODEBANC";
    char T[] = "ABC";
    char result[100]; // 存储结果

    min_window_substring(S, T, result);

    printf("最小覆盖子串: %s\n", result); // 输出: BANC

    return 0;
}
